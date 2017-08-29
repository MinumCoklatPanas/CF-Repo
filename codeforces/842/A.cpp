#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long i,j,k,n,l,r,x,y;
bool cek[10000010];

int main()
{
	cin>>l>>r>>x>>y>>k;
	for (i=l;i<=r;i++)
	 cek[i]=1;
	for (i=x;i<=y;i++)
	{
		if (i*k<=10000000)
		 {
		 	if (cek[i*k])
		 	{
		 		cout<<"YES\n";
		 		return 0;
			 }
		 }
	}
	cout<<"NO\n";
	return 0;
}
