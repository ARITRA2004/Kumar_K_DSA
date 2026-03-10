#include <bits/stdc++.h>
using namespace std;


void DFS(int node, vector<int>G[], vector<int>vis){

    vis[node] = 1;

    for(auto it:G[node]){
        if(vis[it] == 0){
            DFS(it,G,vis);
        }
    }

    cout << node << " ";
}   


int main(){

    int n,m; // n -> number of vertices, m -> number of edges
    cin >> n >> m;

    int A[n];
    int B[n];

    for(int i=0;i<m;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];

    vector<int>G[n];

    // Adjacency list

    for(int i=0;i<m;i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<int>vis(n,0);

    DFS(0,G,vis);

    return 0;
}