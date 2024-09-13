#include "graph.h"

// Reads and sets the number of vertices for the graph, handling invalid input if the number is negative
void Graph::SetNumOfVertices()
{
    int num;
    std::cin >> num;
    if(num <0)
    {
        throw std::invalid_argument("Invalid input");
    }
    else
        numOfVertices=num;
}

// Reads and sets the number of edges for the graph, handling invalid input if the number is negative
void Graph::SetNumOfEdges()
{
    int num;
    std::cin >> num;
    if(num < 0)
    {
        throw std::invalid_argument("Invalid input");
    }
    else
        numOfEdges=num;
}

// Returns the number of edges in the graph
int Graph::GetNumOfEdges() const
{
    return numOfEdges;
}

// Returns the number of vertices in the graph
int Graph::GetNumOfVertices() const
{
    return numOfVertices;
}

// Returns the list of vertices visited at the end of DFS traversal
std::list<int> Graph::GetEndList()
{
    return endList;
}

// Returns the adjacency list representation of the graph
std::vector<std::list<int>> Graph::GetAdjList() const
{
    return adjList;
}

// Initializes the graph with empty adjacency lists, color markers, and end list
void Graph::MakeEmptyGraph()
{
    adjList.resize(numOfVertices);
    color.resize(numOfVertices, 'W');
    root.resize(numOfVertices);
    endList.clear();

    for(int i=0 ; i < numOfVertices ; i++)
    {
        adjList[i].clear();
    }
}

// Checks if there is an edge between two vertices
bool Graph::IsAdjacent(int u,int v)
{
    for (auto& vertex : adjList[u])
    {
        if (vertex == v)
            return true;
    }
    return false;
}

// Returns the adjacency list of a specific vertex
std::list<int> Graph::GetAdjList(int u)
{
    return adjList[u];
}

// Adds a directed edge between two vertices, checking for valid input
void Graph::AddEdge(int u,int v)
{
    CheckIfValidEdge(u,v);
    adjList[u-1].push_back(v-1);
}

// Removes an edge between two vertices
void Graph::RemoveEdge(int u,int v)
{
    adjList[u].remove(v);
}

// Checks if an edge is valid between two vertices
void Graph::CheckIfValidEdge(int u, int v)
{
    if(u > numOfVertices || v > numOfVertices || v == u || u <= 0 || v <= 0)
    {
        throw std::invalid_argument("Invalid input");
    }
}

// Reads edge information from the user and adds edges to the graph
void Graph::GetEdgesFromUser()
{
    int u,v;
    for(int i=1 ; i<=numOfEdges ; i++)
    {
        std::cin >> u >> v;
        AddEdge(u,v);
    }
}

// Constructs a directed graph by setting vertices, edges, and building the graph
void Graph::BuildDirectedGraph()
{
    SetNumOfVertices();
    SetNumOfEdges();
    MakeEmptyGraph();
    GetEdgesFromUser();
}

// Performs a depth-first search (DFS) visit from a vertex, marking visited vertices and adding them to the end list
void Graph::Visit(int u, int currRoot)
{
    root[u]=currRoot;
    color[u]='G';
    for (int vertex: adjList[u])
    {
        if(color[vertex] == 'W')
            Visit(vertex, currRoot);
    }
    color[u]='B';
    endList.push_back(u);
}

// Performs a depth-first search (DFS) traversal of the graph, starting from unvisited vertices
void Graph::DFS()
{
    int i, currentRoot;

    for (i = 0; i < numOfVertices; i++) {
        if (color[i] == 'W') {
            currentRoot = i;
            Visit(i, currentRoot);
        }
    }
}
