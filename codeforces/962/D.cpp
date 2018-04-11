#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map< ll,priority_queue<ll> > pos;
unordered_map<ll,ll> frek;
unordered_map<ll,bool> nyala;

int main()
{
//	 freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	ll tab[200010];
	vector<ll> vec;
	pos.clear();
	frek.clear();
	nyala.clear();
	for (ll i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	frek[tab[i]]++;
	 	vec.push_back(tab[i]);
	 	pos[tab[i]].push(-i);
	 	nyala[tab[i]]=1;
	 }
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	priority_queue<ll> q;
	for (ll i=0;i<vec.size();i++)
	 q.push(-vec[i]);
	vector<ll> now;
	ll cnt=1;
	while (!q.empty())
	{
		ll u=-q.top();
		q.pop();
		now.push_back(u);
		if (pos[u].size()>1)
		{
			now.push_back(2*u);
			q.push(-2*u);
			while (pos[u].size()>1)
			{
				pos[u].pop();
				ll L2=pos[u].top();
				pos[u].pop();
				pos[2*u].push(L2);
			}
		}
	}
	sort(now.begin(),now.end());
	now.erase(unique(now.begin(),now.end()),now.end());
	vector< pair<ll,ll> > posi;
	for (ll i=0;i<now.size();i++)
	{
		assert(pos[now[i]].size()<=1);
//		if (pos[now[i]].size()==1)
//		cout<<now[i]<<" "<<pos[now[i]].top()<<"\n";
		if (pos[now[i]].size()==1)
		 posi.push_back(make_pair(-pos[now[i]].top(),now[i]));
	}
	sort(posi.begin(),posi.end());
	cout<<posi.size()<<"\n";
	for (ll i=0;i<posi.size();i++)
	 {
	 	if (i==posi.size()-1)
	 	 cout<<posi[i].second<<"\n";
	 	else
	 	 cout<<posi[i].second<<" ";
	 }
}
