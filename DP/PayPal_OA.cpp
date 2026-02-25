#include <bits/stdc++.h>
using namespace std;

/*

    Question: Find the largest valid substring - Valid string is a string where adjacent pair of char have diff<=k

    example: "abaabcadef"


*/

int main() {

    string str = "abaabcadef";
    int n = str.size();
    int k = 2;

    vector<int>dp_len(n,0);

    int maxLen = 0;
    int maxindex = 0;

    dp_len[0] = 1;
    maxLen = 1;
    maxindex = 0;

    for(int i=1;i<n;i++){

        if(abs(str[i]-str[i-1])<=k){
            dp_len[i] = dp_len[i-1]+1;
        }else{
            dp_len[i] = 1;
        }

        if(dp_len[i] > maxLen){
            maxLen = dp_len[i];
            maxindex = i;
        }
    }

    int startIndex = maxindex - maxLen + 1;
    cout << str.substr(startIndex,maxLen)<< endl;

    cout << maxLen << endl;

    return 0;
}