#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,x,y;
    cin >> n >> x >> y;

    int A[n]={0};
    int B[n] = {0};

    for(int &ai:A) cin >> ai;
    for(int &bi:B) cin >> bi;

    vector<int> diff(n,0);
    int base_sum = 0;

    for(int i=0;i<n;i++){
        base_sum += B[i];
        diff[i] = A[i] - B[i];
    }

    sort(diff.begin(),diff.end());

    int max_tip = 0;

    for(int i=0;i<n;i++){
        
    }
}