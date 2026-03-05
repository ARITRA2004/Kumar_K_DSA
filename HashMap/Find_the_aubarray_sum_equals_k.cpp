#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int>v = {3,4,1,2,5};
    int sum = 0;
    unordered_map<int,int>mpp;
    int k = 7;
    int count = 0;

    for(int it:v){
        sum += it;

        if(mpp.find(sum - k) != mpp.end()){
            count = count + mpp[sum-k];
        }

        mpp[sum]++;
    }

    cout << count;

    return 0;
}