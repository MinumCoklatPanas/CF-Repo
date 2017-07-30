#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	string s;
	cin>>s;
	while (s.length()<3)
	{
		s='0'+s;
	}
	cout<<"ABC"<<s<<"\n";
	return 0;
}