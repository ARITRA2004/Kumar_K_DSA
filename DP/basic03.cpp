#include <bits/stdc++.h>
using namespace std;

/*

question: Select maximum sum subset from the two arrays such that no two elements are consecutive


Array 1(a1) : {1,5,3,21234}

Array 2(a2) : {-4509,200,3,40}

Answer:- (200+21234=21434)

explanation: 
Modified Version : We are given ‘2’ arrays . Select some elements from both of these arrays (select a subset) such that:-

--->1. Sum of those elements is maximum(Sum of the subset is maximum).

--->2. No 2 elements in the subset should be consecutive.(Note:-If you select, say the 5th element from Array-1, 
then you are not allowed to select 4th element from either Array-1 or Array-2 nor are you allowed to 
select the 5th element from Array -2 all of them are considered consecutive :-) )


intuition:
dp[0] --->  arr1[0] or arr2[0]
      ---> or dont select anything and i can put '0' there

dp[1] --->  arr1[1] or arr2[1] 
      --->  or arr1[0] or arr2[0]

dp[2] ---> arr1[2]+ (arr1[0]or arr2[0]) or arr2[2]+ (arr1[0] or arr2[0])
      ---> or arr1[1] or arr2[1]

dp[3] ---> arr1[3] + (dp[1]) or arr2[3] + dp[1]
      ---> or dp[2]

general formula ---> dp[i] = arr1[i] + dp[i-2] or arr2[3] + dp[i-2]  
                ---> or dp[i-1]

max of both  :->  max((arr1[i]+dp[i-2],arr2[i]+dp[i-2]),dp[i-1]);
                  max(max(arr1[i],arr1[i])+dp[i-2],dp[i-1]);
*/

int main() {

    vector<int> arr1 = {2,3,4,-8,2};
    // vector<int> arr1 = {1,5,3,21234};
    vector<int> arr2 = {-5,8,3,1,-4};
    // vector<int> arr2 = {-4509,200,3,40};

    int n = arr1.size();
    int dp[n] = {0};

    //base cases
    int kk = 0;
    dp[0] = max(arr1[0],arr2[0]);
    dp[1] = max(max(arr1[1],arr2[1]),dp[0]);

    for(int i=2;i<n;i++){
        dp[i] = max(max(arr1[i]+dp[i-2],arr2[i]+dp[i-2]),dp[i-1]);
    }

    cout << dp[n-1];

    return 0;
}