// AMAZON INTERVIEW QUESTION




#include <bits/stdc++.h>
using namespace std;

// find the prefix sum of an array

vector<int>prefixSum(vector<int>v){

    vector<int>PrefixSum;
    int currentMax = v[0];
    PrefixSum.push_back(v[0]);

    for(int i=1;i<v.size();i++){
        currentMax = max({0,v[i],v[i] + currentMax});
        PrefixSum.push_back(currentMax);
    }

    return PrefixSum;
}

// find the suffix sum

vector<int>suffix_sum(vector<int>v){

    int n = v.size();
    vector<int>SuffixSum(n,0);
    int currentMax = v[n-1];
    SuffixSum[n-1] = v[n-1];

    for(int i=n-2;i>=0;i--){
        currentMax = max({0,v[i],currentMax+v[i]});
        SuffixSum[i] = currentMax;
    }
    return SuffixSum;
}

int maxTwonoOverlappingSubarray(vector<int>v){
    int n = v.size();
    if(n == 0) return 0;

    vector<int>pre_sum = prefixSum(v);
    vector<int>suf_sum = suffix_sum(v);

    vector<int>maxPrefixSum;
    maxPrefixSum.push_back(pre_sum[0]);
    for(int i=1;i<n;i++) maxPrefixSum.push_back(max(maxPrefixSum[i-1],pre_sum[i]));
    
    for(auto it:maxPrefixSum) cout <<it << " ";
    cout << endl;

    vector<int>maxSuffixSum(n,0);
    maxSuffixSum[n-1]=(suf_sum[n-1]);
    for(int i=n-2;i>=0;i--) maxSuffixSum[i] = (max(maxSuffixSum[i+1],suf_sum[i]));

    for(auto it:maxSuffixSum) cout <<it << " ";

    // now this is the thing of partition
    int maxiSum = INT_MIN;
    for(int i=0;i<n-1;i++) maxiSum = max(maxiSum,maxPrefixSum[i]+maxSuffixSum[i+1]);

    return maxiSum;
}

int main(){
    // vector<int>v = {10,-8,-2,-3,5};
    vector<int>v = {1,5,-3,4,-9,9,2};

    vector<int>pre = prefixSum(v);
    vector<int>suf = suffix_sum(v);

    // for(auto it:v) cout << it << " ";
    cout << endl;
    // for(auto it:pre) cout << it << " ";
    // cout << endl;
    // for(auto it:suf) cout << it << " ";

    int maxiSum = maxTwonoOverlappingSubarray(v);
    cout << endl << maxiSum;
    return 0;
}