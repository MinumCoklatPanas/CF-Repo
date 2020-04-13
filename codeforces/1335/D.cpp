#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

char tab[15][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	int t;
	cin >> t;
	while (t--)
	{	
		vector< pair<int,int> > pos;
		for (int i = 1 ; i <= 9 ; i++)
		{
			for (int j = 1 ; j <= 9 ; j++)
			{
				cin >> tab[i][j];
				if (tab[i][j] == '1')
					pos.emplace_back(i,j);
				// cout << tab[i][j];
			}
			// cout << endl;
		}
		for (auto it : pos)
			tab[it.first][it.second] = '9';
		for (int i = 1 ; i <= 9 ; i++)
		{
			for (int j = 1 ; j <= 9 ; j++)
				cout << tab[i][j];
			cout << endl;
		}
	}
	return 0;
}