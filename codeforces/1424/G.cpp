#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef pair<int, int> pii;

int n, a, b, l, r, ans, c, year, fix, fixyear;
vector<pii > v;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
        b--;
		v.push_back({a, b});
	}
    int ans = 0; 
	int c = 0; 
	vector<pii > all; 
	for(int i = 0; i < v.size(); i++) 
    { 
		all.push_back({ v[i].first, 0}); 
		all.push_back({ v[i].second, 1}); 
	} 
	sort(all.begin(), all.end()); 
	for(int i = 0; i < all.size(); i++)
    { 
		if (all[i].second == 0) c++;
		if (all[i].second == 1) c--;
		// ans = max(ans, c); 
        if(ans < c)
        {
            ans = c;
            year = all[i].first;
        }
	} 
	cout << year << " " << ans << endl; 
    return 0;
	c = 0;
	sort(v.begin(), v.end());
	l = 0; r = 1000000005; 
    year = 10000005;
	ans = 0;
	for(auto u : v)
	{
		if((u.fi <= r) && (u.sc >= l))
		{
			l = max(l, u.fi);
			r = min(r, u.sc);
            ans++;
            // cout << l << " " << r << endl;
            year = l;
		}
		else 
        {
            if(fix < ans)
            {
                fix = ans;
                fixyear = year;
            }
            l = u.fi, r = u.sc, ans = 1;
        }
	}
	printf("%d %d\n", fixyear, fix);
}
