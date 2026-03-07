#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,target;
    cin >> n >> target;
    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int low = 0;
    int high = n-1;
    int index = 0;
    int ans = -1;

    while(low <= high){
        int mid = (low+high)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    if(ans == n || nums[ans] != target){
        cout << -1;
        return -1;
    }
    cout << ans;
    return ans;
}