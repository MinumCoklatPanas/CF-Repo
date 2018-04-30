#include <bits/stdc++.h>
using namespace std;

int tab[310][310];
int k;
int N,M;
int sisa;
vector< pair<int,int> > ans[50010];

pair<int,int> dfs(int r,int c,int st,int cnt)
{
	ans[st].push_back({r,c});
	if (st!=k)
	{
		if (cnt==2) return {r,c};
		if (r%2==1)
		 {
		 	if (c<M)
		 	 return dfs(r,c+1,st,++cnt);
		 	else
		 	 return dfs(r+1,c,st,++cnt);
		 }
		else
		 {
		 	if (c>1)
		 	 return dfs(r,c-1,st,++cnt);
		 	else
		 	 return dfs(r+1,c,st,++cnt);
		 }
	}
	else
	 {
	 	if (cnt==sisa) return {r,c};
	 	if (r%2==1)
		 {
		 	if (c<M)
		 	 return dfs(r,c+1,st,++cnt);
		 	else
		 	 return dfs(r+1,c,st,++cnt);
		 }
		else
		 {
		 	if (c>1)
		 	 return dfs(r,c-1,st,++cnt);
		 	else
		 	 return dfs(r+1,c,st,++cnt);
		 }
	 }
}

int main()
{
	cin>>N>>M>>k;
	int lastX=1,lastY=1;
	sisa=N*M;
	for (int i=1;i<=k;i++)
	{
		pair<int,int> last=dfs(lastX,lastY,i,1);
		lastX=last.first;
		lastY=last.second;
		if (lastX%2==1)
		{
			if (lastY<M)
			 ++lastY;
			else
			 ++lastX;
		}
		else
		{
			if (lastY>1)
			 --lastY;
			else
			 ++lastX;
		}
		sisa-=2;
//		cout<<lastX<<" "<<lastY<<"\n";
	}
//	for (int i=1;i<=N;i++)
//	 {
//	 	for (int j=1;j<=M;j++)
//	 	{
//	 		if (j==M)
//	 		 cout<<tab[i][j]<<"\n";
//	 		else
//	 		 cout<<tab[i][j]<<" ";
//		 }
//	 }
//	for (int i=1;i<=N;i++)
//	 for (int j=1;j<=M;j++)
//	 {
//	 	ans[tab[i][j]].push_back({i,j});
//	 }
	for (int i=1;i<=k;i++)
	{
		cout<<ans[i].size()<<" ";
		for (int j=0;j<ans[i].size();j++)
		{
			if (j==ans[i].size()-1)
			 cout<<ans[i][j].first<<" "<<ans[i][j].second<<"\n";
			else
			 cout<<ans[i][j].first<<" "<<ans[i][j].second<<" ";
		}
	}
}
