// headers
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse3,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
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
//#define F first
//#define S second
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
template<class T> void compress(vector<T> &v) { sort(all(v)); v.resize(unique(all(v))-v.begin()); return v.size(); }
// read functions
int read_int() { int x; scanf("%d", &x); return x; }
int read_ll() { ll x; scanf("%" PRId64, &x); return x; }
int read_dbl() { dbl x; scanf("%lf", &x); return x; }
void _R(int &x) { x = read_int(); }
void _R(ll &x) { x = read_ll(); }
void _R(dbl &x) { x = read_dbl(); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
// print functions
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
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
using R32 = PRNG<uint32_t, 0x9E3779B1, 0x85EBCA6B, 0xC2B2AE35, 16, 13, 16>;
R32 r32;
using R64 = PRNG<uint64_t, 0x9E3779B97F4A7C15, 0xBF58476D1CE4E5B9, 0x94D049BB133111EB, 30, 27, 31>;
R64 r64;
// program
int program();
int main() {
    //ios::sync_with_stdio(false), cin.tie(0);
    //time_t begin = clock();
    int ret = program();
    //time_t end = clock();
    //fprintf(stderr, "Program took %.3f seconds to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);
    return ret;
}

/************************************************************
                CODE STARTS BELOW THIS POINT
************************************************************/

const int INF = 1e9;
const int N = 110;
const int K = 1000;

struct Data {
    int F, S;
    bool operator<(const Data &rhs) const {
        return (S-F) < (rhs.S-rhs.F);
    }
};

int len(Data x)
{
    return x.S - x.F;
}

int n, m;
int v[N];
set<Data> dp[N][N];

Data ext(Data x, int y)
{
    if (y < x.F)
        x.F = y;
    if (y > x.S)
        x.S = y;
    return x;
}

void upd(set<Data> &v, Data x, int k=K)
{
    auto it = v.upper_bound(x);
    v.insert(it, x);
    if (v.size() > K)
        v.erase(--v.end());
}

int program()
{
    R(n, m);
    for1(i, n)
        R(v[i]);
    
    int sum = 0;
    for1(j, n) {
        sum += v[j];
        upd(dp[1][j], {sum, sum});
    }
    forx(i, 2, m) {
        forx(j, i, n) {
            upd(dp[i][j], {-INF, INF});
            sum = v[j];
            rofx(k, j-1, i-1) {
                int c = 0;
                fora(y, dp[i-1][k]) {
                    Data x = ext(y, sum);
                    upd(dp[i][j], x);
                    if (dp[i][j].size() >= K && ++c > K/10)
                        break;
                }
                sum += v[k];
            }
        }
        forx(j, 1, n)
            dp[i-1][j].clear();
    }
    W(len(*dp[m][n].begin()));
    
    return 0;
}