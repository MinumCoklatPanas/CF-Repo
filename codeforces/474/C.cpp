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
const double EPS = 1e-6;

double between_d(double x,double l,double r) {
	return (min(l,r)<=x+EPS && x<=max(l,r)+EPS);
}

double same_d(double x,double y) {
	return between_d(x,y,y);
}

struct point {
	double x,y;
	point() {
		x=y=0.0;
	}
	point(double _x,double _y) {
		x=_x; y=_y;
	}
	bool operator< (point other) const {
        if (same_d(x,other.x))
        {
            return other.y - y > -EPS;
            // return y < other.y;/
        }
        else
            return other.x - x > -EPS;
            // return x < other.x;
	}
	bool operator== (point other) const {
		return same_d(x,other.x)&&same_d(y,other.y);
	}
};

double e_dist(point P1,point P2) {
	return hypot(P1.x-P2.x,P1.y-P2.y);
}

point rotate(double deg,point p,point pivot)
{
    double x,y;
    point ret;
    x = p.x - pivot.x;
    y = p.y - pivot.y;
    if (deg == 0.0)
    {
        ret.x = x + pivot.x;
        ret.y = y + pivot.y;
    }
    else
    if (deg == 90.0)
    {
        ret.x = -y + pivot.x;
        ret.y = x + pivot.y;
    }
    else
    if (deg == 180.0)
    {
        ret.x = -x + pivot.x;
        ret.y = -y + pivot.y;
    }
    else
    {
        ret.x = y + pivot.x;
        ret.y = -x + pivot.y;
    }
    return ret;
}

double toRad(double x)
{
    return (PI / 180.0) * x;
}

bool valid(vector< point > tab)
{
    // for (auto it : tab)
    //     cout << it.x << " " << it.y << endl;
    // cout << endl;
    vector< double > dist;
    for (int i = 1 ; i < 4 ; i++)
    {
        dist.push_back(e_dist(tab[0],tab[i]));
        if (dist.back() == 0.0) return false;
    }
    sort(dist.begin(),dist.end());
    if (!same_d(dist[0],dist[1])) return false;
    if (!same_d(dist[0] * sqrt(2.0),dist[2])) return false;
    // cout << "yo\n";
    for (int i = 1 ; i < 4 ; i++)
    {
        vector< double > tmp;
        for (int j = 0 ; j < 4 ; j++) if (i != j)
        {
            tmp.push_back(e_dist(tab[i],tab[j]));
            if (dist.back() == 0.0) return false;
        }
        sort(tmp.begin(),tmp.end());
        if (tmp != dist) return false;
    }
    return true;
}

int rec(int ix,vector< point > tab,vector< point > pivot)
{
    if (ix == 4)
    {
        if (valid(tab))
        {   
            return 0;
        }
        else
            return INF;
    }
    point tmp = tab[ix];
    int ret = INF;
    for (int i = 0 ; i < 4 ; i++)
    {
        vector< point > tmp2 = tab;
        tmp2[ix] = rotate((90.0 * i),tmp,pivot[ix]);
        ret = min(ret,i + rec(ix + 1,tmp2,pivot));
        // break;
        // if (ix != 1)
        //     break;
        // else
        // {
        //     if (i == 1)
        //         break;
        // }
    }
    tab[ix] = tmp;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector< point > tab(4),pivot(4);
        for (int i = 0 ; i < 4 ; i++)
        {
            cin >> tab[i].x >> tab[i].y >> pivot[i].x >> pivot[i].y;
        }
        // sort(tab.begin(),tab.end());
        // for (int i = 0 ; i < tab.size() ; i++)
        //     cout << tab[i].x << " " << tab[i].y << endl;
        // return 0;
        // point tmp = rotate(toRad(90.0),tab[1],pivot[1]);
        // cout << tmp.x << " " << tmp.y << endl;
        int ans = rec(0,tab,pivot);
        if (ans >= INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}