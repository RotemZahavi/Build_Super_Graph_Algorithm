#include "superGraph.h"

// Performs Kosaraju's algorithm to find strongly connected components in a graph.
void SuperGraph::Sarir_Kosaraju_Algorithm(Graph origin)
{
    origin.DFS();
    TransposedGraph gTransposed(origin);
    gTransposed.SetEndList(origin.GetEndList());
    gTransposed.DFS();
    BuildSuperGraph(gTransposed.GetDFSGraph());
}

// Builds a supergraph from a given map representing a directed graph.
void SuperGraph::BuildSuperGraph(std::map<int,std::list<int>> origin)
{
    numOfVertices = origin.size();
    MakeEmptyGraph();
    numOfEdges=0;

    std::unordered_map<int, int> originalToNew;

    int newVertexName=1;
    for (const auto& pair : origin) {
        originalToNew[pair.first] = newVertexName;
        newVertexName++;
    }

    for (const auto& pair : origin) {
        int newFrom = originalToNew[pair.first];
        for (int value : pair.second) {
            int newTo = originalToNew[value];
            AddEdge(newTo, newFrom);
            numOfEdges++;
        }
    }
}

// Prints the number of vertices and edges in the supergraph.
void SuperGraph::PrintSuperGraph()
{
    std::cout<< numOfVertices << ' ' << numOfEdges;
}
