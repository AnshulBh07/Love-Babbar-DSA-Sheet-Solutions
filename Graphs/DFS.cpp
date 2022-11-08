#include<iostream>
#include<vector>
using namespace std;

//Time Complexity : O(n) + (V + 2E) for undirected and O(n)+(E)
//Space complexity : O(n)
void doDFS(int node, vector<int>&dfs, vector<int> adj[],vector<bool>&vis){
    //always do this step
    vis[node] = true;
    dfs.push_back(node);

    //traversing all the neighbours
    for(auto it:adj[node]){
        if(!vis[it]){
            doDFS(node,dfs,adj,vis);
        }
    }
}   

vector<int> printDFS(int V, vector<int> adj[]){
    vector<bool> vis(V+1,false); //1 indexed array
    int start=1;
    vector<int> dfs;

    doDFS(start,dfs,adj,vis);

    for(auto x:dfs)
    cout<<x<<" ";
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<int> adj[V+1]; //adjacency list for 1 indexed graph

    for(int i=1;i<=E;i++){
        int u,v;
        cin>>u>>v;

        //we make undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printDFS(V,adj);

    return 0;
}