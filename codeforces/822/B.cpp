#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define INF 1e9

int main()
{
	int i,j,k,n,m,ans[1010];
	string s1,s2;
	cin>>n>>m;
	cin>>s1;
	cin>>s2;
	i=0;
	int ujung=m-1;
	int tambah=0;
	int min=INF;
	int hitung=0;
	while (i<=m-n)
	{
		//cout<<i<<" i\n";
		int dummy[1010];
		bool cek=true;
		hitung=0;
		for (j=i;j<=(n+i)-1;j++)
		{
			//cout<<s1[j+tambah]<<" "<<s2[j]<<"\n";
			if (s1[j+tambah]!=s2[j])
			{
				hitung++;
				dummy[hitung]=j+tambah+1;
			}
		}
		//cout<<hitung<<"\n";
		if (hitung<min)
		 {
		 	min=hitung;
		 	for (j=1;j<=hitung;j++)
		 	 ans[j]=dummy[j];
		 }
		i++;
		tambah--;
	}
	cout<<min<<"\n";
	for (i=1;i<=min;i++)
	{
		if (i==hitung)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
}
