#include <bits/stdc++.h>
using namespace std;

/*

    Find the prime numbers from 1 to n in a very optimized way

    this is the simple Sieve of Eratosthenes

*/


int main() {
    
    int n = 1e5;

    vector<bool>prime(n+1,true);

    for(int i=2;i<=sqrt(n);i++){

        if(prime[i] == true){
            for(int j = i*i;j<=n;j = j+i){
                prime[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i] == true){
            cout << i << " ";
        }
    }

    return 0;
}