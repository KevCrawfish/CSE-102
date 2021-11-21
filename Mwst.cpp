//-----------------------------------------------------------------------------
// Kevin M Crawford, kemcrawf, programming assignment
// Mwst.cpp
//-----------------------------------------------------------------------------
#include "Graph.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){

  if(argc != 3){
  std::cout << "Usage: <input file> <output file>" << std::endl;
  exit(1);
  }

  std::ifstream infile (argv[1]);
  std::ofstream outfile (argv[2]);
  int vertices;
  int edges;
  int u;
  int v;
  int w;

  infile >> vertices;
  Graph g(vertices);
  infile >> edges;

  int e = 1;
  while(infile >> u >> v >> w){
    g.addEdge(u, v, w, e);
    e++;
  }

  std::cout.rdbuf(outfile.rdbuf());
  g.mstKruskal(edges, vertices);

  infile.close();
  outfile.close();

  return 0;
}
