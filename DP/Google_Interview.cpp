#include <bits/stdc++.h>
using namespace std;

/*

    question: Google Interview - Find the largest valid substring - Valid string
    is a string where any pair of characters have diff <= k

    "ababbcd"   k<=2
        a -> max_diff -> 0
        b -> max diff -> 1
        a -> max_diff -> 1
        b -> max_diff -> 1
        b -> max_diff -> 1
        c -> max_diff -> 1, min = 3 dp[i] = 1

    
*/


int main() {

    string str = "ababbcd";
    
    int n = str.size();

    vector<int>dp(n,0);

    return 0;
}