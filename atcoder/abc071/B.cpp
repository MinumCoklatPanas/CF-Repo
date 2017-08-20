#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

int main()
{
	int i,j,k;
	string s;
	bool cek[30];
	memset(cek,0,sizeof(cek));
	cin>>s;
	for (i=0;i<s.length();i++)
	{
		int asc=(int)s[i];
		asc-=96;
		cek[asc]=1;
	}
	for (i=1;i<=26;i++)
	{
		if (!cek[i])
		{
			char ch=(char)i+96;
			cout<<ch<<"\n";
			return 0;
		}
	}
	cout<<"None\n";
}