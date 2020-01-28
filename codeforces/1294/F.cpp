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

const int N = 200005;
 
vector<int> seen; // record each vertice visited in current decomposition
int size[N]; // size of subtree 
int worst[N]; // size of heaviest subtree when this vertice is taken as root
bool taken[N]; // flag for already taken vertice, effectively blocking from other tree
vector<int> adj[N]; // adjacency in tree
int parent[N]; // parent in centroid tree
bool marked[N];
int dist[N];
int parentBfsTree[N];
int n;
 
void dfs(int now,int prv) {
  worst[now] = 0;
  size[now] = 1;
  seen.push_back(now);
  for(int nex : adj[now]) {
    if(nex == prv || taken[nex]) continue;
    dfs(nex,now);
    worst[now] = max(worst[now],size[nex]);
    size[now] += size[nex];
  }
}
 
// prv is centroid from previous step, which created this tree
void makeCentroidTree(int now,int prv) {
  seen.clear();
  dfs(now,0);
  int root = now;
  int best = worst[now];
  
  // find centroid
  for(int inside : seen) {
    worst[inside] = max(worst[inside],size[now] - size[inside]);
    if(worst[inside] < best) {
      best = worst[inside];
      root = inside;
    }
  }
  
  parent[root] = prv;
  taken[root] = 1;
  
  // make centroid for newly created tree from separation
  for(int nex : adj[root]) {
    if(!taken[nex]) {
      makeCentroidTree(nex,root);
    }
  }
}

void makeCentroidTree()
{
	// dfs(1,-1);
	makeCentroidTree(1,-1);
}
 
int traverse(int now) {
  int cur = now;
  int ret = 0;
  while(!marked[cur]) {
    // notice that in original tree, every descendant of cur except the descendant of now's ancestor which is child of cur
    // have LCA which is cur
    // we can use that property to solve problems like QTREE5
    ++ret;
    cur = parent[cur];
  }
  return ret;
}

int bfs(int root)
{
	memset(marked,0,sizeof(marked));
	for (int i = 1 ; i <= n ; i++)
		dist[i] = INF;
	dist[root] = 0;
	queue< pair<int,int> > q;
	q.push({root,0});
	memset(parentBfsTree,-1,sizeof(-1));
	while (!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();
		int u = cur.first;
		int step = cur.second;
		for (int next : adj[u]) if (dist[next] > step + 1)
		{
			dist[next] = step + 1;
			parentBfsTree[next] = u;
			q.push({next,step + 1});
		}
	}
	int furthestNode = -1;
	int maxDist = 0;
	for (int i = 1 ; i <= n ; i++) if (dist[i] > maxDist)
	{
		maxDist = dist[i];
		furthestNode = i;
	}
	// cout << furthestNode << endl;
	// return furthestNode;
	assert(furthestNode != -1);
	int tmp = furthestNode;
	while (tmp != root)
	{
		marked[tmp] = 1;
		tmp = parentBfsTree[tmp];
	}
	marked[root] = 1;
	return furthestNode;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// memset(parent,-1,sizeof(parent));
	cin >> n;
	for (int i = 1 ; i < n ; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// return 0;
	int a = bfs(1);
	// return 0;
	int b = bfs(a);
	int tot = dist[b];
	queue< pair<int,int> > q;
	for (int i = 1 ; i <= n ; i++)
	{
		dist[i] = INF;
		if (marked[i])
		{
			q.push({i,0});
			dist[i] = 0;
		}
	}
	while (!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();
		int u = cur.first;
		int step = cur.second;
		for (int next : adj[u]) if (dist[next] > step + 1)
		{
			dist[next] = step + 1;
			q.push({next,step + 1});
		}
	}
	int c = -1;
	int mx = -1;
	for (int i = 1 ; i <= n ; i++) if (i != a && i != b && dist[i] > mx)
	{
		mx = dist[i];
		c = i;
	}
	tot += mx;
	cout << tot << endl;
	cout << a << " " << b << " " << c << endl;
	return 0;
}