#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int i,j,k,n,urutan[110],player[110],m;
	bool cek[110];
	//cout<<"yo\n";
	cin>>n>>m;
	///cout<<n<<" "<<m<<"\n";
	for (i=1;i<=m;i++)
	 cin>>urutan[i];
	memset(cek,0,sizeof(cek));
	memset(player,-1,sizeof(player));
	for (i=1;i<m;i++)
	{
		//cout<<"yo\n";
		//cout<<i<<" i\n";
		int indeks=urutan[i+1]-urutan[i];
		if (indeks<=0)
		 indeks+=n;
		if (player[urutan[i]]==-1)
		 player[urutan[i]]=indeks;
		else
		 if (player[urutan[i]]!=indeks)
		  {
		  	cout<<-1<<"\n";
		  	return 0;
		  }
		//cout<<player[urutan[i]]<<"\n";
			//cek[indeks]=1;
	}
/*	for (i=1;i<=n;i++)
	{
		if (i==n)
		 cout<<player[i]<<"\n";
		else
		 cout<<player[i]<<" ";
	}*/
	for (i=1;i<=n;i++)
	{
		if (player[i]==-1)
		 continue;
		//cout<<"yo\n";
		//cout<<i<<" i\n";
		if(!cek[player[i]])
		 cek[player[i]]=1;
		else
		 {
		 	//cout<<"yo\n";
		 	cout<<-1<<"\n";
		 	return 0;
		 	break;
		 }
	}
	for (i=1;i<=n;i++)
	{
		if (player[i]==-1)
		{
			for (j=1;j<=n;j++)
			 if (!cek[j])
			 {
			 	player[i]=j;
			 	cek[j]=1;
			 	break;
			 }
		}
	}
	for (i=1;i<=n;i++)
	{
		if (i==n)
		 cout<<player[i]<<"\n";
		else
		 cout<<player[i]<<" ";
	}
}
