#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<int> adj[],int V,vector<int>&color,int start){
    
    color[start] = 0;
    queue<int> q;
    q.push(1); //our starting node is 1

    while(!q.empty()){
        int node = q.front();
        q.pop();

        //looking for neighbours in adjacency list
        for(auto x:adj[node]){
            if(color[x]==-1){
                color[x]=!color[node];
                q.push(x);
            }
            else if(color[x] == color[node]){
                return false;
            }
        }
    }
    return true;
}

//helper function for multiple components 
bool helper(vector<int> adj[],int V){
    //this vector will serve as a visited vector 
    vector<int> color(V,-1);

    for(int i=1;i<=V;i++){
        if(color[i]==-1){
            if(isBipartite(adj,V,color,i))
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
        adj[v].push_back(u);
    }

    for(int i=1;i<=V;i++){
        cout<<"Adjacency list for "<<i<<" is : {";
        for(auto it : adj[i]){
            cout<<it<<",";
        }
        cout<<"}";
        cout<<endl;
    }

    if(helper(adj,V)){
        cout<<"Graph is bipartite!";
    }
    else{
        cout<<"Graph is not bipartite!";
    }

    return 0;
}