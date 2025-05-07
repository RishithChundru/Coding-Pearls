#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> heap;
    void heapifyUp(int i){
        while(i>0 && heap[i]>heap[(i-1)/2]){
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    void heapifyDown(int i){
        int n=heap.size();
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && heap[left]>heap[largest]) largest=left;
        if(right<n && heap[right]>heap[largest]) largest=right;

        if(largest!=i){
            swap(heap[i],heap[largest]);
            heapifyDown(largest);
        }
    }
    public:
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    int extractMax(){
        int maxval=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxval;
    }
    void print(){
        for(int val:heap) cout<<val<<" ";
        cout<<endl;
    }
};
int main(){
    int n;
    cin>>n;
    MaxHeap h;

    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        h.insert(x);
    }
    cout<<"Max heap: ";
    h.print();
    cout<<"Extracted Max: "<<h.extractMax()<<endl;
    cout<<"After Extraction: ";
    h.print();
    return 0;

}