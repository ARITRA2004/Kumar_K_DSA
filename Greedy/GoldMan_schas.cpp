#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>p1_male, p2_male;
    int count = 0;
    
    for(int i=0;i<n;i++){

        int x;
        cin >> x;

        if(x > 0) p1_male.push_back(x);
        else p2_male.push_back(abs(abs(x))); //stores all the negative number means they need girls less than their height -> need female
    }

    vector<int>p1_female,p2_female;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;

        if(x > 0) p1_female.push_back(x);
        else p2_female.push_back(abs(x)); // stores all the negative numbers means they need boys lesser than the girl --> need male
    }

    if(p1_male.size() > 0) sort(p1_male.begin(),p1_male.end());
    if(p2_male.size() > 0) sort(p2_male.begin(),p2_male.end());
    
    if(p1_female.size() > 0) sort(p1_female.begin(), p1_female.end());
    if(p2_female.size() > 0) sort(p2_female.begin(), p2_female.end());

    int i=0,j=0;

    while(i < p1_male.size() && j < p2_female.size()){
        if(p2_female[j] > p1_male[i]){
            count++;
            j++;
            i++;
        }
        else j++;
    }

    i=0;j=0;

    while(i < p2_male.size() && j < p1_female.size()){
        if(p2_male[i] > p1_female[j]){
            count++;
            j++;
            i++;
        }
        else{
            i++;
        }
    }

    cout << count;

    return 0;
}