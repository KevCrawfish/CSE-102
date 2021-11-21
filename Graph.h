//-----------------------------------------------------------------------------
// Kevin M Crawford, kemcrawf, programming assignment
// Graph.h
// Header file for Graph ADT
//-----------------------------------------------------------------------------
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>

#ifndef Graph_H_INCLUDE_
#define Graph_H_INCLUDE_

// Exported type --------------------------------------------------------------
class Graph{

private:
  std::vector<std::tuple <int, int, int, int>> G;
  std::vector<std::tuple <int, int, int, int>> M;

  int *parent;
  int *rank;
  int vertices;

public:
  Graph(int n){
    vertices = n;
    parent = new int[n];
    rank = new int[n];
  }
  int findSet(int x);
  void makeSet(int x);
  void addEdge(int u, int v, int w, int e);
  void unions(int x, int y);
  void link(int x, int y);
  void mstKruskal(int edges, int vertices);
};


#endif
