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

bool sudah[30010];
map<int,bool> ada;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector< int > satu;
	cout << "? ";
	for (int i = 1 ; i <= 100 ; i++)
	{
		int tmp = rand() % ((1 << 14) - 1);
		while (sudah[tmp])
		{
			tmp = rand() % ((1 << 14) - 1);
		}
		sudah[tmp] = 1;
		if (i == 100)
			cout << tmp << endl;
		else
			cout << tmp << " ";
		satu.push_back(tmp);
	}
	cout << flush;
	int a;
	cin >> a;
	vector< int > dua;
	cout << "? ";
	for (int i = 1 ; i <= 100 ; i++)
	{
		int tmp = rand() % ((1 << 14) - 1);
		while (sudah[tmp])
		{
			tmp = rand() % ((1 << 14) - 1);
		}
		while (1)
		{
			ada.clear();
			bool cek = true;
			for (int j : satu)
			{
				int tmp2 = tmp ^ j;
				if (ada[tmp2])
				{
					cek = false;
					break;
				}
				ada[tmp2] = true;
			}
			if (cek)
				break;
			else
				tmp = rand() % ((1 << 14) - 1);
		}
		sudah[tmp] = 1;
		if (i == 100)
			cout << tmp << endl;
		else
			cout << tmp << " ";
		dua.push_back(tmp);
	}
	cout << flush;
	int b;
	cin >> b;
	int c = a ^ b;
	// cout << c << endl;
	// for (int i : satu)
	// 	cout << i << " ";
	// cout << endl;
	for (int i : satu)
		for (int j : dua)
		{
			int tmp = i ^ j;
			// if (i == 1 && j == 4041)
			// 	cout << i << " " << j << endl;
			if (c == tmp)
			{
				int x = a ^ i;
				if (j ^ x == b)
				{
					cout << "! " << x << endl;
					return 0;
				}
			}
		}
	return 0;
}