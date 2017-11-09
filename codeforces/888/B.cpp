#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<char,int> mp;
	mp.clear();
	for (int i=0;i<s.length();i++)
	 mp[s[i]]++;
	int ans=0;
	ans+=min(mp['L'],mp['R'])*2;
	ans+=min(mp['D'],mp['U'])*2;
	cout<<ans<<"\n";
}
