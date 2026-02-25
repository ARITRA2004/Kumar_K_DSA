#include <bits/stdc++.h>
using namespace std;

//	...1
//	..232
//	.34543
//	4567654

int main(){
	int n;
	cin >> n;
	
	int space = 1;
	int odd = 1;
	
	for(int i=1;i<=n;i++){
		
		// for the space
		for(int j=1;j<=n;j++){
			if(j<=n-space){
				cout << "*";
			}
			else{
				if(i > 1){
					for(int k=i;k<=odd;k++){
						if(k < odd || k > odd) cout << k;
						else cout << odd;
					}
				}else cout << odd;
			}
		}
		odd = odd+2;
		space++;
		cout << endl;
	}
}
