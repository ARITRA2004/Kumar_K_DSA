#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,q;
    cin >> n >> q;

    vector<int>profit(n,0);
    vector<int>que(q,0);

    for(int &p:profit) cin >> p;
    for(int &qu:que) cin >> qu;

    sort(profit.begin(),profit.end());
    
    // count total profit
    int total_profit = 0;
    for(int it:profit){
        total_profit += it;
    }

    vector<int>prefix(n,0);
    prefix[0] = profit[0];

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + profit[i]; 
    } 


    // ans for all queries;
    vector<int>ans;
    int query_index = 0;

    while(q--){
        
        int l=0, h = n-1, target = que[query_index++];
        int pivot_element = 0;

        while(l<=h){
            int mid = (l+h)/2;

            if(profit[mid] <= target){
                pivot_element = mid;
                l = mid + 1;
            }
            else h = mid-1;
        }
        
        int left_part = target*pivot_element - prefix[pivot_element];
        int right_part = (total_profit - prefix[pivot_element]) - target*(n-pivot_element);

        ans.push_back(left_part + right_part);
    }

    for(auto it: ans) cout << it << " ";

}