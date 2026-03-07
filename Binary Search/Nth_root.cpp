#include <bits/stdc++.h>
using namespace std;

int func(int mid, int n, int m){
    int ans = 1;

    for(int i=1;i<=n;i++){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m)return 1;
    return 0;
}


int main(){

    int n,m;
    cin >> n >> m;

    int low = 1;
    int high = m;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;
        int milD = func(mid,n,m);

        if(milD == 2){
            high = mid-1;
        }
        else if(milD == 1){
            cout << mid;
            return mid;
        }
        else low = mid+1;
    }
    cout << ans;

    return 0;
}