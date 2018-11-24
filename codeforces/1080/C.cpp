#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct warna{
	ll hitam;
	ll putih;
};

warna cnt(ll x1,ll y1,ll x2,ll y2)
{
	ll row=(x2-x1)+1;
	ll col=(y2-y1)+1;
	ll sum=(row*col);
	warna res;
	res.hitam=res.putih=sum/2;
	if (sum%2==1)
	{
		if ((x1%2)==(y1%2))
			++res.putih;
		else
			++res.hitam;
	}
	return res;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,m;
		cin>>m>>n;
		warna now=cnt(1,1,m,n);
		// cout<<now.putih<<" "<<now.hitam<<"\n";
		// cout<<now.hitam<<" "<<now.putih<<"\n";
		ll x1,x2,y1,y2;
		cin>>y1>>x1>>y2>>x2;
		warna harusnya=cnt(y1,x1,y2,x2);
		ll luas=(y2-y1+1)*(x2-x1+1);
		ll black=luas-harusnya.putih;
		now.hitam-=black;
		now.putih+=black;
		// cout<<now.hitam<<" "<<now.putih<<"\n";
		ll xx1,xx2,yy1,yy2;
		cin>>yy1>>xx1>>yy2>>xx2;
		if (xx2<x1 || xx1>x2 || yy2<y1 || yy1>y2)
		{
			// cout<<"yo\n";
			harusnya=cnt(yy1,xx1,yy2,xx2);
			// cout<<harusnya.putih<<" "<<harusnya.hitam<<"\n";
			luas=(yy2-yy1+1)*(xx2-xx1+1);
			// cout<<luas<<" luas\n";
			ll white=luas-harusnya.hitam;
			now.putih-=white;
			now.hitam+=white;
			cout<<now.putih<<" "<<now.hitam<<"\n";
		}
		else
		{
			// cout<<"yo\n";
			ll Y[4]={y1,y2,yy1,yy2};
			sort(Y,Y+4);
			ll X[4]={x1,x2,xx1,xx2};
			sort(X,X+4);
			ll LuasIntersect=(Y[2]-Y[1]+1)*(X[2]-X[1]+1);
			// cout<<LuasIntersect<<" inte\n";
			harusnya=cnt(yy1,xx1,yy2,xx2);
			warna harusnya2=cnt(Y[1],X[1],Y[2],X[2]);
			// cout<<X[1]<<" "<<Y[1]<<" "<<X[2]<<" "<<Y[2]<<" \n";
			// cout<<harusnya2.putih<<" "<<harusnya2.hitam<<"\n";
			ll nambah=LuasIntersect-harusnya2.putih;
			// cout<<nambah<<" nambah\n";
			// cout<<harusnya.putih<<" "<<harusnya.hitam<<"\n";
			harusnya.putih+=nambah;
			harusnya.hitam-=nambah;
			// cout<<harusnya.putih<<" "<<harusnya.hitam<<"\n";
			luas=(yy2-yy1+1)*(xx2-xx1+1);
			ll white=luas-harusnya.hitam;
			now.putih-=white;
			now.hitam+=white;
			cout<<now.putih<<" "<<now.hitam<<"\n";
		}
	}
}
