#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> printBFS(int V,vector<int> adj[]){
    vector<int> bfs; //maintains the bfs traversal
    vector<bool> vis(V,false); //vector of size V with all false to keep track of visited nodes

    queue<int> q;
    vis[0] = true;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        //exploring adjacency list of the node, if a new node encountered push in queue
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    //creating a graph
    int V,E;
    cin>>V>>E;

    vector<int> adj[V]; //in case of a 0 indexed graph size of array is V

    for(int i=0;i<E;i++){
        //taking the vectices/nodes for each edge
        int u,v;
        cin>>u>>v;

        //creating an edge
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    vector<int> ans = printBFS(V,adj);

    for(auto x:ans)
    cout<<x<<" ";

    return 0;
}