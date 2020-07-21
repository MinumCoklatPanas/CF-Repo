#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	vector<int> frek[30];
	memset(frek,0,sizeof(frek));
	for (int i=0;i<s.length();i++)
	{
		int asc=(int)s[i];
		asc-=96;
		frek[asc].push_back(i);
	}
	bool satu_semua=true;
	for (int i=1;i<=26;i++)
	{
		if (frek[i].size()>1)
		{
			satu_semua=false;
			break;
		}
	}
	if (satu_semua)
	 cout<<(s.length()/2)+1<<"\n";
	else
	 {
	 	int ans=(s.length()/2)+1;
	 	for (int i=1;i<=26;i++)
	 	{
	 		if (frek[i].size()<=1) continue;
	 		int mn=frek[i][0] + 1;
//	 	int diff=frek[i][0]-1;
	 		for (int j=0;j<frek[i].size()-1;j++)
	 		{
	 			int diff=frek[i][j+1]-frek[i][j];
	 			mn=max(diff,mn);
			}
			int diff=s.length()-frek[i][frek[i].size()-1];
			mn=max(diff,mn);
			ans=min(ans,mn);
		}
		cout<<ans<<"\n";
	 }
}