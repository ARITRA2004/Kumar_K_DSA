#include <bits/stdc++.h>
using namespace std;

// this is an O(N) solution
/*
int main() {
	vector<int>v = {3,5,4,8,1};
	sort(v.begin(),v.end());
	
	int first = 0;
	int last = v.size()-1;
	int k = 6;
	int count = 0;
	
	//1,3,4,5,8
	//0,1,2,3,4
	
// 	doubltes are -> [1,8],[3,8],[4,8],[5,8],[3,5],[4,5],[3,4]
	// i have to count the dobulets which will be a[i] + a[j] > k , i < j
	
	while(first < last){
	    
	    if(v[first] + v[last] > k){
	        count = count + (last - first);
	        last--;
	    }
	    else first++;
	}
	
	cout << count;
	
	return 0;

}

*/

// now we will find the 4pairs where Problem :-> Given a sorted array of size N; find the number of quadruplets (i,j,k,l) such that -> a[i] + a[j] > k1 && a[k] + a[l] > k2  

// -> Will i < j < k < l -> Yes; 

// -> What is the nature of numbers in the array -> Both positive / negative ; 

// -> Bound on array elements and k1,k2 -> abs(a[i],k1,k2)<=100000000;

// Input -> [1,1,1,1,2,2] k1=1 k2 = 3;
// -> 6 [1,2,5,6],[2,3,5,6],[3,4,5,6],[1,4,5,6],[1,3,5,6],[2,4,5,6];



// k1 = 1 and k2 = 3, a[i] + a[j] > k1 and a[k] + a[l] > k2
// 1  1  1  1  2  2   
// 0  1  2  3  4  5

// j = 1    k = 2
// i = 0    l = n   -> 
// 


#include <bits/stdc++.h>
using namespace std;

int main(){
                //  0 1 2 3 4 5
    vector<int>v = {1,1,1,1,2,2};
    //[1,2,5,6],[2,3,5,6],[3,4,5,6],[1,4,5,6],[1,3,5,6],[2,4,5,6];
    //[0,1,4,5],[1,2,4,5],[2,3,4,5],[0,3,4,5],[0,2,4,5],[1,3,4,5];
    
    sort(v.begin(),v.end());
    
    int n = v.size();
    //n = 6
    // n-3 = 3
    int k1 = 1;
    int k2 = 3;
    int c = 0;
    int c1 = 0;
    int c2;
    
    for(int j=1;j<=n-3;j++){
        
        int i = j-1;c1 = 0; 
        
        while(i >= 0){
            if(v[i] + v[j] > k1){
                c1++;
            }
            i--;
        }
        
        c2 = 0;
        int k = j+1;
        int l = n-1;
        
        while(k<l){
            if((v[k]+v[l])>k2){
                c2 = c2 + (l-k);
                l--;
            }else{
                k++;
            }
        }
        c += c1*c2;
    }
    
    cout << c;
    
    return 0;
}


