#include <bits/stdc++.h>
using namespace std;

vector<int> pos[35];
int n,m,q;
string s,t;
int len;

bool cek(int x)
{
//	cout<<x<<" "<<len<<"\n";
	int now=0;
	for (int i=x;i<=x+len-1;i++)
	{
//		cout<<i<<" i\n";
//		if (i>r) return false;
		if (s[i]!=t[now]) return false;
		++now;
	}
	return 1;
}

vector<int> ok;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	cin>>s>>t;
	len=t.length();
	for (int i=0;i<n;i++)
	 pos[s[i]-'a'+1].push_back(i);
	for (int i=0;i<n;i++)
	{
		if (cek(i))
		 {
		 	ok.push_back(i);
		 }
	}
	int awal=t[0]-'a'+1;
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		--l; --r;
		r=r-len+1;
		int kiri=lower_bound(ok.begin(),ok.end(),l)-ok.begin();
		if (r<l)
		{
			cout<<0<<"\n";
			continue;
		}
		int kanan=upper_bound(ok.begin(),ok.end(),r)-ok.begin()-1;
		int ans=kanan-kiri+1;
		cout<<ans<<"\n";
	}
}