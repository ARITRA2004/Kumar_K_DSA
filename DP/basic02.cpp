#include <bits/stdc++.h>
using namespace std;

// arr[] = {2,-3,5,-8,7}
// s = 5

// question: sum should be maximum and no 2 elements should be adjacents

// 1. i have to create a dp array
// 2. then I have to write the base cases
// 3. make a general formula
// 4. dp[n] is the answer

// dp[0] = arr[0]
// dp[1] = 1. arr[0] + arr[1] or 2. dp[0]
// dp[1] = max((arr[0] + arr[1]),dp[0])
// dp[1] = max((dp[0]+arr[1]),dp[0])

// dp[2] = 1. arr[2] + dp[0]
//         2. dp[1]

// dp[i] = max((arr[2]+dp[i-2]),dp[i-1])

int main() {
    
    vector<int>arr = {2,-3,5,-8,7};
    
    int n = arr.size();

    int dp[n] = {0};

    //base cases
    dp[0] = arr[0];
    dp[1] = max((dp[0]+arr[1]),dp[0]);

    for(int i=2;i<n;i++){
        dp[i] = max((arr[i]+dp[i-2]),dp[i-1]);
    }

    cout << dp[n-1];

    return 0;
}