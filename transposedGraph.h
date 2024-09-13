#ifndef TRANSPOSEDGRAPH_H
#define TRANSPOSEDGRAPH_H
#include "graph.h"

class TransposedGraph : public Graph{
    std::list<int> vertexOrder;
    std::map<int,std::list<int>> dfsGraph;

public:
    TransposedGraph(const Graph& g);
    void DFS();
    void SetEndList(std::list<int> list);
    void Visit(int u, int currRoot);
    std::map<int,std::list<int>> GetDFSGraph();
};


#endif
