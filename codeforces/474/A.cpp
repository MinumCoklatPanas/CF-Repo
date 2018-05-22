#include <bits/stdc++.h>
using namespace std;


int main()
{
	
//	freopen("input.txt","r",stdin);
	string tab[3]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
	char dir;
	cin>>dir;
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		for (int j=0;j<3;j++)
		 for (int k=0;k<tab[j].length();k++)
		  {
		  	if (tab[j][k]==s[i])
		  	{
		  		if (dir=='R')
		  		 s[i]=tab[j][k-1];
		  		else
		  		 s[i]=tab[j][k+1];
		  		goto hell;
			}
		  }
		hell:;
	}
	cout<<s<<"\n";
}
