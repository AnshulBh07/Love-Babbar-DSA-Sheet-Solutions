#include<iostream>
#include<vector>
using namespace std;

//function for dfs traversal
void dfs(int row,int col,vector<vector<int>>&maze,vector<vector<int>>&vis,vector<vector<int>>&pathvis){
    int m = maze.size();
    int n = maze[0].size();

    vis[row][col] = 1;
    pathvis[row][col] = 1;

    vector<int> delrow{0,-1,0,1};
    vector<int> delcol{-1,0,1,0};

    //check for it's neighbours
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow>=0 && nrow<m && ncol>=0 &&ncol<n && 
        !vis[nrow][ncol] && maze[nrow][ncol]==1){
            dfs(nrow,ncol,maze,vis,pathvis);
        }
    }

    //if the function is popping out of recursive call stack
    pathvis[row][col] = 0;
}

string findPath(vector<vector<int>>&maze){
    int m = maze.size();
    int n = maze[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0)); //visited vector
    vector<vector<int>> pathvis(m,vector<int>(n,0)); //path visited vector for backtracking

    //start dfs from initial coordinates i.e {0,0}
    //we will do only one dfs traversal as the grpah should not have any components to reach 
    //destination
    dfs(0,0,maze,vis,pathvis);

    cout<<"\n\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<pathvis[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    //a 0 in maze represents wall and a 1 in maze represents path
    vector<vector<int>> maze{{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int m = maze.size();
    int n = maze[0].size();

    cout<<"The maze is : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }

    string ans = findPath(maze);
    return 0;
}