#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 50;
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n = n/i;
            }
        }
    }
    if(n>1) ans.push_back(n);
    for(auto x:ans){
        cout<<x<<" ";
    }
}