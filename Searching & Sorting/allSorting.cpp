#include<iostream>
#include<vector>
using namespace std;

//O(n^2) worst case
vector<int> bubbleSort(vector<int>&v){

    for(int j=v.size()-1;j>0;j--){
        for(int i=0;i<j;i++){
            if(v[i]>v[i+1])
            swap(v[i],v[i+1]);
        }
    }
}

//O(n^2) worst case
vector<int> insertionSort(vector<int>&v){
     int key,j;
     for(int i=1;i<v.size();i++){
        key = v[i];
        j = i-1;

        while(j>=0 && v[j]>key){
            v[j+1] = v[j];
            j=j-1;
        }
        v[j+1] = key;
     }
}

vector<int> selectionSort(vector<int>&v){
    int minIndex;
    for(int i=0;i<v.size()-1;i++){
        minIndex = i;
        for(int j=i+1;i<v.size();j++){
            if(v[j]<v[minIndex])
            minIndex = j;
        }
        if(minIndex!=i)
        swap(v[minIndex],v[i]);
    }
}

void merge(vector<int>&v,int beg,int mid,int end){
    int n1 = mid-beg+1;
    int n2 = end-mid;

    vector<int> leftArray,rightArray;
    for(int i=0;i<n1;i++)
    leftArray.push_back(v[beg+i]);

    for(int i=0;i<n2;i++){
        rightArray.push_back(v[mid+1+i]);
    }

    int i=0,j=0,k=beg;

    while(i<n1 && j<n2){
        if(leftArray[i]<=rightArray[j]){
            v[k] = leftArray[i];
            i++;
        }
        else{
            v[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        v[k] = leftArray[i];
        i++;
        k++;
    }
    while(j<n2){
        v[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>&v,int beg,int end){
    if(beg>=end) return;

    int mid;

    if(beg<end){
        mid = beg + (end-beg)/2;
        mergeSort(v,beg,mid);
        mergeSort(v,mid+1,end);
        merge(v,beg,mid,end);
    }
}

void display(vector<int>&v){
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>v {14,13,27,35,10,19,44,42};
    bubbleSort(v);
    display(v);

    insertionSort(v);
    display(v);

    mergeSort(v,0,v.size()-1);
    display(v);
    return 0;
}