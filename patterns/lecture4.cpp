#include <bits/stdc++.h>
using namespace std;

//	***1
//	**12
//	*123
//	1234
/*
int main(){
	int n;
	cin >> n;
	
	// i/p -> 4
	// 3 -> n-1
	// 2 -> n-2
	// 1 -> n-3
	
	int space = 1;
	
	for(int i=1;i<=n;i++){
		// for printing the space
		int ele = 1;
		
		for(int j=1;j<=n;j++){
			if(j<=n-space) cout << " ";
			else {
				cout << ele;
				ele++;
			}
		}
		space++;
		cout << endl;
	}
}
*/

int main(){
	int n;
	cin >> n;
	
	int ele = n;
	int size = n;
	
	for(int i=1;i<=n;i++){
		for(int j=size;j>=1;j--){
			cout << ele << " ";
		}
		cout << endl;
		ele--;
		size--;
	}
}
