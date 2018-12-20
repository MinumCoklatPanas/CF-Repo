#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD=998244353;

vector<ll> adj[300010];
ll color[300010];
ll OldLayer[2];
ll NewLayer[2];
ll n,m;

void reset()
{
	for (ll i=1;i<=n;i++)
	{
		adj[i].clear();
		color[i]=-1;
	}
	// memset(color,-1,sizeof(color)); 
	memset(OldLayer,0,sizeof(OldLayer));
	memset(NewLayer,0,sizeof(NewLayer));
}

ll IsBipartite(ll x)
{
	queue< pair<ll,ll> > q;
	q.push(make_pair(x,1));
	color[x]=0;
	ll mx=0;
	bool can=1;
	NewLayer[1]++;
	while (!q.empty())
	{
		pair<ll,ll> depan=q.front();
		ll u=depan.first;
		ll layer=depan.second;
		mx=max(mx,layer);
		q.pop();
		for (ll i=0;i<adj[u].size();i++)
		{
			if (color[adj[u][i]]==-1)
			{
				color[adj[u][i]]=1-color[u];
				NewLayer[(layer+1)%2]++;
				q.push(make_pair(adj[u][i],layer+1));
			}
			else
			if (color[adj[u][i]]==color[u]) return 0;
		}
	}
	return mx;
}

ll mul(ll x,ll y)
{
	return ((x%MOD)*(y%MOD))%MOD;
}

ll modpow(ll x,ll y)
{
	if (!y) return 1;
	ll z=modpow(x,y/2);
	z=mul(z,z);
	if (y&1) return mul(x,z);
	return z;
}

ll add(ll x,ll y)
{
	return ((x%MOD)+(y%MOD))%MOD;
}

ll readll ()
{
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


inline void writell (ll n)
{
    ll NN = n, rev, count = 0;
    rev = NN;
    if (NN == 0) { putchar('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar('0');
}


ll dua[300010];

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	dua[0]=1ll;
	for (ll i=1;i<=300000;i++)
		dua[i]=mul(dua[i-1],2);
	ll t;
	t=readll();
	while (t--)
	{
		n=readll();
		m=readll();
		reset();
		for (ll i=1;i<=m;i++)
		{
			ll a,b;
			a=readll();
			b=readll();
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ll ans=1;
		bool ada=0;
		for (ll i=1;i<=n;i++)
		{
			if (color[i]!=-1) continue;
			// memset(NewLayer,0ll,sizeof(NewLayer));
			ll conn=IsBipartite(i);
			if (conn==0)
			{
				ans=0;
				break;
			}
			ada=1;
			// cout<<conn<<" conn\n";
			ll ganjil=1;
			ll genap=1;
			for (ll j=0;j<=1;j++)
			{
				// cout<<NewLayer[j]-OldLayer[j]<<" layer\n";
				if (j&1)
					ganjil=mul(ganjil,dua[NewLayer[j]-OldLayer[j]]);
				else
					genap=mul(genap,dua[NewLayer[j]-OldLayer[j]]);
				OldLayer[j]=NewLayer[j];
			}
			// cout<<i<<" "<<ganjil<<" "<<genap<<"\n";
			ans=mul(ans,add(ganjil,genap));
		}
		// ll ganjil=1;
		// ll genap=1;
		// for (ll i=1;i<=n;i++)
		// {
		// 	if (i&1)
		// 		ganjil=mul(ganjil,dua[NewLayer[i]]);
		// 	else
		// 		genap=mul(genap,dua[NewLayer[i]]);
		// }
		// ans=add(ganjil,genap);
		writell(ans);
		puts("");
	}
}