// #################################################################################################
// #                                        You told me                                            #
// #           At your absolute best, you still won't be good enough for the wrong person          #
// #                   At your worst, you'll still be worth it to the right person                 #
// #                           It was good while it lasted, good bye                               #
// #    I believe I really loved you... to that point that I always wanted to hear your voice      #
// #    But before my hand could reach you... you seem to be slowly disappearing from my sight     #
// #################################################################################################
 
 
// #pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define ff  first
#define ss second
#define tm1 first
#define tm2 second.first
#define tm3 second.second
#define sz(x) ll(x.size())
#define fill(x, v) memset(x, v, sizeof(x))
#define all(v) (v).begin(), (v).end()
#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)
#define IFR(i,a,b) for(ll i=ll(a); i>=ll(b); i-- )
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
// #define N 6800005
#define mod1 1000000007
// #define mod1 998244353
#define mod2 1000000009LL
#define bas 987625403
#define sqr(x) 1LL * (x) * (x)
#define INF (ll) 2e18
 
using namespace std;
using namespace __gnu_pbds;
 
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> S_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_Hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout << x << " : " << val1 << "\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd = strchr(x + 1, ',');
    cout.write(x, xd - x) << " : " <<val1 << " | ";
    fff(xd + 1, val2...);
}
 
inline ll add(ll a, ll b, ll mod) { return a + b < mod? a + b : a + b - mod;}
inline ll rem(ll a, ll b, ll mod) { return a >= b? a - b: a - b + mod;}
inline ll mul(ll a, ll b, ll mod) { return (long long) a * b % mod;}
inline void Mul(ll &a, ll b, ll mod) { a = (long long) a * b % mod;}
inline ll bp(ll a, ll p, ll mod){
    ll ret;
    for(ret = 1; p; p >>= 1, Mul(a, a, mod)) (p & 1) && (Mul(ret, a, mod), 1);
    return ret;
}
 
static inline void read(ll &result) {
    bool minus = false;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' and ch <= '9') break;
        ch = getchar();
    }
    (ch == '-')? minus = true: result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' or ch > '9') break;
        result = (result<<3)+ (result<<1) + (ch - '0');
    }
    if(minus) result = -result;
}

struct T {
    multiset<ll> vec;
    T(){}
    inline void clear() {
        multiset<ll>().swap(vec);
    }
    inline ll Left(ll x) {
        auto it = vec.upper_bound(x);
        if(it == vec.begin()) return -INF;
        it --;
        return *it;
    }
    inline ll Right(ll x) {
        auto it = vec.lower_bound(x);
        if(it == vec.end()) return INF;
        return *it;
    }
};

struct ST {
    vector<T> t;
    ll n;
    inline T Op(T a, T b) {
        T ans;
        for(auto xd : a.vec) ans.vec.insert(xd);
        for(auto xd : b.vec) ans.vec.insert(xd);
        return ans;
    }
    inline void build() { IFR(i, n - 1, 1) t[i] = Op(t[i << 1], t[i << 1 | 1]);}
    inline void modify(ll p, ll last, ll val) { 
        p += n;
        while(p) {
            auto it = t[p].vec.find(last);
            t[p].vec.erase(it);
            t[p].vec.insert(val);
            p >>= 1;
        }
    }
    inline ll queLeft(ll l, ll r, ll x) {
        ll ans = -INF;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ans = max(ans, t[l ++].Left(x));
            if(r & 1) ans = max(t[--r].Left(x), ans);
        }
        return ans;
    }
    inline ll queRight(ll l, ll r, ll x) {
        ll ans = INF;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ans = min(ans, t[l ++].Right(x));
            if(r & 1) ans = min(t[-- r].Right(x), ans);
        }
        return ans;
    }
};

int main() {
    fastio;
    ll t; cin >> t;
    while(t --) {
        ll n, q, ty, l, r, x; cin >> n >> q;
        vi ar(n);
        for(auto &xd : ar) cin >> xd;
        ST st;
        st.n = n;
        st.t.resize(n << 1);
        FER(i, n, n << 1) st.t[i].vec.insert(ar[i - n]);
        st.build();
        auto Que = [&](ll l, ll r) {
        	if(r - l <= 700) {
        		ll ans = -INF;
        		FER(i, l, r) ans = max(ans, (ar[i] - ar[l]) * (ar[r - 1] - ar[i]));
        		return ans;
        	}
            ll ans = -ar[l] * ar[r - 1];
            // y = a * x - x ^ 2
            auto a = ar[l] + ar[r - 1];
            auto L = st.queLeft(l, r, a / 2);
            auto R = st.queRight(l, r, (a + 1) / 2);
            auto valL = L != -INF ? a * L - L * L : -INF;
            auto valR = R != INF ? a * R - R * R : -INF;
            return max(valL, valR) + ans;
        };
        auto Upd = [&](ll l, ll x) {
            st.modify(l, ar[l], x);
            ar[l] = x;
        };
        FER(i, 0, q) {
            cin >> ty;
            if(ty & 1) {
                cin >> l >> r; l --;
                auto BunChan = Que(l, r);
                cout << BunChan << "\n";
            }
            else {
                cin >> l >> x; l --;
                Upd(l, x);
            }
        }
    }
    return 0;
}