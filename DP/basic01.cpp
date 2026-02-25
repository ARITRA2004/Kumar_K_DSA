#include <bits/stdc++.h>
using namespace std;

// lets take a quary that will calculate the sum of indexes till 0,1,2....  indexes.
// Though we are do this question using DP I have to do it 
// arr[]={2,3,5,7,8};
// dp[0] -> arr[0] // sum till 0 index
// dp[1] -> arr[0] + arr[1] // sum till 1 index
// dp[2] -> arr[0]+arr[1]+arr[2];
// dp[2] -> dp[1] + arr[2];
// dp[3] -> dp[2] + arr[3];

// general formula is -> dp[i] = dp[i-1]+arr[i];

// so for this i will precalculate the sum till 'n' indexes

int main() {

    vector<int>v = {2,3,4,5,6};

    int n = v.size();

    vector<int>dp(n,0);
    int sum = 0;

    dp[0] = v[0];
    dp[1] = dp[0] + v[1];

    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+v[i];
    }

    int q = 4;

    while(q){
        int i;
        cout << "enter the index to calculate the sum : ";
        cin >> i;
        cout <<"sum is : "<< dp[i];
        q--;
        cout << endl;
    }

    return 0;
}