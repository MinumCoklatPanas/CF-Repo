#include <bits/stdc++.h>
using namespace std;

map<string,string> mp;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s2]=s1;
	}
	for (int i=1;i<=m;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		string s3=s2;
		s3=s3.erase(s2.length()-1,1);
		cout<<s1<<" "<<s2<<" "<<"#"<<mp[s3]<<"\n";
	}
}
