#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int panjang=s.length();
	cout<<s[0];
	cout<<panjang-2;
	cout<<s[panjang-1]<<"\n";
}