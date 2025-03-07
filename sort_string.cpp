#include <bits/stdc++.h>
using namespace std;

template <class T>
class MaxPQ {
    vector<T> maxpq;

public:
    void heapify(int i) {
        int largest = i;
        int l = i * 2 + 1;
        int r = i * 2 + 2;

        if (l < maxpq.size() && maxpq[largest] < maxpq[l]) {
            largest = l;
        }
        if (r < maxpq.size() && maxpq[largest] < maxpq[r]) {
            largest = r;
        }

        if (i != largest) {
            swap(maxpq[i], maxpq[largest]);
            heapify(largest);
        }
    }

    bool empty() {
        return maxpq.empty();
    }

    T top() {
        return maxpq[0];
    }

    void pop() {
        if (maxpq.size() == 1) {
            maxpq.pop_back();
            return;
        }
        maxpq[0] = maxpq[maxpq.size() - 1];
        maxpq.pop_back();
        heapify(0);
    }

    void push(T x) {
        maxpq.push_back(x);
        if (maxpq.size() == 1) {
            return;
        }

        int i = maxpq.size() - 1;

        while (i != 0) {
            int parent = (i - 1) / 2;
            if (maxpq[i] > maxpq[parent]) {
                swap(maxpq[i], maxpq[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }
};

string sortString(string s) {
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }

    MaxPQ<pair<int, char>> pq;
    for (auto x : mp) {
        pq.push({x.second, x.first});
    }

    string ans = "";
    while (!pq.empty()) {
        ans += string((pq.top()).first, (pq.top()).second);
        pq.pop();
    }
    
    return ans;
}

int main() {
    string s = "aaaaaaaabbbbccccccccccdddddddddddddddddddddeee";
    cout << sortString(s);
    return 0; 
}


/*
template<class T> class MaxPQ{
	vector<T> maxpq;
	
	public:
		
		void heapify(int i)
		{
			int largest = i;
			
			int l = i*2+1;
			int r = i*2+2;
			
			if(l<maxpq.size() && maxpq[largest]<maxpq[l])
			largest = l;
			
			if(r<maxpq.size() && maxpq[largest]<maxpq[r])                       
			largest = r;
			
			if(i!=largest)
			{
				swap(maxpq[i],maxpq[largest]);
				heapify(largest);
			}
		}
		
		bool empty()
		{
			return maxpq.empty();
		}
		
		T top()
		{
			return maxpq[0];
		}
		
		void pop()
		{
			if(maxpq.size()==1)
            {
                maxpq.pop_back();
                return;
            }
			
			maxpq[0] = maxpq[maxpq.size()-1];
			maxpq.pop_back();
			heapify(0);			
		}
		
		void push(T x){
			
			maxpq.push_back(x);
			
			if(maxpq.size()==1)
			return;
			
			int i = maxpq.size()-1;
			
			while(i!=0)
			{
				int parent = (i-1)/2;
				
				if(maxpq[i] > maxpq[parent])
				{
					swap(maxpq[i],maxpq[parent]);
					
					i = parent;
				}
				else
				break;
			}
		}
};


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> f;
	
	for(char c : s)
	{
		f[c]++;
	}
	
	MaxPQ<pair<int,char>> pq;
	
	for(auto x : f)
	{
		pq.push({x.second,x.first});
	}
	
	string ans = "";
	
	while(!pq.empty())
	{
		ans = ans + string((pq.top()).first,(pq.top()).second);
		pq.pop();
	}
	
	return ans;	

    }
};

*/
