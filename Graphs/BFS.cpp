#include <bits/stdc++.h>
using namespace std;

/*

basically this programme for the BFS traversal of a undirected, unweitage graphh

*/

int main() {
    
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

    queue<int>q;
    
    int vis[n] = {0};
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){

        int parent_node = q.front();
        cout << parent_node;
        q.pop();

        for(auto it:G[parent_node]){
            if(vis[it] == 0){
                q.push(it);
                vis[it] = 1;
            }    
        }
    }


    return 0;
}