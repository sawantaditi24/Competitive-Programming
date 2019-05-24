#include<bits/stdc++.h>
using namespace std;

//Implementation of Graphs
//////////////////

class Graph
{
    int V;//No of vertices
    
    list<int> *adj;//Same as list<int> adj[], which is an array with every element a list
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
        void print(int V);
        void DFSutil(int v, bool visited[]);
        void DFS(int v);
};

Graph:: Graph(int V)
{
    this->V = V; //No of vertices
    adj = new list<int>[V];//list of size n, each element representing the node of a Graph
}

//Adding edge in Adj list
void Graph:: addEdge(int v, int w)
{
    //We have to add an edge between v and W
    adj[v].push_back(w);
    //If there is an edge from v to w, w will be in the adj list of v 
}

//Printing the Adj lists
void Graph::print(int V)
{
    for(auto v = 0; v < V; v++)
    {
        cout<<"Adj list of "<<v<<"\n head";
        for(auto x: adj[v])
            cout<<"->"<<x;
        cout<<endl;
    }
}


void Graph:: BFS(int s)
{
    //Since Graph does not have a root node, unlike a tree, we need to specify the node from where 
    //we have to start the BFS
    bool *visited = new bool[V];//visited is an array of booleans
    //will have a[i] = true if ith vertex has been visited, false otherwise
    for(int i = 0 ; i < V ; i++)
        visited[i] = false;//Initially setting all vertices as not visited
        
    queue<int> q;
    
    visited[s] = true;
    //Start by visiting the source node
    q.push(s);
    
    while(!q.empty())
    {
        s = q.front();
        cout<<s<<" ";
        q.pop();
        //Checking all vertices in adj of s, enqueing those not visited
        for(auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
                if(!visited[*i])
                {
                        visited[*i] = true;
                        q.push(*i);
                }
        }
        
    }
    
}

void Graph::DFSutil(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    for(auto i = adj[v].begin(); i!=adj[v].end(); ++i)
    {
        if(!visited[*i])
            DFSutil(*i, visited);
    }
}

void Graph:: DFS(int v)
{
    bool *visited = new bool[V];
    for(int i = 0 ; i < v;++i)
        visited[i] = false;
        
     for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
    //If we called only DFS(int v), it would only traverse nodes reachable from v
    //This for loop makes sure that 
}
//Main Method
int main()
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout<<"BFS: ";
    g.BFS(2);
    cout<<"DFS: ";
    g.DFS(2);
  
    return 0;
}
