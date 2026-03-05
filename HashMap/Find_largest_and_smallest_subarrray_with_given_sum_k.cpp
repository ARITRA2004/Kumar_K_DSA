#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int>nums = {2,3,1,2,4,3};
    int target = 7;

    unordered_map<int,int>mpp;
        int sum = 0;
        int minLen = INT_MAX;

        mpp[0] = -1;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            if(mpp.find(sum - target) != mpp.end()){
                int li = sum - target;
                int length = i-mpp[li];
                minLen = min(minLen,length);
            }

            mpp[sum] = i;
        }

        if(minLen == INT_MAX) return 0;

        return minLen;


    return 0;
}