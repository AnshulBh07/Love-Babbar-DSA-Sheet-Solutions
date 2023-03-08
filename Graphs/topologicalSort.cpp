//Topological sort : Linear ordering is done in such a way that if there are two nodes u and v which is 
//v from u the in the ordering u always comes before v
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int>&st){
    vis[node] = 1;

    //looking for neighbours
    for(auto x : adj[node]){
        if(!vis[x])
        dfs(x,adj,vis,st);
    }

    //push in stack whenever fucntion is popping from recursive call stack
    st.push(node);
}

stack<int> topologicalSort(vector<int> adj[],int V){
    vector<int> vis(V,0);
    stack<int> st;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    return st;
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges : ";
    cin>>V>>E;

    vector<int> adj[V];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    for(int i=0;i<V;i++){
        cout<<"Adjacency list for node "<<i<<" : {";
        for(auto it : adj[i]){
            cout<<it<<",";
        }
        cout<<"}"<<endl;
    }

    stack<int> ans = topologicalSort(adj,V);
    cout<<"\nTopological sort for given graph is : {";
    
    while(!ans.empty()){
        cout<<ans.top()<<",";
        ans.pop();
    }
    cout<<"}";
    return 0;
}