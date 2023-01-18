#include<iostream>
#include<vector>
using namespace std;

//function for dfs traversal
void doDFS(int node, vector<int> adj[],vector<int>&visited){
    //this has to be done always
    visited[node] = 1;
    cout<<node<<"->";

    //what are your neighbours?
    for(auto x:adj[node]){
        if(visited[x]!=1)
            doDFS(x,adj,visited);
    }
}

//functon for initial configuration
void initDFS(int V,int E, vector<int> adj[]){
    vector<int> visited(V+1,0);
    visited[1] = 1;

    doDFS(1,adj,visited);
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<int> adj[V+1]; //1 based indexing

    for(int i=0;i<E;i++){
        int u,v; //starting and ending vertex of edge 
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=V;i++){
        cout<<"Adjacency list of vertex "<<i<<" is : {";
        for(auto it:adj[i]){
            cout<<it<<",";
        }
        cout<<"}";
        cout<<endl;
    }

    initDFS(V,E,adj);
    return 0;
}