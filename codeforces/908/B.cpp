#include <bits/stdc++.h>
using namespace std;

char asli[55][55];
char palsu[55][55];
int tab[10];
string s;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  cin>>asli[i][j];
	cin>>s;
//	cout<<s<<" s\n";
	for (int i=1;i<=4;i++)
	 {
//	 	cout<<i<<" i\n";
	 	tab[i]=i-1;
//	 	cout<<tab[i]<<"\n";
	 }
//	for (int i=1;i<=4;i++)
//		 cout<<tab[i]<<" ";
//		cout<<"\n";
	int ans=0;
	do{
//		for (int i=1;i<=4;i++)
//		 cout<<tab[i]<<" ";
//		cout<<"\n";
		pair<int,int> now;
		for (int i=1;i<=n;i++)
		 for (int j=1;j<=m;j++)
		  if (asli[i][j]=='S')
		  {
		  	now={i,j};
		  	break;
		  }
//		cout<<now.first<<now.second<<" now\n";
		bool bisa=false;
		for (int i=0;i<s.length();i++)
		{
			int dir=s[i]-'0'+1;
//			cout<<dir<<" dir\n";
			if (tab[dir]==0)
			 now.first--;
			else
			 if (tab[dir]==1)
			  now.first++;
			 else
			  if (tab[dir]==2)
			   now.second--;
			  else
			   now.second++;
			if (now.first<1) break;
			if (now.first>n) break;
			if (now.second<1) break;
			if (now.second>m) break;
			if (asli[now.first][now.second]=='#') break;
			if (asli[now.first][now.second]=='E')
			{
				bisa=true;
				break;
			}
		}
		if (bisa) ++ans;
	}while (next_permutation(tab+1,tab+5));
	cout<<ans<<"\n";
}
