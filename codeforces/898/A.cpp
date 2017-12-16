#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	if (n%10<=5)
	cout<<(n/10)*10<<"\n";
	else
	cout<<((n/10)+1)*10<<"\n";
}
