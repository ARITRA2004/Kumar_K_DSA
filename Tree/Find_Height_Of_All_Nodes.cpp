#include <bits/stdc++.h>
using namespace std;

int height[50000+5];
/*

    Question: Find the heights of each nodes in the tree
    
    DFS: Because it will go at the leaf node first and calculate the height from the last 
         This will be best method to do.

    What the DFS do: I
        -> In DFS ; you come outside the first for loop only when you
        reach a leaf node for the first time; hence printing the node after
        the first loop guarantees that all the leaves will be printed first

*/

void DFS(int node, vector<int>G[],int vis[], int parent[]){

    vis[node] = 1;

    for(auto u: G[node]){
        if(vis[u] == 0){
            parent[u] = node;
            DFS(u,G,vis,parent);
        }
    }

    // buttom up traversal

    int h = 0;

    for(auto child:G[node]){
        if(child == parent[node]);
        else{
            h = max(h,height[child]); 
        }
    }
    
    height[node] = 1 + h;

}

int main() {

    int n ; 
    cin>>n ; 
    vector <int> G[n+1];
    int 
 
    i = 1 ; 
    while(i<=n-1){
        int u,v;
        cin>>u>>v ; 
        G[u].push_back(v);
        G[v].push_back(u); 
        i++;
    }
    
    int vis[n]={0};
    int parent[n] = {0};

    DFS(1,G,vis,parent);

    i = 1 ;

    cout << endl << "Heights of each nodes : " << endl;
    while(i<=n){
        cout << "Node " << i << " : " <<(height[i]);
        cout<<'\n';
        i++;
    }

    return 0;
}