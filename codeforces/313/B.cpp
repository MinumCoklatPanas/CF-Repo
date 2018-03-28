#include <bits/stdc++.h>
using namespace std;

int DP[2][100010];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	cin>>s;
	int len=s.length()-1;
	for (int i=1;i<=len;i++)
	{
		DP[0][i]=DP[0][i-1];
			DP[1][i]=DP[1][i-1];
		if (s[i]==s[i-1])
		{
			if (s[i]=='.')
			 DP[0][i]=DP[0][i-1]+1;
			else
			 DP[1][i]=DP[1][i-1]+1;
		}
	}
//	for (int i=0;i<=len;i++)
//	 cout<<DP[0][i]<<" ";
//	cout<<"\n";
//	for (int i=0;i<=len;i++)
//	 cout<<DP[1][i]<<" ";
//	cout<<"\n";
	int m;
	cin>>m;
	while (m--)
	{
		int l,r;
		cin>>l>>r;
		--l; --r;
		int titik=DP[0][r]-DP[0][l];
		int hestek=DP[1][r]-DP[1][l];
		cout<<titik+hestek<<"\n";
	}
}
