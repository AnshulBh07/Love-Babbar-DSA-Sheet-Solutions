#include <iostream>
#include <vector>

using namespace std;

// code for DSU using union by rank
class DisjointSetUnion{
    private:
        vector<int> parent,rank;
    public:
        // consutructor that initializes parent vector and rank vector,
        // this constructor will be parametrized, n will be the number of nodes in graph 
        DisjointSetUnion(int n){
            parent.resize(n);
            rank.resize(n,0);

            // initially each node is a parent of itself
            for(int i=0;i<n;i++)
            parent[i] = i;
        } 

        int findUPar(int node){
            if(node == parent[node])
            return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;

            else if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;

            // have same rank
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

int main(){
    DisjointSetUnion dsu(10);

    dsu.unionByRank(1,2);
    dsu.unionByRank(2,3);
    dsu.unionByRank(4,5);
    dsu.unionByRank(6,7);
    dsu.unionByRank(5,6);

    // dsu.unionByRank(3,7);

    if(dsu.findUPar(3) == dsu.findUPar(7))
    cout<<"Same component\n";
    else
    cout<<"Not in same component\n";

    dsu.unionByRank(3,7);

    return 0;
}