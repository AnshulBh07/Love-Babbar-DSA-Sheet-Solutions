//for simplicity sake we will take an undirected graph
//There are two major representations 
//1. Adjacency matrix - here all operations are performed in O(n^2) where n is the number of vertices
//2. Adjacency list - making an array where each element represents the list of connected edges and 
//the index represnets the vertex (1-indexed preferred). It can be implemented using maps and vector arrays. 
//Time complexity is O(|V|+|E|) if V and E are same then = O(n+n) = O(n)
#include<iostream>
#include<vector>
using namespace std;

//adjacency list representation
vector<int>* makeList(int n,int m){
    //this below is not a vector but an array of vectors. It is an array of fixed size n+1 which contains 
    //vector<int> type as values on each index. This is different from vector<vector<int>>.Visualise it
    //the same way as a hash table
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //u ---> v
        adj[u].push_back(v);
        //do below in case of undirected graph only
        //v ---> u
        adj[v].push_back(u);
    }

    /*Note: Whenever a weighted graph is given make pair of vertex and weight then insert in array
    like vector<pair<int,int>> adj[n+1]
    SPACE COMPLEXITY :  O(2E) and for directed graph it will be O(E)(as nodes connect in one direction only)
    * In case of a weighted graph when a matrix is given instead of pushing 1, push the weight in matrix*/

   for(int i=0;i<n+1;i++){
        cout<<"Adjacency list of vertex "<<i<<"\n head -> ";
        for(auto x:adj[i]){
            cout<<"-> "<<x;
        }
        cout<<endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m; //number of vertices and edges

    makeList(n,m);

    //initialise the adjacency matrix
    int graph[n+1][n+1];
    //initialise all as 0 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }

    //take edges as input
    for(int i=0;i<m;i++){
        int u,v; //pair of vertices

        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    return 0;
}