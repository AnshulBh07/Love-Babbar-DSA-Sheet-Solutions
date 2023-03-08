//can only be solved using bfs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));
    vector<vector<int>> dis(m,vector<int>(n,0));
    //for 4 directional traversal
    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,1,0,-1};

    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int nearestOne = q.front().second;
        q.pop();

        //looking for neighbours in 4 directions
        for(int i=0;i<4;i++){
            int newr = row + delrow[i];
            int newcol = col + delcol[i];

            if(newr>=0 && newr<m && newcol>=0 && newcol<n && 
            !vis[newr][newcol] && grid[newr][newcol]==0){
                vis[newr][newcol] = 1;
                dis[newr][newcol] = nearestOne+1;
                q.push({{newr,newcol},nearestOne+1});
            }
        }
    }
    return dis;
}

int main(){
    vector<vector<int>> grid{{1,0,1},{1,1,0},{1,0,0}};
    vector<vector<int>> ans = nearest(grid);   
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}