#include <bits/stdc++.h>
using namespace std;


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
    int fives[n]={0};

    int vis[n] = {0};
    int val[n] = {0};

    for(int i=0;i<n;i++) cin >> val[i];

    q.push(0);
    if(val[0] == 5) fives[0] = 1;

    vis[0] = 1;

    int dis[n] = {0}; // --> distance array to find the distance from the parent of every node
    dis[0] = 1;

    while(!q.empty()){

        int parent_node = q.front();
        cout << parent_node;
        q.pop();

        for(auto it:G[parent_node]){
            if(vis[it] == 0){
                q.push(it);
                vis[it] = 1;
                dis[it] = dis[parent_node] +1;
                if(fives[it] == 5){
                    fives[it] = fives[parent_node] + 1;
                }
                else{
                    fives[it] = fives[parent_node];
                }
            }
            else{
                if(dis[it] == dis[parent_node] + 1){
                    int temp;

                    if(val[it] == 5) temp =  fives[parent_node] + 1;
                    else fives[it] = fives[parent_node];

                    if(temp > fives[it]){
                        fives[it] = temp;
                    }
                }
            }
        }
    }


    // print the all nodes with their number of fives and the distances
    
    for(int i=0;i<n;i++){
        cout << dis[i] << " " << fives[i] << endl;
    }

    return 0;
}