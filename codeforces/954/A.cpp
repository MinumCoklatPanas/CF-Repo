#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i=0;
	int kurang=0;
	while (i<n)
	{
		if (s[i]=='U' && s[i+1]=='R' && i<s.length()-1)
		 {
		 	++kurang;
		 	i+=2;
		 }
		else
		 if (s[i]=='R' && s[i+1]=='U' && i<s.length()-1)
		 {
		 	++kurang;
		 	i+=2;
		 }
		else
		 ++i;
	}
	cout<<n-kurang<<"\n";
}
