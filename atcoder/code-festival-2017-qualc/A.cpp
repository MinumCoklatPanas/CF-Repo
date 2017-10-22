#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1;
	s2="AC";
	size_t a=s1.find(s2);
	cout<<(a!=string::npos ? "Yes" : "No")<<"\n";
}