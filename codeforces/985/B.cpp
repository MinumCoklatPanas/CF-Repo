#include <bits/stdc++.h>
using namespace std;

vector<int> tombol[2010];
char tab[2010][2010];

int main()
{
//	freopen("input.txt","r",stdin);
	int N,M;
	cin>>N>>M;
	for (int i=1;i<=N;i++)
	 for (int j=1;j<=M;j++)
	 {
	 	cin>>tab[i][j];
	 	if (tab[i][j]=='1')
	 	{
	 		tombol[j].push_back(i);
		}
	 }
	for (int i=1;i<=N;i++)
	 {
	 	bool bisa=true;
	 	for (int j=1;j<=M;j++)
	 	{
	 		if (tab[i][j]=='1')
	 		{
	 			if (tombol[j].size()==1)
	 			{
	 				bisa=false;
	 				break;
				}
			}
		}
		if (bisa)
		{
			cout<<"YES\n";
			return 0;
		}
	 }
	cout<<"NO\n";
}
