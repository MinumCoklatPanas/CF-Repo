#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

map< pair<int,int>,vector<int> > adj;
int cnt[100010];
pair< pair<int,int>,int > tab[100010];
bool vis[100010];
vector<int> ans;
int head,tail;
int n;

bool dfsCek(int curL,int curR) {
	vis[curL] = 1;
	vis[curR] = 1;
	if (curR == tail) return true;
	bool ret = false;
	for (int i = 0 ; i < adj[{curL,curR}].size() ; i++) {
		int ix = adj[{curL,curR}][i];
		int nxt;
		vector<int> tmp(3);
		tmp[0] = tab[ix].first.first;
		tmp[1] = tab[ix].first.second;
		tmp[2] = tab[ix].second;
		sort(tmp.begin(),tmp.end());
		int mx = max(curL,curR);
		int mn = min(curL,curR);
		if (tmp[0] == mn && tmp[1] == mx)
			nxt = tmp[2];
		else
		if (tmp[0] == mn && tmp[2] == mx)
			nxt = tmp[1];
		else
		if (tmp[1] == mn && tmp[2] == mx)
			nxt = tmp[0];
		else
			assert(false);
		if (!vis[nxt])
			ret |= dfsCek(curR,nxt);
	}
	return ret;
}

void dfsFill(int curL,int curR) {
	vis[curL] = 1;
	vis[curR] = 1;
	if (curR == tail) {
		return;
	}
	bool ret = false;
	for (int i = 0 ; i < adj[{curL,curR}].size() ; i++) {
		int ix = adj[{curL,curR}][i];
		int nxt;
		vector<int> tmp(3);
		tmp[0] = tab[ix].first.first;
		tmp[1] = tab[ix].first.second;
		tmp[2] = tab[ix].second;
		sort(tmp.begin(),tmp.end());
		int mx = max(curL,curR);
		int mn = min(curL,curR);
		if (tmp[0] == mn && tmp[1] == mx)
			nxt = tmp[2];
		else
		if (tmp[0] == mn && tmp[2] == mx)
			nxt = tmp[1];
		else
		if (tmp[1] == mn && tmp[2] == mx)
			nxt = tmp[0];
		else
			assert(false);
		if (!vis[nxt]) {
			ans.push_back(nxt);
			dfsFill(curR,nxt); 
		}
	}
	return;
}

void process() {
	memset(vis,0,sizeof(vis));
	for (int i = 1 ; i <= n ; i++) {
		if (tab[i].first.first == head) {
			ans.push_back(tab[i].first.first);
			if (dfsCek(tab[i].first.second,tab[i].second)) {
				ans.push_back(tab[i].first.second);
				ans.push_back(tab[i].second);
				memset(vis,0,sizeof(vis));
				vis[head] = 1;
				dfsFill(tab[i].first.second,tab[i].second);
			}
			else {
				ans.push_back(tab[i].second);
				ans.push_back(tab[i].first.second);
				memset(vis,0,sizeof(vis));
				vis[head] = 1;
				dfsFill(tab[i].second,tab[i].first.second);
			}
		}
		else if (tab[i].first.second == head) {
			ans.push_back(tab[i].first.second);
			vis[head] = 1;
			if (dfsCek(tab[i].first.first,tab[i].second)) {
				ans.push_back(tab[i].first.first);
				ans.push_back(tab[i].second);
				memset(vis,0,sizeof(vis));
				vis[head] = 1;
				dfsFill(tab[i].first.first,tab[i].second);
			}
			else {
				ans.push_back(tab[i].second);
				ans.push_back(tab[i].first.first);
				memset(vis,0,sizeof(vis));
				vis[head] = 1;
				dfsFill(tab[i].second,tab[i].first.first);
			}
		}
		else if (tab[i].second == head) {
			ans.push_back(tab[i].second);
			if (dfsCek(tab[i].first.first,tab[i].first.second)) {
				ans.push_back(tab[i].first.first);
				ans.push_back(tab[i].first.second);
				memset(vis,0,sizeof(vis));
				vis[head] = 1;
				dfsFill(tab[i].first.first,tab[i].first.second);
			}
			else {
				ans.push_back(tab[i].first.second);
				ans.push_back(tab[i].first.first);
				memset(vis,0,sizeof(vis));
				vis[head] = 1;
				dfsFill(tab[i].first.second,tab[i].first.first);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n - 2 ; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		cnt[a]++;
		cnt[b]++;
		cnt[c]++;
		adj[{a,b}].push_back(i);
		adj[{b,a}].push_back(i);
		adj[{a,c}].push_back(i);
		adj[{c,a}].push_back(i);
		adj[{b,c}].push_back(i);
		adj[{c,b}].push_back(i);
		tab[i] = {{a,b},c};
	}
	head = -1;
	tail = -1;
	for (int i = 1 ; i <= n ; i++) if (cnt[i] == 1) {
		if (head == -1)
			head = i;
		else
			tail = i;
	}
	process();
	if (ans.size() != n) {
		ans.clear();
		swap(head,tail);
		process();
	}
	assert(ans.size() == n);
	for (int i = 0 ; i < n ; i++)
		cout << ans[i] << " ";
	cout << endl;
}
