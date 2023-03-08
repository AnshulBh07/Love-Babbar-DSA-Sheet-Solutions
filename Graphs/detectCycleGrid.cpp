#include<iostream>
#include<vector>
using namespace std;

bool doDFS(int row,int col,int prow,int pcol,vector<vector<char>>&grid ,vector<vector<int>>&vis){

    int m = grid.size();
    int n = grid[0].size();

    vis[row][col] = 1;

    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,1,0,-1};

    //looking for the neighbours of current element/node
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow==prow && ncol==pcol)
        continue;

        if(nrow < m && nrow >=0 && ncol < n && ncol>=0
        && grid[nrow][ncol] == grid[row][col]){

            if(vis[nrow][ncol])
            return true;

            else
            doDFS(nrow,ncol,row,col,grid,vis);
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    //visited array
    vector<vector<int>> vis(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                if(doDFS(i,j,-1,-1,grid,vis))
                return true;
            }
        }
    }

    return false;
}

int main(){
    vector<vector<char>> grid{{'o','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    for(vector<char> v : grid){
        for(char ch : v){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<containsCycle(grid);
    return 0;
}