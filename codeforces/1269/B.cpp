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

map<int,int> frekA;
map<int,int> frekB;
vector<int> A;
vector<int> B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		int ta;
		cin >> ta;
		A.push_back(ta);
		frekA[ta]++;
	}
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	for (int i = 1 ; i <= n ; i++) {
		int ta;
		cin >> ta;
		B.push_back(ta);
		frekB[ta]++;
	}
	sort(B.begin(),B.end());
	B.erase(unique(B.begin(),B.end()),B.end());
	assert(A.size() == B.size());
	int ans = INF;
	for (int i = 0 ; i < B.size() ; i++) {
		int diff = B[i] - A[0];
		if (diff < 0)
			diff += m;
		bool can = true;
		// cout << diff << endl;
		for (int j = 0 ; j < A.size() ; j++) {
			int tmp = frekA[A[j]];
			int nxt = (A[j] + diff) % m;
			if (frekB[nxt] != tmp) {
				can = false;
				break;
			}
		}
		if (can)
			ans = min(ans,diff);
	}
	cout << ans << endl;
}