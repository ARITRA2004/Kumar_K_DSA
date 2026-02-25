#include <bits/stdc++.h>
using namespace std;

/*

questions:
Understanding :-> You are standing at index 1 of the array. You have to reach the last index N 
of the array in minimum cost ; you can only make 1 step or 2 step jumps. 
If you are jumping from index i to index j cost will be-> abs(b[i] - b[j]) 

intuition:
    arr[] = {10 30 40 20}
             0  1  2  3
    
    i can go i+1 or i+2

    dp[0] = 0; -> because the cost to reach 'i' is 0 because i am standing on that index
    dp[1] = arr[0] - arr[1] 

    dp[2] = arr[0] - arr[2]+dp[0] or arr[1]-arr[2]+dp[1]
    dp[2] = 


    dp[3] = arr[1] - arr[3]+dp[1] or arr[2] - arr[3]+ dp[2]
    

    general formula :-> dp[i] = min(abs(arr[i-2] - arr[i])+dp[i-2],abs(arr[i-1]-arr[i])+dp[i-1])

*/

int main()
{
    vector<int>arr = {10,30,40,20};
    int n = 4;

    int dp[n]={0};

    //base case

    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);

    for(int i=2;i<n;i++){
        dp[i] = min(abs(arr[i-2] - arr[i])+dp[i-2],abs(arr[i-1]-arr[i])+dp[i-1]);
    }

    cout << dp[n-1];

    return 0;
}