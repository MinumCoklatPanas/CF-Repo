#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int a[510][510];
int b[510][510];
map<int,int> cntA;
map<int,int> cntB;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			cntA[a[i][j]]++;
		}
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> b[i][j];
			cntB[b[i][j]]++;
		}
	for (int i = 1 ; i <= m ; i++)
	{
		int row = 1;
		int col = i;
		vector<int> A;
		vector<int> B;
		while (col)
		{
			A.push_back(a[row][col]);
			B.push_back(b[row][col]);
			--col;
			++row;
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		// cout << i << endl;
		for (int j = 0 ; j < A.size() ; j++)
		{
			// cout << A[j] << " " << B[j] << endl;
			if (A[j] != B[j])
			{
				// cout << i << endl;
				cout << "NO\n";
				// puts("NO");
				return 0;
			}
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		int row = i;
		int col = m;
		vector<int> A;
		vector<int> B;
		while (row <= n)
		{
			A.push_back(a[row][col]);
			B.push_back(b[row][col]);
			++row;
			--col;
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		// cout << i << endl;
		for (int j = 0 ; j < A.size() ; j++)
		{
			// cout << A[j] << " " << B[j] << endl;
			if (A[j] != B[j])
			{
				// cout << i << endl;
				cout << "NO\n";
				// puts("NO");
				return 0;
			}
		}
	}
	cout << "YES\n";
}