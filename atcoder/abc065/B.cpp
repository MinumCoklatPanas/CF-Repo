#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int i,j,k,n,tab[100010];
	bool cek[100010];
	memset(cek,0,sizeof(cek));
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	if (1==tab[tab[1]])
	{
		if (tab[1]==2)
		 {
		 	cout<<1<<"\n";
		 	return 0;
		 }
		else 
		 {
		 	cout<<-1<<"\n";
		 	return 0;
		 }
	}
	else
	 {
	 	int now=1;
	 	int count=0;
	 	while (1)
	 	{
	 		memset(cek,0,sizeof(cek));
	 		count++;
	 		cek[tab[now]]=1;
	 		now=tab[now];
	 		if (count>=n)
	 		{
	 			cout<<-1<<"\n";
	 			return 0; 
			}
			if (cek[2])
			{
				cout<<count<<"\n";
				return 0;
			}
		}
	 }
}