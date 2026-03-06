#include <bits/stdc++.h>
using namespace std;

/*

    sum <= k

*/


int main() {
    
    int n,k;

    cin >> n >> k;
    int sum = 0;

    vector<int>v(n,0);
    int count = 0;

    for(int i = 0 ;i < n ;i++) cin >> v[i];

    for(int i=0, j = 0;j<n;j++){
        sum += v[j];

        while(sum > k){
            sum -= v[i];
            i++;
        }

        count = count +  (j-i+1);    
    }
    cout << count;
    return 0;
}