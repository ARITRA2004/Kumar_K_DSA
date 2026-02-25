#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    // int row , col;
    
    // cin >> row >> col;
    
    // for(int i=1;i<=row;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << "0" << " ";
    //     }
    //     cout << endl;
    // }
    
    // int ip;
    // cin >> ip;
    
    // for(int i=1;i<=ip;i++){
    //     int sum =0;
        
    //     for(int j=1;j<=i;j++){
    //         sum += j;
    //         if(i == j) cout << j;
    //         else cout << j << "+";
    //     }
    //     cout << "=" << sum;
    //     cout << endl;
    // }
    
    int ip;
    cin >> ip;
    int count = 1;
    
    for(int i=1;i<=ip+(ip-1);i=i+2){
        for(int j=i;j<=ip+(ip-1);j=j+2){
            cout << j << " ";
            if(j == ip+(ip-1) && i>1){
                count = count+1;
                int temp = count;
                int k=1;
                while(temp>1){
                    cout << k << " ";
                    k = k+2;
                    temp--;
                }
            }
        }
        cout << endl;
    }
}
