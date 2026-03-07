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
        int ans = n;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }

        // 'ans' store the ans 
        
        // this if condition is for if the elemenet is not present in the array then it will return -1
        if(ans >= 0 && nums[ans-1] != target){
            cout << -1;
            return 0;
        }
        cout << ans-1;
    return 0;
}