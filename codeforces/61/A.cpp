#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	for (int i=0;i<s1.length();i++)
	{
		bool a=(s1[i]=='1');
		bool b=(s2[i]=='1');
		bool c=a^b;
		cout<<c;
	}
	cout<<"\n";
}
