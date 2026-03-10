#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int>spf (n);

    // every number to itself
    for(int i=2;i<=n;i++) spf[i] = i;

    for(int i=2;i<=sqrt(n);i++){
        // scheve of eratosthenis

        if(spf[i] == i){
            for(int j=i*i;j<=n;j = j+i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    for(int i=0;i<=n;i++){
        cout << i << " -> " << spf[i] << endl;
    }

    return 0;
}