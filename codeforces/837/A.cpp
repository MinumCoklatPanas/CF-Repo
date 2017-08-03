#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int i,j,k,n;
	string s;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	int best=0;
	int count=0;
	i=0;
	while (i<n)
	{
		count=0;
		while (s[i]!=' ' && i<n)
		{
			int asc=(int)s[i];
			if (65<=asc && asc<=90)
			 count++;
			i++;
		}
		i++;
		best=max(count,best);
	}
	cout<<best<<"\n";
}
