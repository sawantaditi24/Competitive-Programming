//Contains all implementations of Dijkstra's shortest path algorithm

//Implementation 1: Using Adjacency Matrix representation of Graph

/* Details:

Time: O(V^2)

//Graph - V * V

//Adjacency Matrix Representation of a graph: It is a 2D array of size V * V, where V are the number of vertices
//adj[i][j] stores the weight of the edge from vertex i to vertex j
//A value of 0 means that no edge exists from i to j.

//Algorithm:
//1. We take two sets: One of which stores the vertices included so far in the shortest path tree, another with the vertices that arent included
//2. We pick a vertex with the minimum distance from the source from the second set, and add it to the first set.
//3. We end when all vertices are present in the first set.
*/
////////////////

//This function finds the vertex with the minimum distance from the set of vertices not included so far in the sptSet
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for(int v = 0 ; v < V; v++)
    {
        if(!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];    //dist[i] hols the shortest distance from src to i
    bool sptSet[V]; //sptSet[i] will be true if vertex i is included, that is,
                    //the shortest distance from src to i is finalised
                    
    
    for(int i = 0 ; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    dist[src] = 0;
    //Distance of src from itself = 0
    
    for(int count = 0 ; count < V - 1; count++)
    {
        //Pick the minimum distance vertex from the set of vertices still not considered
        int u = minDistance(dist, sptSet);
        
        //Marking that vertex as visited
        sptSet[u] = true;
        
        //Updating dist values of adj vertices
        
        for(int v = 0 ; v < V ; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}
