//This can be done using dfs where we will traverse the border of our matrix and mark all the O and
//other connected O with the border O as 1 on our vis matrix, then replace everything else with X
#include<iostream>
#include<vector>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>&mat,vector<int>&delrow,vector<int>&delcol){
    vis[row][col] = 1;
    int m = mat.size();
    int n = mat[0].size();

    //looking for neighbours
    for(int i=0;i<4;i++){
        int newr = row + delrow[i];
        int newcol = col + delcol[i];
        if(newr>=0 && newr<m && newcol>=0 && newcol<n && 
        !vis[newr][newcol] && mat[newr][newcol]=='O'){
            dfs(newr,newcol,vis,mat,delrow,delcol);
        }
    }
}

vector<vector<char>> fill(vector<vector<char>>&mat,int n,int m){
    vector<vector<int>> vis(m,vector<int>(n,0));

    //at every depth we need to check for all 4 directions too 
    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,1,0,-1};

    //now need to traverse borders 
    for(int j=0;j<n;j++){
        //first row
        if(!vis[0][j] && mat[0][j]=='O'){
            dfs(0,j,vis,mat,delrow,delcol);
        }

        //last row
        if(!vis[m-1][j] && mat[m-1][j]=='O'){
            dfs(m-1,j,vis,mat,delrow,delcol);
        }
    }

    for(int i=0;i<m;i++){
        //first column
        if(!vis[i][0] && mat[i][0]=='O'){
            dfs(i,0,vis,mat,delrow,delcol);
        }

        //last column
        if(!vis[i][n-1] && mat[i][n-1]=='O'){
            dfs(i,n-1,vis,mat,delrow,delcol);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]!=1){
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}

int main(){
    vector<vector<char>> mat{{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}};
    int m = mat.size();
    int n = mat[0].size();

    cout<<"Problem matrix : "<<endl;;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    fill(mat,n,m);
    cout<<"\nAnswer matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}