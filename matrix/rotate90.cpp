#include<iostream>
#include<vector>
using namespace std;

void rotate90Degree(vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    //swapping across the diagonal from first to last cell
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
           swap(matrix[i][j],matrix[j][i]);
        }
    }

    //now swapping as per the middle col
    int scol,ecol;

    for(int i=0;i<m;i++){
        scol = 0;
        ecol = n-1;

        while(scol<ecol){
            swap(matrix[i][scol],matrix[i][ecol]);
            scol++;
            ecol--;
        }
    }
}

int main()
{
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    for(vector<int> v:matrix){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    rotate90Degree(matrix);

    for(vector<int> v:matrix){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}