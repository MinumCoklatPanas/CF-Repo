#include <bits/stdc++.h>
using namespace std;

int dx[3]={1,0,-1};
int dy[3]={1,0,-1};


int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int tab[100010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	int ans=-1;
	for (int i=0;i<3;i++)
	 for (int j=0;j<3;j++)
	 {
	 	int cnt=0;
	 	cnt+=(dx[i]!=0);
	 	cnt+=(dy[j]!=0);
	 	bool bisa=true;
	 	int last=tab[2]+dy[j];
	 	int beda=(tab[2]+dy[j])-(tab[1]+dx[i]);
//	 	cout<<dx[i]<<" "<<dy[j]<<" "<<beda<<"\n";
	 	for (int k=3;k<=n;k++)
	 	{
	 		int diff=tab[k]-last;
//	 		cout<<k<<" "<<diff<<" diff\n";
	 		if (abs(diff-beda)>1)
	 		{
//	 			cout<<abs(diff-beda)<<" abs\n";
//	 			cout<<k<<" k\n";
	 			bisa=false;
	 			break;
			}
			if (diff==beda)
			{
//				cout<<k<<" k\n";
				last=tab[k];
				continue;
			}
			else
			{
				++cnt;
				if (tab[k]>last)
				{
					if (diff>beda)
					{
						last=tab[k]-1;
					}
					else
					{
						last=tab[k]+1;
					}
				}
				else
				{
					if (diff<beda)
					{
						last=tab[k]+1;
					}
					else
					{
						last=tab[k]-1;
					}
				}
			}
		}
		if (bisa)
		{
			if (ans==-1)
			 ans=cnt;
			else
			 ans=min(ans,cnt);
		}
	 }
	cout<<ans<<"\n";
}
