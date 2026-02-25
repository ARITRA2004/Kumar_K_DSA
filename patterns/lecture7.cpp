#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int space = 1;
	
	for(int i=1;i<=n;i++){
		
		// for space print
		if(i > 1){
			for(int k=1;k<space;k++) cout << " ";
		}
		
		for(int j=1;j<=n;j++){
			cout << "*";
		}
		cout << endl;
		space++;
	}
}
