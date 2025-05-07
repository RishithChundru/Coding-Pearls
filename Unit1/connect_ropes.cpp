#include<bits/stdc++.h>
using namespace std;
int minConnectRopes(vector<int> &ropes){
    priority_queue<int,vector<int>,greater<int>> pq(ropes.begin(),ropes.end());
    int cost=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        cost+=first+second;
        pq.push(first+second);
    }
    return cost;
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> ropes(n);
    for(int &x:ropes){
        cin>>x;
    }
    cout<<"Minimum cost to connect ropes: "<<minConnectRopes(ropes)<<endl;
}