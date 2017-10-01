#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	string s;
	int sf=0,fs=0;
	cin>>n;
	cin>>s;
	for (i=0;i<n;i++)
	{
		if (s[i]=='S')
		{
			if (s[i+1]=='F') 
			 sf++;
		}
		else
		 if (s[i]=='F')
		 {
		 	if (s[i+1]=='S')
		 	 fs++;
		 }
	}
	cout<<(sf>fs ? "YES\n" : "NO\n");
}
