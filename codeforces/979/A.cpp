#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	++n;
	if (n==1)
	 cout<<"0\n";
	else
	 cout<<(n%2==0 ? n/2 : n)<<"\n";
}
