#include <bits/stdc++.h>
using namespace std;

char tab[510][510];
queue< pair<int,int> > q;
bool vis[510][510];
int n,m,k,target;

void BFS(int i,int j)
{
	q.push({i,j});
	int count=1;
	while (!q.empty())
	{
		pair<int,int> depan=q.front();
		q.pop();
		int x=depan.first;
		int y=depan.second;
		vis[x][y]=1;
//		cout<<x<<" "<<y<<" "<<count<<"\n";
		if (count==target) return;
		if (!vis[x-1][y] && x>0 && tab[x-1][y]=='.')
		{
//			cout<<"yo1\n";
			q.push({x-1,y});
			vis[x-1][y]=1;
			++count;
			if (count==target) return;
		}
		if (!vis[x+1][y] && x<=n && tab[x+1][y]=='.')
		{
//			cout<<"yo2\n";
			q.push({x+1,y});
			vis[x+1][y]=1;
			++count;
			if (count==target) return;
		}
		if (!vis[x][y-1] && y>0 && tab[x][y-1]=='.')
		{
//			cout<<"yo3\n";
			q.push({x,y-1});
			vis[x][y-1]=1;
			++count;
			if (count==target) return;
		}
		if (!vis[x][y+1] && y<=m && tab[x][y+1]=='.')
		{
//			cout<<"yo4\n";
			q.push({x,y+1});
			vis[x][y+1]=1;
			++count;
			if (count==target) return;
		}
	}
	return;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	int hitung=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	cin>>tab[i][j];
	 	hitung+=(tab[i][j]=='.');
	 }
	target=hitung-k;
//	cout<<target<<" target\n";
	for (int i=1;i<=n;i++)
	 {
	 	bool sudah=false;
	 	for (int j=1;j<=m;j++)
	 	 {
	  		if (tab[i][j]=='.')
	   		{
	   			BFS(i,j);
	   			sudah=true;
	   			break;
			}
	  	}
	  	if (sudah) break;
	 }
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (tab[i][j]=='#')
	 	 cout<<tab[i][j];
	 	else
	 	 if (!vis[i][j])
	 	  cout<<"X";
		  else
		   cout<<tab[i][j];
		 if (j==m)
		  cout<<"\n";  
	 }
}
