#include <bits/stdc++.h>
using namespace std;

/*

    Basic implementation of graph

    (1,2),(1,3),(2,4),(2,5) -> 1 based indexing
    (0,1),(0,2),(1,3),(1,4) -> 0 based indexing

    0 -> {1,2}  childern -> 2
    1 -> {3,4}  childern -> 2
    2 -> {}     0
    3 -> {}     0
    4 -> {}     0

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

    while(!q.empty()){

        int parent = q.front();
        q.pop();

        for(auto childrens:G[parent]){
            if(vis[childrens] == 0){
                vis[childrens] = 1;
                q.push(childrens);
                no_of_clildren[parent] = no_of_clildren[parent]+1;
            }
        }
    }

    cout << endl;

    for(int i=0;i<n;i++){
        cout << i << " -> " << no_of_clildren[i] << endl;
    }

    return 0;
}