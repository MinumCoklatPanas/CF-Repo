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

map< pair<int,int>, set<int> > mp;
pair<int,int> tab[1010];
pair<int,int> clue[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i].first >> tab[i].second;
	for (int i = 1 ; i <= n ; i++)
		cin >> clue[i].first >> clue[i].second;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			pair<int,int> treas;
			treas.first = tab[i].first + clue[j].first;
			treas.second = tab[i].second + clue[j].second;
			mp[treas].insert(j);
		}
	}
	for (auto it : mp) {
		if ((it.second).size() == n) {
			cout << it.first.first << " " << it.first.second << endl;
			return 0;
		}
	}
}