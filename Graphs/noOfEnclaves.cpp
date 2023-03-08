//same as replace O with X but let's do this one with bfs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int numberOfEnclaves(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));
    queue<pair<int,int>> q;

    //we will traverse only boundaries and look for connected land cells (1) on the borders
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==m-1 || j==0 || j==n-1){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
    }

    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,1,0,-1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traversing 4 directions for neighbours 
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m &&ncol>=0 && ncol<n
            && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }

    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>> grid{{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};

    cout<<numberOfEnclaves(grid);
    return 0;
}