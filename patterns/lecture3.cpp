#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	//10
	int fst = 65+n;
	//A -> 65
	// 65+10 = 75 -> J
	
	for(int i=0;i<=10;i++){
		for(int j=fst-i;j<=fst;j++){
			char ch = j;
			cout << ch << " ";
		}
		cout << endl;
	}

	return 0;
}
