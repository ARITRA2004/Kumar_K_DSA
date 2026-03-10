#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>all_factors;

    int n;
    cin >> n;

    for(int i=1;i<=sqrt(n);i++){
        if(n % i == 0){
            if(n/i == i) all_factors.push_back(i);
            else{
                all_factors.push_back(i);
                all_factors.push_back(n/i);
            }
        }
    }

    sort(all_factors.begin(),all_factors.end());

    for(auto it:all_factors) cout << it << " ";
    cout << endl;

    return 0;
}