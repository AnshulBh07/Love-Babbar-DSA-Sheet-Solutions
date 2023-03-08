//In this two visited arrays are maintained, one is normal visited and the other is path visited
//This can be done in BFS using topo sort.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&pathvis,vector<int>&check){
    vis[node] = 1;
    pathvis[node] = 1;
    check[node] = 0;

    //what are your neighbours?
    for(auto x : adj[node]){
        if(!vis[x]){
            if(dfs(x,adj,vis,pathvis,check))
            return true;
        }
        //if the node has been previously visited but it has to be
        //visited again
        else if(pathvis[x]){
            return true;
        }
    }

    //if the function returns recursively then make pathvis 0 and check to 1
    //1 on check means a safe node
    check[node] = 1;
    pathvis[node] = 0;
    return false;
}

vector<int> safeNodes(vector<int> adj[],int V){
    vector<int> vis(V+1,0);
    vector<int> pathvis(V+1,0);
    vector<int> check(V+1,0);
    vector<int> ans;

    //performing dfs for various components 
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,pathvis,check);
        }
    }

    for(int i=1;i<=V;i++){
        if(check[i]==1)
        ans.push_back(i);
    }

    sort(ans.begin(),ans.end());
    return ans;
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

    vector<int> ans = safeNodes(adj,V);
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}