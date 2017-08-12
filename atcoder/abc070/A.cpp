#include <iostream>
#include <string>
using namespace std;

void cek(string s)
{
	int l=0;
	int r=s.length()-1;
	while (l<=r)
	{
		if (s[l]!=s[r])
		{
			cout<<"No\n";
			return;
		}
		l++;
		r--;
	}
	cout<<"Yes\n";
	return;
}

int main()
{
	string a;
	cin>>a;
	cek(a);
}