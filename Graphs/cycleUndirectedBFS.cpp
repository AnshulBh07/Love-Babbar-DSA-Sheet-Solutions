//Time Complexity : O(V + 2E)
//Space complexity : O(n)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detectCycle(vector<int> adj[],vector<bool> &vis,int start){
    vis[start] = true;

    queue<pair<int,int>> q;
    q.push({start,-1}); //pushing 0th vertex with source null or -1

    while(!q.empty()){
        int node = q.front().first;
        int source = q.front().second;
        q.pop();

        //what are your neighbours?
        for(auto x : adj[node]){    
            if(!vis[x]){
                q.push({x,node});
                vis[x] = true;
            }
            else if(source != x){
                return true;
            }
        }
    }
    return false;
}

//helper function if the graph has multiple components 
bool helper(vector<int> adj[],int V){
    vector<bool> vis(V,false); //visited vector

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detectCycle(adj,vis,i)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V,E;

    cout<<"Enter vertices and edges : ";
    cin>>V>>E;

    vector<int> adj[V];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<V;i++){
        cout<<"Adjaceny list for vertex "<<i<<" is {";
        for(auto it:adj[i]){
            cout<<it<<",";
        }
        cout<<"}";
        cout<<endl;
    }

    if(helper(adj,V)){
        cout<<"Graph has a cycle!";
    }else{
        cout<<"Graph is acyclic!";
    }

    return 0;
}