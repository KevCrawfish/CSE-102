//-----------------------------------------------------------------------------
// Kevin M Crawford, kemcrawf, programming assignment
// Graph.cpp
// Implementation file for Graph ADT.
//-----------------------------------------------------------------------------
#include "Graph.h"

Graph::~Graph(){
  free(parent);
  free(rank);
}

void Graph::makeSet(int x){
  parent[x] = x;
  rank[x] = 0;
}

void Graph::unions(int x, int y){
  link(findSet(x), findSet(y));
}

void Graph::link(int x, int y){
  if(rank[x] > rank[y]){
    parent[y] = x;
  } else {
    parent[x] = y;
    if(rank[x] == rank[y]){
      rank[y] = rank[y] + 1;
    }
  }
}

int Graph::findSet(int x){
  if(x != parent[x]){
    parent[x] = findSet(parent[x]);
  }
  return parent[x];
}

void Graph::addEdge(int u, int v, int w, int e) {
  G.push_back(std::make_tuple(w, u, v, e));
}

void Graph::mstKruskal(int edges, int vertices){
  for(int i = 0; i < vertices; i++){
    makeSet(i);
  }

  std::sort(G.begin(), G.end());

  for(int i = 0; i < edges; i++){
    int u = std::get<1>(G[i]);
    int v = std::get<2>(G[i]);
    if(findSet(u) != findSet(v)){
      M.push_back(G[i]);
      unions(u, v);
    }
  }

  float t = 0;
  for(int i = 0; i < vertices - 1; i++){
    float w = std::get<0>(M[i]);
    int u = std::get<1>(M[i]);
    int v = std::get<2>(M[i]);
    int e = std::get<3>(M[i]);
    std::cout << std::setw(4) << e;
    std::cout << ": (" << u << ", " << v << ") " << std::fixed << std::setprecision(1) << w << std::endl;
    t += w;
  }
  std::cout << "Total Weight = " << std::fixed << std::setprecision(2) << t << std::endl;
}
