#include <bits/stdc++.h>
using namespace std;

/*

    Given a Tree of ‘N’ Nodes and ‘N-1’ Edges; rooted at Node-1 ; 
    each node is assigned either 1 or 0 ; for each node “i” ;
    find the number of 1’s on the shortest path from node 1 to node “i” 

*/


int main() {
    int n;
    cin >> n;
    vector<int>G[n];
    
    int i=1;

    while(i<=n-1){ //n=5, start = 0, 
        int x,y;
        cin >>x>>y;

        x--;y--;

        G[x].push_back(y);
        G[y].push_back(x);

        i++;
    }

    int color[n]={0};

    while(i<n){
        cin>>color[i];
        i++;
    }
    
    cout << "this is the graph : " << endl;
    for(int i=0;i<n;i++){
        cout << i;
        for(auto it:G[i]){
            cout << " -> " << it ;
        }
        cout << endl;
    }

    cout << endl;

    vector<int>vis(n,0);
    queue<int>q;

    vector<int>no_of_clildren(n,0);
    q.push(0);
    vis[0] = 1;
    int ans[n] = {0};

    ans[0] = color[0];

    while(!q.empty()){

        int parent = q.front();
        q.pop();

        for(auto childrens:G[parent]){
            if(vis[childrens] == 0){
                vis[childrens] = 1;
                q.push(childrens);
                
                if(color[childrens] == 1){
                    ans[childrens] = ans[parent]+1;
                }
                else{
                    ans[childrens] = ans[parent];
                }
            }
        }
    }

    return 0;
}