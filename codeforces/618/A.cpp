#include <bits/stdc++.h>
using namespace std;

vector<int> bit(int x)
{
	stack<int> st;
	while (x>0)
	{
		st.push(x%2);
		x/=2;
	}
	vector<int> res;
	while (!st.empty())
	{
		res.push_back(st.top());
		st.pop();
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	int n;
	cin>>n;
	vector<int> ans=bit(n);
	 for (int i=ans.size()-1;i>=0;i--)
	 {
		if (ans[i])
		 cout<<i+1<<" ";
	 } 
	cout<<"\n";
}
