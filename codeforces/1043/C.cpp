#include <bits/stdc++.h>
using namespace std;

bool flip[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	// string ans;
	// ans="z";
	// int pan=(int)s.length();
	// for (int i=0;i<(1<<pan);i++)
	// {
	// 	string tmp=s;
	// 	cout<<i<<" i\n";
	// 	for (int j=0;j<pan;j++)
	// 	{
	// 		if (i&(1<<j))
	// 			{
	// 				cout<<j<<" j\n";
	// 				reverse(tmp.begin(),tmp.begin()+j+1);
	// 				cout<<tmp<<" tmp\n";
	// 			}
	// 	}
	// 	// cout<<i<<" i\n";
	// 	cout<<tmp<<" tmp\n";
	// 	ans=min(ans,tmp);
	// }
	// cout<<ans<<"\n";
	// return 0;
	int range=1;
	int l=-1,r=-1;
	int i=0;
	while (i<s.length())
	{
		// int cnt=0;
		int L=i;
		bool ya=false;
		while ((s[i]=='a') && (i<s.length()))
		{
			++i;
			ya=true;
		}
		// cout<<ya<<"\n";
		int R=i;
		// if (ya)
		// 	cout<<L<<" "<<R<<"\n";
		int len=R-L;
		if (ya)
		{
			if (L!=0)
			{
				flip[L-1]=1;
			}
			flip[R-1]=1;
		}
		++i;
	}
	// if (l!=-1)
	//  {
	//  	flip[r-1]=1;
	//  	if ((s[0]=='a') && (l>0))
	//  		 flip[l-1]=1;
	//  }
	for (int i=0;i<s.length();i++)
	{
		if (i==0)
			 cout<<flip[i];
		else
			 cout<<" "<<flip[i];
	}
	cout<<"\n";
}