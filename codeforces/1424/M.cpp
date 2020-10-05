/*
 *  Filename: BubbleCup13/m.cpp
 *  Timestamp: 05-10-2020 20:15:37
 *  Author: Fadhil Musaad
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const ll INF64 = 1e18;

string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(bool b) {
  return b ? "true" : "false";
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename T>
string to_string(const vector<T> &v) {
  string ret = "<";
  for (auto it : v)
    ret += to_string(it) + ", ";
  ret.pop_back(); ret.pop_back();
  ret += ">";
  return ret;
}

void debug_print() { cerr << endl; }

template <typename T, typename ...U>
void debug_print(T t, U... u) {
  cerr << " " << to_string(t);
  debug_print(u...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_print(__VA_ARGS__)
const int N = 1e5 + 5;

struct Page {
  int num;
  vector<string> v;
  bool operator<(const Page &other) const {
    return num < other.num;
  }
};

ll n, k;
vector<Page> p;
vector<string> dic;
vector<int> adj[70];
vector<int> ord;;
bool mat[70][70];
bool cycle = false;
bool isExist[70];
int col[70];

int to_num(char x) {
  if (islower(x))
    return x - 'a';
  return x - 'A' + 26;
}

char to_ch(int x) {
  if (x < 26)
    return x + 'a';
  return x + 'A';
}

void dfs(int v) {
  col[v] = 1;
  for (auto it : adj[v]) {
    if (col[it] == 1) {
      cycle = true;
    }
    if (col[it] == 0) {
      dfs(it);
    }
  }
  ord.pb(v);
  col[v] = 2;
}

bool toposort() {
  SET(col, 0);
  for (int i = 0; i < 70; i++) {
    if (!isExist[i] || col[i] != 0)
      continue;
    dfs(i);
  }
  if (cycle)
    return false;
  reverse(all(ord));
  return true;
}

int main() {
  NeedForSpeed;
  cin >> n >> k;
  p.resize(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p[i].num = x;
    for (int j = 0; j < k; j++) {
      string s;
      cin >> s;
      for (char c : s) {
        isExist[to_num(c)] = 1;
      }
      p[i].v.pb(s);
    }
  }
  sort(all(p));
  dic.resize(n * k);
  for (int i = 0; i < n; i++) {
    if (i + 1 < n)
      assert(p[i].num != p[i + 1].num);
    for (int j = 0; j < k; j++) {
      dic[i * k + j] = p[i].v[j];
    }
  }
  for (int i = 1; i < n * k; i++) {
    int a = dic[i].size();
    int b = dic[i - 1].size();
    bool br = false;
    for (int j = 0; j < min(a, b); j++) {
      if (dic[i][j] != dic[i - 1][j]) {
        if (!mat[to_num(dic[i - 1][j])][to_num(dic[i][j])]) {
          mat[to_num(dic[i - 1][j])][to_num(dic[i][j])] = 1;
          adj[to_num(dic[i - 1][j])].pb(to_num(dic[i][j]));
        }
        b = true;
        break;
      }
    }
    if (!br && a < b)
      cycle = true;
  }
  if (!toposort()) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  for (auto it : ord) {
    cout << to_ch(it);
  }
  cout << '\n';
  //If you dont need Flush Stream, dont use endl
  return 0;
}
