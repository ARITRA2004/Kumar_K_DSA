#include <bits/stdc++.h>
using namespace std;


int main(){
    unordered_map<int,int> a;

    int n;
    cin >> n;

    while(n%2 == 0){
        a[2]++;
        n = n/2;
    }

    for(int i=3;i<=sqrt(n);i = i+2){

        while(n%i == 0){
            a[i]++;
            n = n/i;
        }
    }

    if(n > 2){
        a[n]++;
    }

    cout << endl << "all prime factors are : " << endl;
    for(auto it:a){
        cout << it.first << " -> " << it.second << endl;
    }
    return 0;
}