#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int i,j,k,n,m;
	char tab[110][110];
	map <char,int> mp;
	mp['R']=0;
	mp['G']=0;
	mp['B']=0;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++)
	  cin>>tab[i][j];
	if (n%3!=0 && m%3!=0)
	{
		cout<<"NO\n";
		return 0;
	}
	bool cek1,cek2;
	//if (tab[1][2]==tab[1][1])
		cek1=true;
		i=1;
		while (i<=n)
		{
			int hitung=0;
			int start=i;
			if (!mp[tab[i][1]])
			{
				char patokan=tab[i][1];
				for (int j=1;j<=m;j++)
				{
					if (tab[i][j]!=patokan)
					{
						cek1=false;
						break;
					}
				}
				while (tab[i][1]==patokan && i<=n)
				{
					i++;
					hitung++;
				}
				for (int row=start;row<i;row++)
				 for (int column=1;column<=m;column++)
				 {
				 	if (tab[row][column]!=patokan)
				 	{
				 		cek1=false;
				 		break;
					 }
				 }
				mp[patokan]=hitung;
			}
			else
			 {
			 	//cout<<"yo\n";
			 	cek1=false;
			 	break;
			 }
		}
	if (mp['R']!=mp['G'] || mp['R']!=mp['B'] || mp['G']!=mp['B'])
	 cek1=false;
	//else
	 //{
	mp['R']=0;
	mp['G']=0;
	mp['B']=0;
	cek2=true;
	 	i=1;
		while (i<=m)
		{
			int hitung=0;
			int start =i;
			if (!mp[tab[1][i]])
			{
				char patokan=tab[1][i];
				for (int j=1;j<=n;j++)
				{
					if (tab[j][i]!=patokan)
					{
						cek2=false;
						break;
					}
				}
				while (tab[1][i]==patokan && i<=m)
				{
					i++;
					hitung++;
				}
				for (int row=1;row<=n;row++)
				 for (int column=start;column<i;column++)
				 {
				 	if (tab[row][column]!=patokan)
				 	{
				 		cek2=false;
				 		break;
					 }
				 }
				mp[patokan]=hitung;
			}
			else
			 {
			 	cek2=false;
			 	break;
			 }
		}
	 //}
	if (mp['R']!=mp['G'] || mp['R']!=mp['B'] || mp['G']!=mp['B'])
	{
		cek2=false;
	}
	if (cek1 || cek2) 
	 cout<<"YES\n";
	else
	 cout<<"NO\n";
}
