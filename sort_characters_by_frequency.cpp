#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s) {
    unordered_map<char,int> mp;
    for(auto x:s){
        mp[x]++;
    }

    priority_queue<pair<int,char>> pq;
    for(auto x:mp){
        pq.push({x.second,x.first});
    }
    string res="";
    while(!pq.empty()){
        res=res+string((pq.top()).first,(pq.top()).second);
        pq.pop();
    }
    return res;
}
int main(){
    string s;
    getline(cin,s);
    cout<<frequencySort(s);
}