#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <map>

class Graph{
protected:
    int numOfVertices;
    int numOfEdges;
    std::vector<std::list<int>> adjList;
    std::vector<char> color;
    std::vector<int> root;
    std::list<int> endList;

public:
    void SetNumOfVertices();
    void SetNumOfEdges();
    int GetNumOfVertices() const;
    int GetNumOfEdges() const;
    std::list<int> GetEndList();
    std::vector<std::list<int>> GetAdjList() const;
    void CheckIfValidEdge(int u, int v);
    void BuildDirectedGraph();
    void GetEdgesFromUser();
    virtual void Visit(int u, int currRoot);
    virtual void DFS();
    void MakeEmptyGraph();
    bool IsAdjacent(int u,int v);
    std::list<int> GetAdjList(int u);
    void AddEdge(int u,int v);
    void RemoveEdge(int u,int v);
};

#endif
