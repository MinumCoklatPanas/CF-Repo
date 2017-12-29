#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
//	bool ada=false;
//	int huruf=0;
	int buka=0;
	for (int i=0;i<s.length();i++)
	{
		int asc=(int)s[i];
//		cout<<s[i]<<" "<<asc<<"\n";
		if (s[i]=='a' || s[i]=='i' || s[i]=='e' || s[i]=='u' || s[i]=='o')
		 ++buka;
		if (48<=asc && asc<=57)
		{
//			cout<<s[i]<<"\n";
			asc-=48;
			buka+=asc%2;
		}
		 
	}
	cout<<buka<<"\n";
}
