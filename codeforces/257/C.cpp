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

double between_d(double x,double l,double r) {
	return (min(l,r)<=x+EPS && x<=max(l,r)+EPS);
}

double same_d(double x,double y) {
	return between_d(x,y,y);
}

double dabs(double x) {
	if (x<EPS) return -x; return x;
}

int sign(double x) {
	return (0.0<x)-(x<0.0);
}

/*Point*/

struct point {
	double x,y;
	point() {
		x=y=0.0;
	}
	point(double _x,double _y) {
		x=_x; y=_y;
	}

    int kuadran()
    {
        if (x >= 0.0 && y >= 0.0) return 1;
        if (x <= 0.0 && y >= 0.0) return 2;
        if (x <= 0.0 && y <= 0.0) return 3;
        if (x >= 0.0 && y <= 0.0) return 4;
        assert(false);
        return 5;
    }

	bool operator< (point other) const {
		if (y<other.y+EPS) return true;
		if (y+EPS>other.y) return false;
		return x<other.x+EPS;
	}
	bool operator== (point other) const {
		return same_d(x,other.x)&&same_d(y,other.y);
	}
};

double e_dist(point P1,point P2) {
	return hypot(P1.x-P2.x,P1.y-P2.y);
}

double m_dist(point P1,point P2) {
	return dabs(P1.x-P2.x)+dabs(P1.y-P2.y);
}

bool pointBetween(point P,point L,point R) {
	return (e_dist(L,P)+e_dist(P,R)==e_dist(L,R));
}

point mid(point P,point Q) {
	return point((P.x+Q.x)/2,(P.y+Q.y)/2);
}

/*Vector*/

struct vec {
	double x,y;
	vec() {
		x=y=0.0;
	}
	vec(double _x,double _y) {
		x=_x; y=_y;
	}
	vec(point A) {
		x=A.x; y=A.y;
	}
	vec(point A,point B) {
		x=B.x-A.x; y=B.y-A.y;
	}
};

vec scale(vec v,double s) {
	return vec(v.x*s,v.y*s);
}

vec flip(vec v) {
	return vec(-v.x,-v.y);
}

double dot(vec u,vec v) {
	return (u.x*v.x+u.y*v.y);
}

double cross(vec u,vec v) {
	return (u.x*v.y-u.y*v.x);
 }

double norm_sq(vec v) {
	return (v.x*v.x+v.y*v.y);
}

point translate(point P,vec v) {
	return point(P.x+v.x,P.y+v.y);
}

point rotate(point P,point O,double angle) {
	vec v(O); P=translate(P,flip(v));
	return translate(point(P.x*cos(angle)-P.y*sin(angle),P.x*sin(angle)+P.y*cos(angle)),v);
}

double angle(point A,point O,point B) {
	vec OA(O,A), OB(O,B);
	return acos(dot(OA,OB)/sqrt(norm_sq(OA)*norm_sq(OB)));
}

double orientation(point O,point P,point Q) {
	vec OP(O,P), OQ(O,Q);
	double c=cross(OP,OQ);
	return c;
}

bool cmp(point a,point b)
{
    if (a.kuadran() == b.kuadran())
    {
        point origin(0,0);               
        vec OA(origin,a), OB(origin,b);
        return (cross(OA,OB) > EPS);
    }   
    else
    return a.kuadran() < b.kuadran();
}

double toDeg(double x)
{
    return (180.0 / PI) * x;
}


point tab[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        puts("0.00000000");
        return 0;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i].x >> tab[i].y;
        // cout << tab[i].kuadran() << endl;
    }
    sort(tab + 1,tab + n + 1,cmp);
    point origin(0,0);
    // for (int i = 1 ; i <= n ; i++)
    //     cout << tab[i].x << " " << tab[i].y << endl;
    // double tmp = toDeg(angle(tab[1],origin,tab[n]));
    double ans = 360.0;
    for (int i = 1 ; i + 1 <= n ; i++)
    {
        vec OA(origin,tab[i + 1]), OB(origin,tab[i]);
        double sudut = toDeg(angle(tab[i],origin,tab[i + 1]));
        // cout << i << " " << sudut << " " << (cross(OA,OB) < 0.0) << " " << cross(OA,OB) << endl;
        if (cross(OA,OB) < EPS)
            ans = min(ans,360.0 - sudut);
        else
            ans = min(ans,sudut);
    }
    vec OA(origin,tab[n]),OB(origin,tab[1]);
    double sudut = toDeg(angle(tab[n],origin,tab[1]));
    if (cross(OA,OB) < EPS)
        ans = min(ans,sudut);
    else
        ans = min(ans,360.0 - sudut);
    cout << setprecision(8) << fixed << endl;
    cout << ans << endl;
    return 0;
}
