#include<bits/stdc++.h>
using namespace std;

void printArrayHeap(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<"Node: "<<arr[i];
        if(2*i+1<n) cout<<", Left Child: "<<arr[2*i+1];
        if(2*i+2<n) cout<<", Right Child: "<<arr[2*i+2];
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> heap(n);
    cout<<"Enter elements: ";
    for(int &x: heap) cin>>x;
    printArrayHeap(heap);
}