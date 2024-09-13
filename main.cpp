#include "graph.h"
#include "transposedGraph.h"
#include "superGraph.h"

int main() {
    try {
        Graph g;
        g.BuildDirectedGraph();
        TransposedGraph gTransposed(g);
        SuperGraph superG;
        superG.Sarir_Kosaraju_Algorithm(g);
        superG.PrintSuperGraph();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
