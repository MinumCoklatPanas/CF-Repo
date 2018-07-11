#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	string s1,s2;
	cin>>s1>>s2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
//	cout<<s1<<" "<<s2<<"\n";
	int mn=min(s1.length(),s2.length());
	int i=0;
	while (s1[i]==s2[i] && i<mn)
	 ++i;
//	cout<<i<<" i\n";
	int ans=s1.length()+s2.length()-2*i;
	cout<<ans<<"\n";
}