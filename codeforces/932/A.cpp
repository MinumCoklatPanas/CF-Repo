#include <bits/stdc++.h>
using namespace std;

bool palindrome(string a)
{
	int l=0;
	int r=a.length()-1;
	while (l<r)
	{
		if (a[l]!=a[r]) return false;
		++l;
		--r;
	}
	return true;
}

int main()
{
	string s;
	cin>>s;
	if (palindrome(s))
	 cout<<s<<"\n";
	else
	 {
	 	cout<<s;
	 	for (int i=s.length()-2;i>=0;i--)
	 	 cout<<s[i];
	 	cout<<"\n";
	 }
}
