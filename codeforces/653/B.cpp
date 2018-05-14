#include <bits/stdc++.h>
using namespace std;

int DP[10][10];

int get(char a)
{
	return a-'a'+1;
}

vector<int> depan[10];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		depan[get(b[0])].push_back(get(a[0]));
		DP[2][get(b[0])]++;
	}
//	for (int i=1;i<=6;i++)
//	 cout<<DP[2][i]<<" ";
//	cout<<"\n";
	for (int i=3;i<=n;i++)
	{
	 for (int j=1;j<=6;j++)
	 {
	 	for (int k=0;k<depan[j].size();k++)
	 	{
	 		DP[i][j]+=DP[i-1][depan[j][k]];
		}
	 }
//	 for (int j=1;j<=6;j++)
//	  cout<<DP[i][j]<<" ";
//	 cout<<"\n";
	}
	cout<<DP[n][1]<<"\n";
}
