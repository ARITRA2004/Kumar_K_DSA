#include <bits/stdc++.h>
using namespace std;

/*
    This is the Google interview question

    Find the sum of sub trees

*/

int sum[50000+5];
int b[50000+5];

void DFS(int node, vector<int>G[],int vis[], int parent[]){

    vis[node] = 1;

    for(auto it:G[node]){
        if(vis[it] == 0){
            parent[it] = node;
            DFS(it,G,vis,parent);
        }
    }

    // to find the sum of subtree

    int s = 0;

    for(auto child:G[node]){
        if(child == parent[child]);
        else{
            s = s + sum[child];
        }
    }

    sum[node] = b[node] + s;
}


int main() {

    int n; cin >> n;

    vector<int>G[n+1];

    int i=1;

    while(i<=n){
        cin >> b[i];
        i++;
    }

    i = 1;

    while(i<=n-1){

        int u,v;
        cin>>u>>v ; 
        G[u].push_back(v);
        G[v].push_back(u); 
        i++;

    }

    int vis[n+1]={0};
    int parent[n+1]={0};

    DFS(1,G,vis,parent);

    int ans = INT_MIN;

    i = 1;

    while(i<=n){
        ans = max(ans,sum[i]);
        i++;
    }

    cout << ans;
    
    return 0;
}