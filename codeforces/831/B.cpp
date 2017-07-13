#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int i,j,k,n;
	map<char,char> mp;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	for (i=0;i<s1.length();i++)
	{
		mp[s1[i]]=s2[i];
	}
	string s3;
	cin>>s3;
	for (i=0;i<s3.length();i++)
	{
		char ans;
		char now=s3[i];
		int asc=(int) now;
		if (48<= asc && asc<=57)
		 ans=now;
		else
		 {
		 	if (65<=asc && asc<=90)
		 	{
		 		//cout<<now<<" huruf\n";
		 		asc+=32;
		 		now=(int)asc;
		 		//cout<<now<<" after\n";
		 		now=mp[now];
		 		asc=(int)now;
		 		asc-=32;
		 		//cout<<now<<" now\n";
		 		//asc=(int)now;
		 		//cout<<asc<<" asc bef\n";
		 		//asc+=32;
		 		//cout<<asc<<" asc aft\n";
		 		ans=(char)asc;
			}
			else
			 {
			 	ans=mp[now];
			 }
		 }
		 if (i==s3.length()-1)
		 {
		 	cout<<ans<<"\n";
		 }
		 else
		  cout<<ans;
	}
}
