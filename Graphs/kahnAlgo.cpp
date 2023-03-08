//this is just topological sort using BFS (a slightly modified approach)
//Here we use a queue and not a stack, moreover we use an Indegree vector instead of visited vector
//Indegree means the number of incoming edges 
//It is only applicable on DAG (directed Acyclic Graph)
/*ALGORITHM:
    1. Insert all nodes into the queue with indegree 0.
    2. take the elements out of the queue and reduce the indegree value in vector for its
       adjacent nodes.
*Note:- to find indegree for each node traverse the adjacency list for all nodes and keep incrementing
the value in indegree vector with index as the adjacent node.

This algorithm can also be used for detection of cycle in a Directed graph
Do the kahn's algo and then at last compare the size of topoSort vector to V
if(topoSort.size()!=V) return true 
i.e. graph is cyclic and topoSort is not done*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kahnAlgorithm(vector<int> adj[],int V){
    vector<int> indegree(V,0); //replaces the task of visited array

    //populating indegree vector
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    vector<int> topoSort;

    //only vertices with indegree 0 will enter the queue and thereafter in toposort vector
    for(int i=0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);

        //explore it's neighbours and reduce indegree of adjacent nodes by 1 
        for(auto x : adj[node]){
            indegree[x]--;

            if(indegree[x]==0)
            q.push(x);
        }
    }
    return topoSort;
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
    }

    for(int i=0;i<V;i++){
        cout<<"Adjacency list for node "<<i<<" : {";
        for(auto it : adj[i]){
            cout<<it<<",";
        }
        cout<<"}"<<endl;
    }

    vector<int> ans = kahnAlgorithm(adj,V);
    cout<<"Toposort is : ";
    for(auto it:ans){
        cout<<it<<",";
    }
    return 0;
}