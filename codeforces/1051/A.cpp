#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		string s;
		cin>>s;
		int bes=0,kec=0,an=0;
		for (int i=0;i<s.length();i++)
		{
			bes+=(('A'<=s[i]) && (s[i]<='Z'));
			kec+=(('a'<=s[i]) && (s[i]<='z'));
			an+=(('0'<=s[i]) && (s[i]<='9'));
		}
//		cout<<bes<<" "<<kec<<" "<<an<<"\n";
		int ndada=((bes==0)+(kec==0)+(an==0));
		if (!ndada)
		 {
		 	cout<<s<<"\n";
		 	continue;
		 }
		else
		 if (ndada==1)
		 {
		 	if (!bes)
		 	{
		 		for (int i=0;i<s.length();i++)
		 		{
		 			if ((('a'<=s[i]) && (s[i]<='z')) && (kec>1))
		 			 {
		 			 	s[i]='A';
		 			 	break;
					  }
					if (('0'<=s[i]) && (s[i]<='9') && (an>1))
					{
						s[i]='A';
						break;
					}
		 			
				}
			}
			else
			 if (!kec)
			 {
//			 	cout<<"yo\n";
			 	for (int i=0;i<s.length();i++)
		 		{
		 			if ((('A'<=s[i]) && (s[i]<='Z')) && (bes>1))
		 			 {
		 			 	s[i]='a';
		 			 	break;
					  }
					if (('0'<=s[i]) && (s[i]<='9') && (an>1))
					{
						s[i]='a';
						break;
					}
		 			
				}
			 }
			else
			 if (!an)
			 {
			 	for (int i=0;i<s.length();i++)
		 		{
		 			if ((('a'<=s[i]) && (s[i]<='z')) && (kec>1))
		 			 {
		 			 	s[i]='0';
		 			 	break;
					  }
					if (('A'<=s[i]) && (s[i]<='Z') && (bes>1))
					{
						s[i]='0';
						break;
					}
		 			
				}
			 }
		 }
		else
		 {
		 	if (bes)
		 	{
		 		s[0]='0';
		 		s[1]='a';
			 }
			else
			 if (kec)
			 {
			 	s[0]='A';
			 	s[1]='0';
			 }
			else
			 {
			 	s[0]='a';
			 	s[1]='A';
			 }
		 }
		cout<<s<<"\n";
	}
}