/*
 *  Filename: BubbleCup13/irev.cpp
 *  Timestamp: 05-10-2020 21:54:27
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

ll mulmod(ll a, ll b) {
  a %= MOD;
  b %= MOD;
  return (a * b) % MOD;
}

ll f(ll n) {
  ll r = (n + 1) / 2;
  if (n & 1)
    return mulmod(r, r);
  return mulmod(r, r + 1);
}

int main() {
  NeedForSpeed;
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    n += 2;
    n /= 2;
    cout << f(n) << '\n';
  }
  //If you dont need Flush Stream, dont use endl
  return 0;
}
