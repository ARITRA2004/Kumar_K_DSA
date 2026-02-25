// Check if there are any two Equal numbers in an array at a distance less than or equal to k


#include <bits/stdc++.h>
using namespace std;

typedef int number;
typedef int index;

int main() {

    vector<int>v = {3,1,2,3,2}; //ans -> 
    int k = 1;

    int n = v.size();
    unordered_map<number,index>mpp;

    int distance = 0;

    for(int i=0;i<n;i++){

        if(mpp.find(v[i])!=mpp.end()){
            distance = i - mpp[v[i]];
            if(distance <= k){
                cout << "true";
                return 0;
            }
        }
        mpp[v[i]] = i;
    }
    cout << "false";
    return 0;

}