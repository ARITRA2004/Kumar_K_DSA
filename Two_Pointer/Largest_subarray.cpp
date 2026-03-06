#include <bits/stdc++.h>
using namespace std;

/*

    largest subarray whose sum <= k
*/

int main() {
    
    int n,k;
    cin >> n >> k;

    vector<int> v(n,0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int maxLen = INT_MIN;
    int sum = 0;

    for(int i=0,j=0;j<n;j++){
        sum += v[j];

        while(sum > k){
            sum -= v[i];
            i++;
        }

        maxLen = max(maxLen, j-i+1);    
    }

    cout << maxLen;

    return 0;
}