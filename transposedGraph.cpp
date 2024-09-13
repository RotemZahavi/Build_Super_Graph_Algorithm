#include "transposedGraph.h"

// Constructs a transposed graph from a given graph by reversing the edges.
TransposedGraph::TransposedGraph(const Graph& g)
{
    numOfVertices=g.GetNumOfVertices();
    numOfEdges=g.GetNumOfEdges();
    MakeEmptyGraph();
    std::vector<std::list<int>> adjListOriginGraph = g.GetAdjList();
    for(int i=0 ; i<numOfVertices ; i++)
        for(int vertex: adjListOriginGraph[i])
            AddEdge(vertex+1, i+1);
}

// Performs Depth-First Search (DFS) traversal on the transposed graph to identify strongly connected components.
void TransposedGraph::DFS()
{
    int currRoot;

    for(int v : endList)
        color[v]='W';

    for(int v : endList)
    {
        if(color[v] == 'W')
        {
            currRoot = v;
            dfsGraph.insert({currRoot, std::list<int>()});
            Visit(v, currRoot);
        }
    }
}

// Visits a vertex during DFS traversal and updates information about its root and color.
void TransposedGraph::Visit(int u, int currRoot)
{
    root[u]=currRoot;
    color[u]='G';

    for (int vertex: adjList[u])
    {
        if(color[vertex] == 'W')
            Visit(vertex, currRoot);
        else if(color[vertex] == 'B' && (currRoot != root[vertex]))
        {
            if( dfsGraph[currRoot].front() != root[vertex] || dfsGraph[currRoot].empty())
                dfsGraph[currRoot].push_front(root[vertex]);
        }
    }
    color[u]='B';
}

// Sets the list of vertices in reverse topological order.
void TransposedGraph::SetEndList(std::list<int>  list)
{
    endList = list;
    endList.reverse();
}

// Returns the directed graph obtained from DFS traversal.
std::map<int,std::list<int>> TransposedGraph::GetDFSGraph()
{
    return dfsGraph;
}
