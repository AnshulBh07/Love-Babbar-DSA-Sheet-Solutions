//Space Complexity : O(3N) ~~ O(N)
//Time Complexity - There is a queue which runs once for each node and then there's a for loop inside
//while which runs for the given node to get all the degrees (neighbours) therefore time complexity
//will be Time for queue traversal + Time taken for total number of degrees traversal{O(2E)}
//i.e. Time Complecity = O(N or V) + O(2E) simplifying it more we get O(V) + O(E)
//if V=E the it is O(E) or O(V)  
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(int V,int E,vector<int> adj[]){
    queue<int> q;
    int visited[V]{0};

    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<"->";

        //what are your neighbour node?
        for(auto x :adj[node]){
            if(visited[x]!=1){
                q.push(x);
                visited[x]=1;
            }
        }
    }
}

int main(){
    int V,E; //number of vertices and edges
    cin>>V>>E;

    vector<int> adj[V]; //used as a hashmap to store the ajdaceny list/vector for each vertex(index)
    //size V for 0 indexed and V+1 for 1 indexed 

    for(int i=0;i<E;i++){
        int u,v; //start and end vertex for an edge 
        cin>>v>>u;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<V;i++){
        cout<<"Adjacency list of vertex "<<i<<" is : {";
        for(auto it:adj[i]){
            cout<<it<<",";
        }
        cout<<"}";
        cout<<endl;
    }

    BFS(V,E,adj);
    return 0;
}