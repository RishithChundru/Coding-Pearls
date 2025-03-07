#include<bits/stdc++.h>

using namespace std;

class DSU{
	vector<int> parent;
	
	public:
		DSU(int n)
		{
			parent.resize(n,-1);
		}
		
		int find(int x)
		{
			if(parent[x]<0)
			return x;
			
			return parent[x] = find(parent[x]);
		}
		
		void unite(int x,int y)
		{
			int parentX = find(x);
			int parentY = find(y);
			
			if(parentX==parentY)
			return;
			
			if(parent[parentX] <= parent[parentY])
			{
				parent[parentX]+=parent[parentY];
				parent[parentY]=parentX;
			}
			else
			{
				parent[parentY]+=parent[parentX];
				parent[parentX]=parentY;
			}
		}
		
		bool isSameSet(int i,int j)
		{
			return find(i)==find(j);
		}
};

int main()
{
	DSU d1(8);
	
	d1.unite(0,1);
	d1.unite(1,2);
	d1.unite(2,3);
	d1.unite(2,4);
	d1.unite(5,6);
	d1.unite(6,7);
	
	cout<<(d1.isSameSet(5,7));
}