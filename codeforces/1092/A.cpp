#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,k;
		cin>>n>>k;
		for (int i=0;i<n;i++)
		{
			cout<<(char)('a'+(i%k));
		}
		cout<<"\n";
	}
}