#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    vector<int>com = {2,2,3,1};
    vector<int>stocks = {3,2,1,4};
    vector<int>cost = {2,3,1,6};
    ll budget = 30;
    
    int n = com.size()-1;
    
    ll low = 0;
    ll high = 1e18;    
    ll ans = 0;
    
    while(low<high){
        ll mid = (low+high)/2;
        ll tot_cost = 0;
        
        for(int i=0;i<n;i++){
            ll p = com[i]*mid;
            ll req = p-stocks[i];
            tot_cost += req*cost[i];    
        }
        
        if(tot_cost <= budget){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    
    cout << ans;
    
    return 0;
    
}