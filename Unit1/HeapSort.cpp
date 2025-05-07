#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}
void heapSort(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,n);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Elements: ";
    for (int& x : arr) cin >> x;
    heapSort(arr);
    cout<<"After Heap Sort: ";
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}