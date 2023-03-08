#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col,int &count){
    vis[row][col] = 1;
    int m = grid.size();
    int n = grid[0].size();

    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,1,0,-1};

    //traversing in all 4 directions to look for connected land 
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
        !vis[nrow][ncol] && grid[nrow][ncol]==1){
            count++;
            vis[nrow][ncol] = 1;
            dfs(grid,vis,nrow,ncol,count);
        }
    }
}

int maxAreaOfIsland(vector<vector<int>>&grid,int m,int n){
    vector<vector<int>> vis(m,vector<int>(n,0));

    int maxArea = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                int count=1;
                dfs(grid,vis,i,j,count);
                maxArea = max(maxArea,count);
            }
        }
    }
    return maxArea;
}

int main(){
    vector<vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int m = grid.size();
    int n = grid[0].size();

    cout<<"Problem matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Maximum area is : "<<maxAreaOfIsland(grid,m,n);
    return 0;
}