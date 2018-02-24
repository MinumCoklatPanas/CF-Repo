#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	int ans=0;
	int sum=s[0]-'0';
	ans+=s[0]-'0'-1;
	for (int i=1;i<s.length();i++)
	 {
	 	ans+=9;
	 	sum+=s[i]-'0';
	 }
	cout<<max(ans,sum)<<"\n";
}