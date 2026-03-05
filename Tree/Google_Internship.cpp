#include <bits/stdc++.h>
using namespace std;

/*

Given an undirected acyclic graph with all of the vertices having at most 3 neighbors.
Please find a vertex in the tree so that after setting the vertex as root it forms a valid binary tree.T

*/

/*

    1 -> 2,3,4
    2 -> 1,4



*/

int main() {
    
    int n; cin >> n;
    
    vector<int>G[n+1];
    int x,y;

    int i=1;

    while(i<=n-1){
        cin >> x >> y;

        G[x].push_back(y);
        G[y].push_back(x);

        i++;
    }

    int ans = 0;

    for(int j=1;j<=n;j++){
        int size = G[j].size();
        if(size == 1){
            ans = j;
            cout << j;
            break;
        }
    }

    return 0;
}