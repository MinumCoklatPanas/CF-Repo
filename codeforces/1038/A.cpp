#include <bits/stdc++.h>
using namespace std;

int frek[30];

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
//	cout<<n<<" "<<k<<"\n";
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++)
	 frek[s[i]-'A'+1]++;
	int mn=1000000;
	for (int i=1;i<=k;i++)
	 mn=min(mn,frek[i]);
	cout<<k*mn<<"\n";
}