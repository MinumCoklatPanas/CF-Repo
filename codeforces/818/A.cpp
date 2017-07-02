#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	long long i,j,k,n,c,d;
	cin>>n>>k;
	long long kali=k+1;
	d=(n/2)/kali;
	c=k*d;
	long long l=n-(d+c);
	cout<<d<<" "<<c<<" "<<l<<"\n";
}
