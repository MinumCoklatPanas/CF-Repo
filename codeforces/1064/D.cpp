#include <iostream>
#include <utility>
#include <queue>
#include <vector>
 
using namespace std;
 
using Pos = pair<int, int>;
 
int n, m, r, c, x, y;
char a[2000][2000];
 
void print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
 
int solve() {
	int ans = 0;
 
	Pos start = make_pair(r, c);
	priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, greater<pair<int, Pos>>> pq;
	pq.emplace(0, start);
	while (pq.size()) {
		auto top = pq.top();
		pq.pop();
 
		int cr = top.second.first, cc = top.second.second;
		if (a[cr][cc] == '*') continue;
 		// cout << cr << " " << cc << endl;
		++ans;
		a[cr][cc] = '*';
 
		if (cr != 0 && a[cr - 1][cc] != '*') {
			pq.emplace(top.first, make_pair(cr - 1, cc));
		}
		if (cr != n - 1 && a[cr + 1][cc] != '*') {
			pq.emplace(top.first, make_pair(cr + 1, cc));
		}
		if (cc != 0 && a[cr][cc - 1] != '*' && top.first < x) {
			pq.emplace(top.first + 1, make_pair(cr, cc - 1));
		}
		if (cc != m - 1 && a[cr][cc + 1] != '*' && cc - c + top.first < y) {
			pq.emplace(top.first, make_pair(cr, cc + 1));
		}
	}
 
	return ans;
}
 
int main() {
	cin >> n >> m >> r >> c >> x >> y;
	--r; --c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	cout << solve() << endl;
}