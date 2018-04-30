#include <bits/stdc++.h>
using namespace std;

const
 int MOD=1e9+7;

int DP[3][110][110];

int main()
{
	int n,k,d;
	cin>>n>>k>>d;
	for (int i=1;i<=k;i++)
	{
		if (i>=d)
		 DP[1][i][i]=1;
		else
		 DP[0][i][i]=1;
		DP[2][i][i]=DP[1][i][i]+DP[0][i][i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			int sisa=i-j;
			if (sisa>0)
			{
				for (int l=1;l<=k;l++)
				{
					if (j<d)
					{
						if (l<d)
						{
							DP[0][j][i]+=DP[0][l][sisa];
							DP[0][j][i]%=MOD;
							DP[1][j][i]+=DP[1][l][sisa];
							DP[1][j][i]%=MOD;
						}
						else
						 {
						 	DP[1][j][i]+=DP[2][l][sisa];
						 	DP[1][j][i]%=MOD;
						 }
					}
					else
					 {
					 	DP[1][j][i]+=DP[2][l][sisa];
					 	DP[1][j][i]%=MOD;
					 }
				}
			}
			DP[2][j][i]=DP[0][j][i]+DP[1][j][i];
			DP[2][j][i]%=MOD;
		}
	}
	int ans=0;
	for (int i=1;i<=k;i++)
	{
		ans+=DP[1][i][n];
		ans%=MOD;
	}
	cout<<ans<<"\n";
}
