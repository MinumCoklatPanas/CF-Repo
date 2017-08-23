#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,l,m,n;
	string s;
	int ans=100;
	cin>>s;
	for (i=0;i<=9;i++)
	 for (j=0;j<=9;j++)
	  for (k=0;k<=9;k++)
	   for (l=0;l<=9;l++)
	    for (m=0;m<=9;m++)
	     for (n=0;n<=9;n++)
	     {
	     	if (i+j+k!=l+m+n) continue;
	     	int sum=0;
	     	if (s[0]-'0'!=i)
	     	 sum++;
	     	if (s[1]-'0'!=j)
	     	 sum++;
	     	if (s[2]-'0'!=k)
	     	 sum++;
	     	if (s[3]-'0'!=l)
	     	 sum++;
	     	if (s[4]-'0'!=m)
	     	 sum++;
	     	if (s[5]-'0'!=n)
	     	 sum++;
	     	ans=min(ans,sum);
		 }
	cout<<ans<<"\n";
}
