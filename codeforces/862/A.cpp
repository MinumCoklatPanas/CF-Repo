#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n,x;
	bool cek[110];
	memset(cek,0,sizeof(cek));
	cin>>n>>x;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		cek[k]=1;
	}
	int sum=0;
	for (i=0;i<=x;i++)
	{
	//	cout<<i<<" i\n";
		if (i==x)
		 {
		 	if (cek[i])
		 	 sum++;
		 }
		else
		 if (!cek[i])
		  sum++;
	//	cout<<sum<<"\n";
	}
	cout<<sum<<"\n";
}
