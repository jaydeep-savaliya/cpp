#include <bits/stdc++.h>
using namespace std;
long long totalCost(vector<int> &costs,int k,int candidates){
    int i = 0;
    int j = costs.size()-1;
    priority_queue<int,vector<int>,greater<int>> pq1,pq2;
    long long ans = 0;
    while(k--){
        while(pq1.size()<candidates && i<=j){
            pq1.push(costs[i++]);
        }
        while(pq2.size()<candidates && i<=j){
            pq2.push(costs[j--]);        
        }
        int a = pq1.size()>0?pq1.top():INT_MAX;
        int b = pq2.size()>0?pq2.top():INT_MAX;
        if(a<=b){
            ans+=a;
            pq1.pop();
        }else{
            ans+=b;
            pq2.pop();
        }
    }
    return ans;
}
int main(){
    vector<int> costs{17,12,10,2,7,2,11,20,8};
    int k = 3;
    int candidates = 4;
    long long ans = totalCost(costs,k,candidates);
    cout<<ans;
}