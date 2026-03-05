#include <bits/stdc++.h>
using namespace std;

vector<int>prefixSum(vector<int>num){

    int n = num.size();

    vector<int>psum(n,0);
    psum[0] = num[0];

    for(int i=1;i<n;i++){
        psum[i] = psum[i-1] + num[i];
    }
    return psum;

}

int findPrefixSum(vector<int>prefix,int l,int r){
    return prefix[r] - prefix[l-1];
}

int main() {
    
    vector<int>v = {1,2,3,4,5,7};

    vector<int>Prefix_sum = prefixSum(v);
    
    int ans = findPrefixSum(v,2,3);
    
    cout << ans;

    return 0;
}