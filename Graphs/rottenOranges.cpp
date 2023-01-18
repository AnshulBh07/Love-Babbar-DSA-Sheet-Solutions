//only BFS is to be used as rotten oranges can rotten only neighbouring oranges
//a neighbour can be seen as same level
//take a third variable to store time with the pair in queue
//time complexity O(n * m)
//Space Complexity O(n * m)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rotOranges(vector<vector<int>> &oranges){
    int m = oranges.size();
    int n = oranges[0].size();
    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,-1,0,1};
    vector<vector<int>> vis(m,vector<int>(n,0));

    queue<pair<pair<int,int>,int>> q; //((row,col),time)

    //populating the queue and visited matrix with rotten oranges first
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(oranges[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }

    int time=0;
    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ct = q.front().second;
        q.pop();
        
        //updating max time
        time = max(time,ct);

        //checking for neighbours
        for(int i=0;i<4;i++){
            int newr = cr+delrow[i];
            int newc = cc+delcol[i];

            if(newr>=0 && newr<m && newc>=0 && newc<n && 
            vis[newr][newr]!=2 && oranges[newr][newc]==1){
                vis[newr][newc]=2;
                q.push({{newr,newc},ct+1});
            }
        }
    }
    return time;
}

int main(){
    vector<vector<int>> oranges{{2,1,0,2,1},{1,0,1,2,1},{1,0,0,2,1}};
    cout<<rotOranges(oranges);
    return 0;
}