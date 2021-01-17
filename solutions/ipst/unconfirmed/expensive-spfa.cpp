// headers
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// types
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using dbl = double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using piipi = pair<pii, int>;
using pipii = pair<int, pii>;
using plpii = pair<ll, pii>;
using ppii = pair<pii, pii>;
// loops
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define fora(x, v) for (auto x : v)
// define shortcuts
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
// functions
template<class T> inline bool hasbit(T x, int i) { return x&(1<<i); }
template<class T> inline T togbit(T x, int i) { return x|(1<<i); }
template<class T> inline T setbit(T x, int i) { return x|(1<<i); }
template<class T> inline T rembit(T x, int i) { return x&~(1<<i); }
template<class T> inline bool setmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool setmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> int compress(vector<T> &v) { sort(all(v)); v.resize(unique(all(v))-v.begin()); return v.size(); }
// read functions
int read_int() { int x; scanf("%d", &x); return x; }
ll read_ll() { ll x; scanf("%" SCNd64, &x); return x; }
ull read_ull() { ull x; scanf("%" SCNu64, &x); return x; }
dbl read_dbl() { dbl x; scanf("%lf", &x); return x; }
void _R(int &x) { x = read_int(); }
void _R(ll &x) { x = read_ll(); }
void _R(dbl &x) { x = read_dbl(); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
// print functions
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%" PRId64, x); }
void _W(const ull &x) { printf("%" PRIu64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
// pseudo-random number generator
template<class T, T x1, T x2, T x3, int y1, int y2, int y3>
struct PRNG {
    using S = typename make_signed<T>::type;
    T s;
    PRNG(T _s = 0) : s(_s) {}
    T next() {
        T z = (s += x1);
        z = (z ^ (z >> y1)) * x2;
        z = (z ^ (z >> y2)) * x3;
        return z ^ (z >> y3);
    }
    T next(T n) { return next() % n; }
    S next(S l, S r) { return l + next(r - l + 1); }
    T operator()() { return next(); }
    T operator()(T n) { return next(n); }
    S operator()(S l, S r) { return next(l, r); }
    static T gen(T s) { return PRNG(s)(); }
    template<class U>
    void shuffle(U first, U last) {
        size_t n = last - first;
        for (size_t i = 0; i < n; i++) swap(first[i], first[next(i + 1)]);
    }
};
PRNG<uint32_t, 0x9E3779B1, 0x85EBCA6B, 0xC2B2AE35, 16, 13, 16> r32;
PRNG<uint64_t, 0x9E3779B97F4A7C15, 0xBF58476D1CE4E5B9, 0x94D049BB133111EB, 30, 27, 31> r64;
// program
int _main();
int main() {
    //ios::sync_with_stdio(false), cin.tie(0);
    //time_t begin = clock();
    int ret = _main();
    //time_t end = clock();
    //fprintf(stderr, "Program took %.3f seconds to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);
    return ret;
}

/************************************************************
                CODE STARTS BELOW THIS POINT
************************************************************/

const int INF = 1e9+1;
const int N = 100010;
const int LN = 19;
const int S = 110;

int n, m, q;
int deg[N], dep[N], len[N], par[N][LN];
vector<pii> G[N];
map<int, vector<int> > dlist;
bool vis[N];

void dfs(int u, int p)
{
    vis[u] = true;
    par[u][0] = p;
    for1(i, LN-1) par[u][i] = par[par[u][i-1]][i-1];
    fora(v, G[u]) if (v.F != p && !vis[v.F]) {
        dep[v.F] = dep[u] + 1;
        len[v.F] = len[u] + v.S;
        dfs(v.F, u);
    }
}

int lca(int u, int v)
{
    if (dep[u] > dep[v]) swap(u, v);
    rofn(i, LN) {
        int nv = par[v][i];
        if (dep[nv] >= dep[u]) v = nv;
    }
    if (u == v) return u;
    rofn(i, LN) {
        int nu = par[u][i];
        int nv = par[v][i];
        if (nu != nv) u = nu, v = nv;
    }
    return par[u][0];
}

int dist(int u, int v)
{
    return len[u]+len[v]-2*len[lca(u, v)];
}

vector<int> dijk(int s)
{
    vector<int> dist(n+1, INF);
    dist[s] = 0;
    deque<int> Q;
    Q.pb(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        fora(v, G[u]) if (setmin(dist[v.F], dist[u]+v.S)) {
            if (Q.empty() || dist[v.F] < dist[Q.front()])
                Q.push_front(v.F);
            else
                Q.pb(v.F);
        }
    }
    return dist;

    /*vector<bool> vis(n+1, false);
    vector<int> dist(n+1, INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Q.push({0, s});
    while (!Q.empty()) {
        int u = Q.top().S;
        int d = Q.top().F;
        Q.pop();
        if (vis[u] || d > dist[u])
            continue;
        vis[u] = true;
        fora(v, G[u]) if (!vis[v.F] && setmin(dist[v.F], d+v.S))
            Q.push({dist[v.F], v.F});
    }
    return dist;*/
}

int _main()
{
    R(n, m, q);
    for1(i, m) {
        int u, v, w;;
        R(u, v, w);
        G[u].eb(v, w);
        G[v].eb(u, w);
        ++deg[u], ++deg[v];
    }
    dfs(1, 0);
    for1(s, n) if (s == 1 || deg[s] > 2)
        dlist[s] = dijk(s);

    while (q--) {
        int u, v;
        R(u, v);
        int ans = dist(u, v);
        fora(&D, dlist)
            setmin(ans, D.S[u]+D.S[v]);
        W(ans);
    }

    return 0;
}