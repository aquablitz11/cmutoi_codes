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

const int INF = 1e9;
const int N = 1010;

bool vis[N][N];
int B[N][N], dist[N][N];
int gox[5], goy[5];
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int dd[] = {151, 101, 151, 151, 101, 151, 101, 101};

int _main()
{
    int L;
    R(L);
    while (L--) {
        int n, m, sx, sy, tx, ty, b, t, x, y, x2, y2, d;
        R(n, m, sx, sy, tx, ty, b, t);
        for1(i, n) for1(j, m) B[i][j] = -1, dist[i][j] = INF, vis[i][j] = false;
        forn(i, b) R(x, y), B[x][y] = 0;
        for1(i, t) R(x, y, x2, y2), B[x][y] = i, gox[i] = x2, goy[i] = y2;

        dist[sx][sy] = 0;
        priority_queue<pipii, vector<pipii>, greater<pipii> > Q;
        Q.push({0, {sx, sy}});
        while (!Q.empty()) {
            d = Q.top().first;
            tie(x, y) = Q.top().second;
            Q.pop();
            if (x == tx && y == ty) {
                W(d);
                break;
            }
            if (vis[x][y] || d > dist[x][y]) continue;
            vis[x][y] = true;
            if (B[x][y] == -1) {
                forn(i, 8) {
                    int nx = x+dx[i], ny = y+dy[i], nd = d+dd[i];
                    if (!vis[nx][ny] && B[nx][ny] && setmin(dist[nx][ny], nd))
                        Q.push({nd, {nx, ny}});
                }
            } else {
                int i = B[x][y];
                int nx = gox[i], ny = goy[i], nd = d;
                if (!vis[nx][ny] && B[nx][ny] && setmin(dist[nx][ny], nd))
                    Q.push({nd, {nx, ny}});
            }
        }
    }
    
    return 0;
}