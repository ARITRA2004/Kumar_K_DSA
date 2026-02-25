// example ->
// arr = [9,3,3,3,9]
//        0 1 2 3 4
// arr[0] == arr[4] and sum(arr[1]....arr[3]) = 9 which is equals to arr[0] or arr[4]


// brute force
// TC -> O(n^2)
/*
#include <bits/stdc++.h>
using namespace std;


int main(){
    // vector<int>v = {9,3,3,3,9};
    // vector<int>v = {-4,4,0,0,-8,-4};
    vector<int>v = {1,2,3,4,5};
    int n = v.size();
    int sum = 0;
    int count = 0;

    for(int i=0;i<v.size();i++){
        for(int j = i;j<v.size();j++){
            sum += v[j];
            if(v[i] == v[j] && 3*v[i] == sum) count++;
        }
    }
    cout << count;

    return 0;
}

*/


// now using the hash map
//1st part check how many sub arrays whose first and last element is same and the size is >= 3
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v = {-4,4,0,0,-8,-4};
    // vector<int>v = {9,2,3,4,9,5,8,9};
    // vector<int>v = {9,3,3,3,9};

    // -4 -> 1
    // 4 -> 0
    // 4 2 3 4 0 7 4 1 2 4 5 6 4 -> 4 + 3+ 2+ 1 -> 10
    int n =v.size();
    int count_subarray = 0;

    unordered_map<int,int>f;

    for(int it:v){
        int current = it;
        count_subarray += f[it];
        f[it] = f[it]+1;
    }

    for(auto it:f) cout << it.first << " -> " << it.second << endl;

    cout << count_subarray;

    return 0;
}

*/


// now i will do the final step
// 1. arr[i] == arr[j] 
// 2. sum(arr[i+1]....arr[j-1]) == arr[i] || arr[j]

// map<pair<sum,last_ele>,freq>

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    vector<int>v = {-4,4,0,0,-8,-4};
    map<pair<ll,ll>,ll>freq;
    ll sum = 0;
    ll count = 0;

    for(int i=0;i<v.size();i++){
        sum += v[i]; // -12
        ll desire_sum = sum - 2*v[i]; // -12 + 8 = -4

        // -4 - 
        if(freq.find({desire_sum,v[i]}) != freq.end()){
            count = count + freq[{desire_sum,v[i]}];
        }
        freq[{sum,v[i]}]++;
    }

    for(int i=0;i<v.size()-1;i++){
        if(v[i] == v[i+1] && v[i+1] == 0) count--;
    }

    cout << count;
    return 0;
}


// 