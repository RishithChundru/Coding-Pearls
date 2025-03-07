#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr,int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(i!=largest){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
int main(){
    vector<int> arr={12,7,9,23,5,19,27,47,97};
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}