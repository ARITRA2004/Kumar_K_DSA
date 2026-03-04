#include <bits/stdc++.h>
using namespace std;

/*

    Find the nodes level

*/

int main() {
    
    int n,m;

    cin >> n >> m;

    int A[n];
    int B[n];

    for(int i=0;i<m;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];

    vector<int>G[n];  

    /*
        what will be the structure of this

        G[0] -> [......] -> vector
        G[1] -> [......] -> vector
        G[2] -> [....] -> vector
    */

    for(int i=0;i<m;i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    cout << "adjacency list :" << endl;
    for(int i=0;i<n;i++){
        cout << i <<" -> ";
        for(auto it:G[i]){
            cout  << it << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    int level[n]={0};

    queue<int>q;
    int vis[n]={0};

    int start_node = 0;
    q.push(0);
    level[0] = 0;
    int leb = 0;
    vis[0] = 1;

    for(int i=0;i<n;i++){

        if(G[i].size()>0){

            q.push(i);
            vis[i] = 1;

            while(!q.empty()){

                int parent_node = q.front();
                q.pop();

                for(auto it:G[parent_node]){
                    if(vis[it] == 0){
                        q.push(it);
                        vis[it] = 1;
                        level[it] = level[parent_node] + 1; 
                    }           
                }
            }
        }else continue;
    }
    
    for(int i=0;i<n;i++){
        cout << i << " -> " << level[i] << endl;
    }

    return 0;
}