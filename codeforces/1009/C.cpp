#include <bits/stdc++.h>
using namespace std;

double x[100010];
double d[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	double n,m;
	cin>>n>>m;
	double sum=0.0;
	for (int i=1;i<=m;i++)
	{
		cin>>x[i]>>d[i];
		sum+=n*x[i];
	}
	double tengah=(n+1)/2.0;
	double mid=0.0;
	double ujung=0.0;
	for (int i=1;i<=n;i++)
	 {
	 	mid+=fabs(i-tengah);
	 	ujung+=i*1.0;
	 }
	ujung-=n;
	for (int i=1;i<=m;i++)
	{
		if (d[i]<0)
		 sum+=mid*d[i];
		else
		 sum+=ujung*d[i];
	}
	double rata=sum/n;
	printf("%.13lf\n",rata);
}