#include <bits/stdc++.h>
using namespace std;

/*

    Number of pairs whose absolute diff <=K 

    0 1 2
    1 2 3

    pairs -> 1,2 ; 2,3 ; 1,3

    take v[i] and v[j]
        check abs(v[i] - v[j]) <= k if true count
        else increase the i pointer to  i++;
    
    (1,2) ->  count =1;
    (1,3) -> count = 2;
    
    to count all the pairs if have to do j-i+1;

    1st time -> 1-0+1 = 2;
    2ns time -> 2-0+1 = 3;

    at the end count  = 5;

    substract count - n = 2

*/


int main() {

    int n,k;
    cin >> n >> k;

    vector<int>v(n,0);

    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());
    int count = 0;

    for(int i=0, j = 1;j<=n-1;j++){

        int diff = abs(v[i] - v[j]);
        
        while(diff > k){
            i++;
            diff = abs(v[i] - v[j]);
        }

        count = count + (j-i+1);
    }
    cout << (count-n);
    return 0;
}