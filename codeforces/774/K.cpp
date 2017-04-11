#include <iostream>
using namespace std;

int main ()
{
	int c,k,n,i;
	char s[100010];
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	i=1;
	while (i<n)
	{
		if ((s[i]=='a')||(s[i]=='i')||(s[i]=='u')||(s[i]=='y'))
		{
			k=1;
			c=i;
			c++;
			while (s[c]==s[i])
			{
				k++;
				s[c]='1';
				c++;
			}
			i=c;
		}
		else
		 if ((s[i]=='e')||(s[i]=='o'))
		 {
		 	k=1;
		 	c=i;
		 	c++;
		 	while (s[c]==s[i])
		 	{
		 		k++;
		 		if (k>2)
		 		 {
		 		 	s[c]='1';
		 		 	s[c-1]='1';
				  }
				c++;
			 }
			 i=c;
		 }
		 else
		  i++;
	}
	for (i=1;i<=n;i++)
	{
		if (s[i]!='1')
		 cout<<s[i];
	}
	cout<<"\n";
}
