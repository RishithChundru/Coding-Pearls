#include<bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> &arr,int k){
    priority_queue<int,vector<int> , greater<int>> minHeap;
    for(int i:arr){
        minHeap.push(i);
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    return minHeap.top();
}
int main(){
    int n,k;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int &x:arr){
        cin>>x;
    }
    cout<<"Enter k: ";
    cin>>k;
    cout<<k<<"th largest element: "<<kthLargest(arr,k)<<endl;
    return 0;
}