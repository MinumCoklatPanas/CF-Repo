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

int tab[1010];
int gobs[15] = {2,3,5,7,11,13,17,19,23,29,31};
int ans[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cout << __gcd(437,391) << endl;	
	int t;
	cin >> t;
	while (t--)
	{
		// cout << "yo\n";
		int n;
		cin >> n;
		vector< int > compress;
		for (int i = 1 ; i <= n ; i++)
		{
			int ta;
			cin >> ta;
			for (int j = 0 ; j < 11 ; j++) if (ta % gobs[j] == 0)
			{
				ans[i] = j + 1;
				compress.push_back(j + 1);
				break;
			}
		}
		sort(compress.begin(),compress.end());
		compress.erase(unique(compress.begin(),compress.end()),compress.end());
		cout << compress.size() << endl;
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 0 ; j < compress.size() ; j++)
			{
				if (ans[i] == compress[j])
				{
					cout << j + 1 <<  " ";
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}