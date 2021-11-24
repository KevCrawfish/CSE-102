//-----------------------------------------------------------------------------
// Kevin M Crawford, kemcrawf, programming assignment
// Graph.h
// Header file for Graph ADT
// Graph.h and Graph.cpp were implemented with assistance from https://www.programiz.com/dsa/kruskal-algorithm
// Functions in Graph.cpp were implemented with assistance from Introduction to Algorithms (3rd edition) by Cormen, Leiserson, Rivest and Stein
//    pages 571 and 631 
//-----------------------------------------------------------------------------
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>

#ifndef Graph_H_INCLUDE_
#define Graph_H_INCLUDE_

class Graph{

private:
  std::vector<std::tuple <double, int, int, int>> G;
  std::vector<std::tuple <double, int, int, int>> M;

  int *parent;
  int *rank;

public:
  Graph(int n){
    parent = (int *)calloc(n + 1, sizeof(int));
    rank = (int *)calloc(n + 1, sizeof(int));
  }
  ~Graph();
  int findSet(int x);
  void makeSet(int x);
  void addEdge(int u, int v, double w, int e);
  void unions(int x, int y);
  void link(int x, int y);
  void mstKruskal(int edges, int vertices);
};


#endif
