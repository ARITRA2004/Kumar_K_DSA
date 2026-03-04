#include <bits/stdc++.h>
using namespace std;

// The code is not correct 


/*
    Questions: Find the number of shortest paths
    I will store all the shortes paths in a array.

*/


int main() {

    int n,m;
    cin >> n >> m;

    int A[n];
    int B[n];

    for(int i=0;i<m;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];

    vector<int>G[n];

    for(int i=0;i<m;i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    queue<int>q;
    int vis[n]={0};

    q.push(0);
    vis[0] = 1;

    int shortest_possible_paths[n] = {0};

    while(!q.empty()){

        int parent_node = q.front();
        q.pop();

        for(auto it:G[parent_node]){
            if(vis[it] == 0){
                q.push(it);
                vis[it] = 1;
                shortest_possible_paths[it] = 1;
            }
            else{

                if(G[it]!=G[parent_node]){
                    if(shortest_possible_paths[it] == shortest_possible_paths[parent_node]+1){
                        shortest_possible_paths[it] = shortest_possible_paths[it]+1;
                    }    
                } 
                
            }
        }
    }

    for(int i=0;i<n;i++) cout << i <<" -> " << shortest_possible_paths[i];
    
    return 0;
}