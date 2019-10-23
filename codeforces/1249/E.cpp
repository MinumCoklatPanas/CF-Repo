#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll tab[2][200010];
ll dist[2][2000010];//[index]
ll n,c;

void dijkstra() {
	for (ll i = 1 ; i <= n ; i++)
		dist[0][i] = dist[1][i] = INFF;
	dist[0][1] = 0;
	dist[1][1] = 0;
	//<jarak,<sebelumnya pake lift,index>>
	priority_queue< pair< ll,pair<ll,ll> >,vector< pair< ll,pair<ll,ll> > >, greater< pair< ll,pair<ll,ll> > > > pq;
	pq.push({0,{0,1}});
	while (!pq.empty()) {
		pair< ll,pair<ll,ll> > depan = pq.top();
		pq.pop();
		ll jarak = depan.first;
		ll pake_lift = depan.second.first;
		ll index = depan.second.second;
		// cout << jarak << " " << pake_lift << " " << index << endl;
		if (jarak == dist[pake_lift][index]) {
		//naik tangga
		ll d = jarak + tab[0][index];
		// cout << d << " ";
			if (dist[0][index + 1] > d) {
				dist[0][index + 1] = d;
				pq.push({d,{0,index + 1}});
			}
			//naik lift
			d = jarak + tab[1][index] + c * (!pake_lift);
			// cout << d << endl;
			// cout <<index << " index\n";
			// cout << tab[1][1] << endl; 
			// cout << jarak << " " << tab[1][index] << " " << c << endl;
			if (dist[1][index + 1] > d) {
				dist[1][index + 1] = d;
				pq.push({d,{1,index + 1}});
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> c;
	for (ll i = 1 ; i < n ; i++)
		cin >> tab[0][i];
	for (ll i = 1 ; i < n ; i++) {
		cin >> tab[1][i];
		// cout << tab[1][i] << " ";
	}
	// cout << endl;
	// return 0;
	dijkstra();
	for (ll i = 1 ; i <= n ; i++) {
		if (i == n)
			cout << min(dist[0][i],dist[1][i]) << endl;
		else
			cout << min(dist[0][i],dist[1][i]) << " ";
	}
}