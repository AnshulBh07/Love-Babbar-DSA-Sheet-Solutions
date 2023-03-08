//In this two visited arrays are maintained, one is normal visited and the other is path visited
#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&pathvis){
    vis[node] = 1;
    pathvis[node] = 1;

    //what are your neighbours?
    for(auto x : adj[node]){
        if(!vis[x]){
            if(dfs(x,adj,vis,pathvis))
            return true;
        }
        //if the node has been previously visited but it has to be
        //visited again
        else if(pathvis[x]){
            return true;
        }
    }

    //if the function returns recursively then make pathvis 0
    pathvis[node] = 0;
    return false;
}

bool isCyclic(vector<int> adj[],int V){
    vector<int> vis(V+1,0);
    vector<int> pathvis(V+1,0);

    //performing dfs for various components 
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis))
            return true;
        }
    }
    return false;
}

int main(){
    int V,E;
    cout<<"Enter vertices and edges : ";
    cin>>V>>E;

    vector<int> adj[V+1];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    for(int i=1;i<=V;i++){
        cout<<"Adjacency list for "<<i<<" is : {";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<"}"<<endl;
    }

    if(isCyclic(adj,V)){
        cout<<"Graph is cyclic!";
    }
    else{
        cout<<"Graph is acyclic!";
    }
    return 0;
}