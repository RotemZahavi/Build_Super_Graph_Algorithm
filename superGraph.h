#ifndef SUPERGRAPH_H
#define SUPERGRAPH_H
#include "transposedGraph.h"
#include "graph.h"
#include <unordered_map>

class SuperGraph : public Graph{
    std::list<std::list<int>> superGAdjList;

public:
    void Sarir_Kosaraju_Algorithm(Graph origin);
    void BuildSuperGraph(std::map<int,std::list<int>> origin);
    void PrintSuperGraph();
};

#endif
