#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue< ll > pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	ll kurang=0ll;
	for (int i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		pq.push(-a);
	}
	for (int i=1;i<=k;i++)
	{
		if (pq.empty())
			cout<<0<<"\n";
		else
		{
			while (-pq.top()-kurang==0 && !pq.empty())
				pq.pop();
			if (pq.empty())
			{
				cout<<0<<"\n";
				continue;
			}
			ll depan=-pq.top();
			pq.pop();
			// cout<<depan<<" depan\n";
			ll res=max(depan-kurang,0ll);
			kurang+=res;
			cout<<res<<"\n";
		}

	}
}