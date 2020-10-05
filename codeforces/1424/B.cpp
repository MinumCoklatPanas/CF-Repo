#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

const int MAXN = 2e5 ;
int N , M  ; // N = Number of Nodes on the Left side and M = Number of Edges in the bipartite graph
vector<int> g [MAXN] ; // Declaration of our bipartite graph
int Distance[MAXN] ; // This will store the Length of augmenting path we have made till this node
int matched[MAXN] ; // matched[u] = v , if there is an edge between u and v in final matched graph.

bool bfs()
{
    /**
       Construction of Layered graph with alternating matched and unmatched edges using bfs.
    **/
   queue<int> q ;
   for(int i = 1 ; i <= N ; i++)  // Looping through all Left Side vertices
      if(matched[i] == 0) // If this vertex is not matched then insert it into queue to make layered graph
      {
         q.push(i) ;
         Distance[i] = 0 ;
      }
      else Distance[i] = INF ; // it is matched we dont have to consider it now

   Distance[0] = INF ; // This is the dummy vertex created to check existence of a augmenting path if this remains INF  after bfs then it would mean that there are
                   // no more augmenting paths and we need to stop now
   while(!q.empty())
   {
      int Left = q.front(); // unmatched vertex
      q.pop() ;
      for(int Right : g[Left])  // Looking for all right side vertices
      {
         if(Distance[matched[Right]] == INF) // This means that the edge between ch and matched[ch]  is a matched edge and hence fulfils our condition of alterating vertices
         {
            Distance[matched[Right]] = Distance[Left] + 1 ; // We made  it an unmatched edge and pushed into the queue
            q.push(matched[Right]) ;
         }

      }

   }
   return (Distance[0] != INF); // if Distance is not equal to infinity then we have find an augmenting path and it will increasing matching by atleast one.
}

/* Construction of new matching using dfs */
bool dfs(int Left)
{
   if(Left == 0) return true;

   for(int Right : g[Left])
   {
      if(Distance[matched[Right]] == Distance[Left] + 1)
      {
         if(dfs(matched[Right]))
         {
            matched[Left] = Right;
            matched[Right] = Left;
            return true;
         }
      }

   }
   Distance[Left] = INF;
   return false;

}

int Hopcroft()
{
   int matching = 0;

   while(bfs())
   {
      for(int i = 1 ; i <= N ; i++)
      if(matched[i] == 0 and dfs(i)) // updating the matched and unmatched vertices
         matching++ ;  // Since every augmenting path increases matching by 1
   }

   return matching;
}

struct node
{
    int u,v,c;

    node(int _u,int _v,int _c)
    {
        u = _u;
        v = _v;
        c = _c;
    }
};


int n,m;

void reset()
{
    memset(matched,0,sizeof(matched));
    for (int i = 1 ; i <= 2 * n ; i++) g[i].clear();
}

vector<node> edges;

bool cek(int k)
{
    reset();
    N = n; M = 0;
    for (auto it : edges) if (it.c <= k)
    {
        g[it.u].push_back(it.v + n);
        ++M;
    }
    int cnt = Hopcroft();
    return (cnt == n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        edges.push_back(node(u,v,c));
    }
    int l = 1;
    int r = INF;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (cek(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (cek(l))
        cout << l << endl;
    else
    if (cek(r))
        cout << r << endl;
    else
        cout << -1 << endl;
    return 0;
}