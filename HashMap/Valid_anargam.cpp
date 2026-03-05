#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s1 = "arit";
    string s2 = "rita";

    unordered_map<char,int>mpp;

    for(int i=0;i<s1.size();i++){
        mpp[s1[i]]++;
        mpp[s2[i]]--;
    }

    for(auto it:mpp){
        if(it.second!=0) return false;
    }

    return true;
    return 0;
}