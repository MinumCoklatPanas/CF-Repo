#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i;string s1,s2,hasil="";
	bool b=true;
	cin>>s1;
	cin>>s2;
	for (i=0;i<=s1.length()-1;i++)
	{
		if (s2[i]>s1[i])
		 {
		 	//cout<<"case1\n";
		 	hasil="-1";
		 	b=false;
		 	cout<<hasil<<"\n";
		 	break;
		 }
		else
		 if (s2[i]==s1[i])
		 {
		 	//cout<<"case2\n";
		 	int k;
		 	k= (int) s2[i];
		 	char ch;
		 	ch = (char) k;
		 	hasil=hasil+ch;
		 }
		else
		 if (s2[i]<s1[i])
		  {
		  	//cout<<"case3\n";
		  	hasil=hasil+s2[i];
		  }
	}
	if (b)
	 cout<<hasil<<"\n";
}
