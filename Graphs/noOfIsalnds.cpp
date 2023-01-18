//Space Complexity : O(n^2)
//Time Complexity : O(n^2)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &vis,int row,int col,vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vis[row][col] = 1; //initial config
    queue<pair<int,int>> q;
    q.push({row,col});

    while(!q.empty()){
        int crow = q.front().first;
        int ccol = q.front().second;

        q.pop();

        //now finding neighbours of the current cell
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nrow = crow+i;
                int ncol = ccol+j;
                //learn all of these conditions, they are important
                if(nrow>=0 && nrow<m && ncol>=0 && 
                ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}

int findIslands(vector<vector<int>> &grid,int m,int n){
    //creating a replica visited 2D matrix initially all 0
    vector<vector<int>> vis(m,vector<int>(n,0));

    int cnt =0; //counter for islands/components
    //traversing the matrix to find starting node
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[m][n]==1 && !vis[m][n]){
                cnt++;
                bfs(vis,i,j,grid); //passing with row and col of starting node
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> grid{{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,1,0}};
    int m = grid.size();
    int n = grid[0].size();

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Number of islands are : "<<findIslands(grid,m,n);
    return 0;
}