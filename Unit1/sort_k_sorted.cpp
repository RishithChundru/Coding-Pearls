#include<bits/stdc++.h>
using namespace std;
void sortKSorted(vector<int> &arr, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    int idx=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            arr[idx++]=pq.top();
            pq.pop();
        }
    }
    while(!pq.empty()){
        arr[idx++]=pq.top();
        pq.pop();
    }
}
int main(){
    int n,k;
    cout<<"Enter no of elements: ";
    cin>>n;
    vector<int> arr(n);

    for(int &x:arr){
        cin>>x;
    }
    cout<<"Enter k: ";
    cin>>k;
    sortKSorted(arr,k);
    cout<<"Sorted Array: ";
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
    return 0;
}