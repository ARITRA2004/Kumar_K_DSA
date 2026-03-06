#include <bits/stdc++.h>
using namespace std;


int noOfLCT(string s){

    unordered_map<char,int>mpp;
    int count = 0;
    int l = 0, lc = 0, lct = 0;

    for(int i=0;i<s.size();i++){
        if(s[i] == 'L') l++;
        if(s[i] == 'C') lc++;
        if(s[i] == 'T') lct = lct + lc;   
    }
    return lct;
}



int main() {
    
    string s = "LLCCTT";
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
    cout << "number of LCT : " << noOfLCT(s) << endl;
    cout << "number of LC : " << count;
    return 0;
}