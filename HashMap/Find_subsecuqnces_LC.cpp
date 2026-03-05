#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s = "LLCC";
    unordered_map<char,int>mpp;
    
    int count = 0;

    for(int i=0;i<s.size();i++){

        if(mpp.find('L')!=mpp.end() && s[i] == 'C'){
            count = count + mpp['L'];
        }
        if(s[i] == 'L'){
            mpp[s[i]]++;
        }
    }
    
    cout << count;
    return 0;
}