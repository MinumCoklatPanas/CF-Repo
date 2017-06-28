#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;


int main()
{
	int i,j,k,n,sherlock[1010],moriarty[1010];
	string s1,s2;
	char salin1[1010],salin2[1010];
	bool M[1010],S[1010];
	cin>>n;
	cin>>s1;
	cin>>s2;
	for (i=1;i<=n;i++)
	{
		sherlock[i]=(int)s1[i-1]%48;
		moriarty[i]=(int)s2[i-1]%48;
	}
	sort(sherlock+1,sherlock+n+1);
	sort(moriarty+1,moriarty+n+1);
	memset(S,0,sizeof(S));
	memset(M,0,sizeof(M));
	int max_mori=0,min_sher=0;
	//cari max_mori
	for (i=1;i<=n;i++)
	{
		bool cek=true;
		for (j=1;j<=n;j++)
		{
			if (!M[j])
			{
				if (moriarty[j]>sherlock[i])
				{
					max_mori++;
					M[j]=1;
					break;
				}
			}
		}
	}
	//cari min_sherlock
	memset(S,0,sizeof(S));
	memset(M,0,sizeof(M));
	for (i=1;i<=n;i++)
	{
		bool cek=true;
		for (j=1;j<=n;j++)
		{
			if (!M[j])
			{
				if (moriarty[j]>=sherlock[i])
				{
					//cout<<moriarty[j]<<" mori\n";
					M[j]=1;
					cek=false;
					break;
				}
			}
		}
		if (cek)
		 min_sher++;
	}
	//min_sher=n-min_sher;
	cout<<min_sher<<"\n";
	cout<<max_mori<<"\n";
}
