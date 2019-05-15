#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

bool sudah[6];

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	double asli[6] = {4,8,15,16,23,42};
	double ratio[10][10];
	int ans[6];
	for (int i = 0 ; i < 6 ; i++)
		for (int j = 0 ; j < 6 ; j++)
			ratio[i][j] = asli[i] / asli[j];
	// for (int i = 0 ; i < 6 ; i++)
	// 	for (int j = i + 1 ; j < 6 ; j++)
	// 		cout << ratio[i][j] << endl;
//	return 0;
	cout << "? 1 2\n";
	cout << flush;
	double ab;
	cin >> ab;
	cout << "? 2 3\n";
	cout << flush;
	double bc;
	cin >> bc;
	double ca = bc / ab;
	for (int i = 0 ; i < 6 ; i++)
		for (int j = 0 ; j < 6 ; j++)
		{
			if (sudah[i] || sudah[j]) continue;
			if (fabs(ca - ratio[i][j]) <= EPS)
			{
				double c = asli[i];
				double a = asli[j];
				double b = bc / c;
				bool bisa = 0;
				int simpan = -1;
				for (int k = 0 ; k < 6 ; k++) if (k != i && k != j)
				{
					if (fabs(asli[k]- b) <= EPS)
					{
						bisa = 1;
						simpan = k;
						break;
					}
				}
				if (!bisa)continue;
				if (fabs(a*b - ab) <= EPS)
				{
					ans[0] = (int)a;
					ans[1] = (int)b;
					ans[2] = (int)c;
					sudah[simpan] = 1;
					sudah[i] = 1;
					sudah[j] = 1;
					goto hell;
				}
			}
		}
	hell:;
	cout << "? 4 5\n";
	cout << flush;
	cin >> ab;
	cout << "? 5 6\n";
	cout << flush;
	cin >> bc;
	ca = bc / ab;
	for (int i = 0 ; i < 6 ; i++)
		for (int j = 0 ; j < 6 ; j++)
		{
			if (sudah[i] || sudah[j]) continue;
			if (fabs(ratio[i][j] - ca) <= EPS)
			{
				double c = asli[i];
				double a = asli[j];
				double b = bc / c;
				bool bisa = 0;
				int simpan = -1;
				for (int k = 0 ; k < 6 ; k++) if (!sudah[k] && k != i && k != j)
				{
					if (fabs(asli[k] - b) <= EPS)
					{
						bisa = 1;
						simpan = k;
						break;
					}
				}
				if (!bisa)continue;
				if (fabs(a * b - ab) <= EPS)
				{
					ans[3] = (int)a;
					ans[4] = (int)b;
					ans[5] = (int)c;
					sudah[simpan] = 1;
					sudah[i] = 1;
					sudah[j] = 1;
					goto school;
				}
			}
		}
	school:;
	for (int i = 0 ; i < 6 ; i++)
	{
		assert(sudah[i]);
//		if (!sudah[i])
//		cout << i << "I belum\n";
	}
	cout << "! ";
	for (int i = 0 ; i < 6 ; i++)
	{
		if (i == 5)
			cout << ans[i] << endl;
		else
			cout << ans[i] << " ";
	}
}

