#include <iostream>
#include <string>
using namespace std;

int main ()
{
	int i,hasil=0;
	string s;
	cin>>s;
	for (i=0;i<=s.length()-1;i++)
	{
		if (s[i]=='V')
		 {
		 	if ((s[i+1]=='V')&&(s[i+2]!='K'))
		 	{
		 		s[i+1]='K';
		 		break;
			 }
		 	
		 }
		else
		 if (s[i]=='K')
		 {
		 	if ((s[i-1]=='K')&&(s[i-2]!='V'))
		 	{
		 		s[i-1]='V';
		 		break;
			 }
		 }
	}
	//cout<<s<<"\n";
	for (i=0;i<=s.length()-1;i++)
	{
		if (s[i]=='V')
		{
			if (s[i+1]=='K')
			 hasil++;
		}
	}
	cout<<hasil<<"\n";
}
