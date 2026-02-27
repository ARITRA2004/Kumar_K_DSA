#include <bits/stdc++.h>
using namespace std;

/*


You are given an undirected graph consisting of N vertices, numbered from 0 to N-1,
connected with M edges. The graph is described by two arrays, A and B, both of length
M. A pair (A[K], B[K]), for K from 0 to M-1, describes an edge between vertex A[K] and
vertex B[K].

Each second, every vertex with at most one edge connected to it disappears. Every
edge which is connected to one of the disappearing vertices also disappears.


Function Defination: 

    Write a function:   int solution(int N, int A[], int B[], int M);
    N -> Verticies
    M -> Edges

    that, given an integer N and two arrays A and B of M integers each, returns the number
    of seconds after which the vertices will stop disappearing, or 0 if no vertices will ever
    disappear.

After how many seconds will the vertices stop disappearing?

example:
    Consider a graph with N = 7 vertices and following 6 edges: (0, 1), (1, 2), (2, 0), (1, 4), (4,
    5) and (4, 6).

    After the first second, vertices 3, 5, and 6 (marked red in the picture above) will
    disappear:

    After the next second vertex 4 will disappear and only vertices 0, 1 and 2 will be left:

    All three remaining vertices are connected to two edges, so none of will ever disappear
    and the answer is 2.


*/


int main() {
    
    int n,m;
    cin >> n >> m;

    int A[n];
    int B[n];

    vector<int>vis(n,0);
    vector<int>G[n];

    

    for(int i=0;i<m;i++){
        cin >> A[i];
    }

    for(int i=0;i<m;i++){
        cin >> B[i];
    }

    for(int i=0;i<m;i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }


    for(int i=0;i<n;i++){
        cout << i <<" -> ";
        for(auto it:G[i]){
            cout  << it;
        }
        cout << endl;
    }


    // now i have find the degree of each vartices or nodes

    int degree[n]={0};
    queue<int>q;

    for(int i=0;i<n;i++){
        int size = G[i].size();

        degree[i] = size;

        if(degree[i]<=1){
            q.push(i);
            vis[i] = 1;
        }
    }

    int time = 0; // I have to find the time needed so I assign the value of time  = 0

    int size_of_queue = q.size();

    int g = 0;

    if(size_of_queue == 0);
    else g = 1;

    while(g == 1){
        
        queue<int>new_queue;

        while(!q.empty()){

            int new_node = q.front();
            cout << "front element : " << new_node << endl;
            q.pop();


            for(auto it:G[new_node]){
                degree[it] = degree[it] - 1;

                if(degree[it] <= 1 && vis[it] == 0){
                    new_queue.push(it);
                    vis[it] = 1;
                }
            }
        }
        

        q = new_queue;

        if(q.size() == 0) g = 0;

        time = time + 1;

        cout << endl;
    }

    cout << time;

    return 0;
}