#include <bits/stdc++.h>
using namespace std;

// Number of subarrays whose count of distinct number <= K 

int main() {
     
    int n,k;
    cin >> n >> k;

    vector<int>v(n,0);

    for(int i=0;i<n;i++) cin >> v[i];
    
    unordered_map<int,int>mpp;
    int count = 0;

    for(int i = 0,j = 0;j<n;j++){
        mpp[v[j]] = mpp[v[j]] + 1;

        int size = mpp.size();

        while(size > k){
            mpp[v[i]] = mpp[v[i]] - 1;

            if(mpp[v[i]] == 0) mpp.erase(v[i]);
            i++;

            size = mpp.size();
        }
        count = count + (j-i+1);
    }

    cout << count;

    return 0;
}

