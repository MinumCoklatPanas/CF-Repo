#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	string anss;
	for (int i=0;i<n-1;i++)
	{
		string tmp;
		tmp=s[i];
		tmp+=s[i+1];
		int cnt=0;
		for (int j=0;j<n-1;j++)
		 if (s[j]==s[i] && s[j+1]==s[i+1])
		  ++cnt;
		if (cnt>ans)
		{
			anss=tmp;
			ans=cnt;
		}
	}
	cout<<anss<<"\n";
}