#include <bits/stdc++.h>
using namespace std;

/*

    Given two arrays A and B -> find the number of valid pairs (A[i],B[j]) such that B[j] is multiple of A[i] 

    1. take the frequencies of every element from array A and array B 
    2. Count the elements is present in the freqB which is the multiple of freqA elements 
        like: first element of freaA is 2 then i will make a table from 2 to 10^(5) and check how many times the mutiple comes to
              freqB then add the freq an after that Add the freq of freqBs to the freqA
    3. Finally the count will "count" the total pairs.

*/


int main() {
    
    int n; cin >> n;
    
    int A[n];
    int B[n];

    unordered_map<int,int>freqA,freqB;

    for(int i=0;i<n;i++){
        cin >> A[i];
        freqA[A[i]]++;
    }

    for(int i=0;i<n;i++){
        cin >> B[i];
        freqB[B[i]]++;
    }

    int count = 0;

    for(auto it = freqA.begin();it != freqA.end();++it){
        int curr = it->first;
        int d = 0;

        int j = curr;

        while(j<=1e5){
            d = d + freqB[j];
            j = j+curr;
        }
        d = d*freqA[curr];

        count = count + d;
    }

    cout << count;

    return 0;
}