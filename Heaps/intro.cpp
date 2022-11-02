/*A heap is a tree type data structure which follows two properties 
1. it is a complete binary tree or a complete BST
2. It can be a min heap or a max heap
    min-heap : the value of root node is smaller than either of it's children
    max-heap : the value of root node is greater than either of its children

Normally a heap is represented by an array and all the operations are performed on arrau
itself (insrtion and deletion).
while perfomring those operations we should keep in mind that the complete binary tree structure of the
array should be maintained and the heap property should be retianed(max or min heap)
1. Insertion : the element is always inserted at the end and then the array is modified to satisfy 
the heap property and structure.The adjustment takes place from leaf to root node, i.e bottom to up.
Time complexity for inserting depends on the number of swaps made to retain the heap properties
1 element is O(logn) so for n elements it will be O(nlogn)
2. Deletion : You don't have a choice only the root element will always be deleted and then the adjustment
of nodes is done from root to leaf i.e top to bottom to retain heap properties.
Time Complexity = number of adjustmentrs made i,e O(nlogn) where logn is the height of complete 
binary tree.

Heapify : this refres to the process of adjustment of array after insertion or deletion,it follows 
adjustment from top to bottom just like deletion.Heapify basically mean creating a heap from given
array

Imp: proiority queues are implemented using min and max heaps
- smaller number higher priority uses min heap
- larger number higher prioirity uses max heap*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//change the direction of converting, start from end of arrray
//Time complexity : O(n) 
void heapify(vector<int>&v,int n,int i){
    int largest = i; //largest as root
    int l = 2*i+1; //left child of root
    int r = 2*i+2; //right child

    if(l<n && v[l]>v[largest])
    largest = l;

    if(r<n && v[r]>v[largest])
    largest = r;

    if(largest!=i){
        swap(v[i],v[largest]);
        heapify(v,n,largest);
    }
}

void buildHeap(vector<int>&v,int n){
    //we can ignore the leaf nodes as they are already a heap
    int startidx = (n/2)-1;

    //perform reverse level order traversal from last non leaf node and
    //heapify each node 
    for(int i=startidx;i>=0;i--){
        heapify(v,n,i);
    } 
}

//print heapified array
void print(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}

int main()
{
    vector<int> v{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = v.size();
    
    buildHeap(v,n);
    print(v,n);
    return 0;
}