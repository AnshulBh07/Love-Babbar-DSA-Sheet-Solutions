#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
bool compare(pair<int,int> a,pair<int,int> b){
    //compare distance first
    if(a.first != b.first)
    return a.first < b.first;

    //comapre second only if first are not equal
    return a.second < b.second;
}*/

//dijkstra's algo for shortest path
//it is for single source shortest path
vector<int> disjkstra(int S,vector<pair<int,int>> adj[],int V){

    vector<int> distance(V,0); //distance vector

    //this is a min heap data structure storing a pair 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    //initialing distance vector with infinite (very big integer)
    for(int i=0;i<V;i++){
        distance[i] = INT64_MAX;
    }

    distance[S] = 0;

    //push starting node with distance 0 (to itself)
    pq.push({S,0});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto x : adj[node]){
            int edgeWt = x.second;
            int adjNode = x.first;

            if(dis + edgeWt < distance[adjNode]){
                distance[adjNode] = dis + edgeWt;
                pq.push({distance[adjNode],adjNode});
            }
        }
    }
    return distance;
}

int main(){
    int V,E;
    cout<<"Enter the vertices and edges : ";
    cin>>V>>E;

    vector<pair<int,int>> adj[V];

    cout<<"Enter edges with their weights : "<<endl;;

    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});

    }

    for(int i=0;i<V;i++){
        cout<<"Adjacency list for "<<i<<" is : {";
        for(auto it : adj[i]){
            cout<<"{"<<it.first<<","<<it.second<<"},";
        }
        cout<<"}"<<endl;
    }
    
    int S,D; //start and destination node
    cout<<"\n\nEnter start and destination vertex : ";
    cin>>S>>D;
    return 0;
}