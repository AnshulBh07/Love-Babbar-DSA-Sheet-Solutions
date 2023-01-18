//Space Complexity : O(n x m)
//Time Complexity : O(n x m)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &vis,vector<vector<int>> &image,int sr,int sc,int newColor){
    int m = image.size();
    int n = image[0].size();
    int iniColor = image[sr][sc];
    vis[sr][sc] = newColor;
    vector<int> delrow{-1,0,1,0};
    vector<int> delcol{0,-1,0,1};
    queue<pair<int,int>> q;
    q.push({sr,sc});

    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        //looking for neighbours in the image matrix
        for(int i=0;i<4;i++){
                int newr = cr+delrow[i];
                int newc = cc+delcol[i];

                //necessary conditions
                if(newr>=0 && newr<m && newc>=0 && newc<n && !vis[newr][newc] && 
                image[newr][newc]==iniColor){
                    vis[newr][newc]=newColor;
                    q.push({newr,newc});
                }
            }
    }
}

void floodFill(vector<vector<int>> &image,int sr,int sc,int newColor){
    int m = image.size();
    int n = image[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));

    bfs(vis,image,sr,sc,newColor);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(image[i][j]!=vis[i][j] && vis[i][j]==0){
                vis[i][j] = image[i][j];
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};   
    int sr =1,sc=1;
    int newColor = 2;
    floodFill(image,sr,sc,newColor);
    return 0;
}