#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<bool>&vis,vector<int> adj[]){
    vis[node] = true;
    //traversing neighbours
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}

int NoOfProvinces(int V,vector<int> adj[]){
    vector<bool> vis(V+1,false);
    int count=0;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            count++;
            dfs(i,vis,adj);
        }
    }
    return count;
}

int main(){
    int V;
    cin>>V;

    vector<int> adj[V+1];
    for(int i=1;i<=V;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*1 1 0
      1 1 0
      0 0 1*/

    cout<<NoOfProvinces(V,adj);
    return 0;
}