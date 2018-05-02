#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if (s=="0")
	 cout<<s<<"\n";
	else
	 {
	 	int nol=0;
	 	for (int i=0;i<n;i++)
	 	 nol+=s[i]=='0';
	 	cout<<1;
	 	for (int i=1;i<=nol;i++)
	 	 cout<<0;
	 	cout<<"\n";
	 }
}
