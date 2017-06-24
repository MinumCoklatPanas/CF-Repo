#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long i,j,k,n,m,hasil;

int main()
{
	cin>>n>>m;
	if (abs(n-m)>=2)
	 {
	 	cout<<0<<"\n";
	 	return 0;
	 }
	else
	 {
	 	long long kali=min(n,m);
	 	long long satunya=max(n,m);
	 	hasil=1;
	 	if (n==m)
	 	{
	 		long long hasil1=1;
	 		long long hasil2=1;
	 		for (i=1;i<=n;i++)
	 		{
	 			hasil1=((hasil1%1000000007)*(i%1000000007))%1000000007;
	 			hasil2=((hasil2%1000000007)*(i%1000000007))%1000000007;
			 }
			hasil=(2*(hasil1%1000000007)*(hasil2%1000000007))%1000000007;
			cout<<hasil<<"\n";
			return 0;
		 }
		else
		 {
		 	long long hasil1=1;
		 	long long hasil2=1;
		 	for (i=1;i<=satunya;i++)
		 	{
		 		if (i==satunya)
		 		 hasil1=((hasil1%1000000007)*(i%1000000007))%1000000007;
		 		else
		 		 {
		 		 	hasil1=((hasil1%1000000007)*(i%1000000007))%1000000007;
		 		 	hasil2=((hasil2%1000000007)*(i%1000000007))%1000000007;
				 }
			 }
			 hasil=((hasil1%1000000007)*(hasil2%1000000007))%1000000007;
			 cout<<hasil<<"\n";
			 return 0;
		 }
	 }
}