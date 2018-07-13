#include <bits/stdc++.h>
using namespace std;

bool con(char x)
{
	return ((x=='a') || (x=='i') || (x=='u') || (x=='e') || (x=='o'));
}

int main()
{
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		if (!con(s[i]) && s[i]!='n' && i!=s.length()-1)
		{
			if (!con(s[i+1]))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else
		 if (!con(s[i]) && i==s.length()-1 && s[i]!='n')
		 {
		 	cout<<"NO\n";
		 	return 0;
		 }
	}
	cout<<"YES\n";
}