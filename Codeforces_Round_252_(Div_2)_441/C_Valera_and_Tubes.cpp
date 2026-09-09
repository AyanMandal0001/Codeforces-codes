#include <bits/stdc++.h>
using namespace std;

/*============= Standard Macros =================*/
#define ll long long
const ll mod = 1e9 + 7;

#define faster() (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0))

#define state pair<ll, ll>
#define vi vector<ll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define umap unordered_map
#define uset unordered_set

#define pb push_back
#define pback pop_back
#define eb emplace_back

#define ff first
#define ss second

#define lb lower_bound
#define ub upper_bound

#define contain(i, mp) ((mp).find(i) != (mp).end())
#define maxele(x) *max_element(all(x))
#define minele(x) *min_element(all(x))

#define len(s) (s).length()
#define nl cout << '\n'
#define endl '\n'

#define rep(i, a, b) for (ll i = a; i < b; i++)

/* ===================== BASIC MATH ===================== */

inline ll ceilf(ll a, ll b) { return (a + b - 1) / b; }
inline ll floorf(ll a, ll b) { return a / b; }

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll res = power(a, b / 2);
    res *= res;
    if (b & 1) res *= a;
    return res;
}

ll binpow(ll b, ll p, ll m) {
    ll ans = 1;
    b %= m;
    while (p) {
        if (p & 1) ans = ans * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return ans;
}

ll mul(ll a, ll b) { return (a % mod) * (b % mod) % mod; }
ll addm(ll a, ll b) { return (a % mod + b % mod) % mod; }
ll subtm(ll a, ll b) { return (a % mod - b % mod + mod) % mod; }
ll modInv(ll x) { return binpow(x, mod - 2, mod); }
ll divm(ll a, ll b) { return mul(a, modInv(b)); }

/* ===================== NUMBER THEORY ===================== */

bool isPrime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

ll countSetBits(ll num) {
    ll cnt = 0;
    while (num) {
        cnt += num & 1;
        num >>= 1;
    }
    return cnt;
}

ll sumOfDigits(ll n) {
    ll sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

ll cnt_noOfDigits(ll num) {
    if (num == 0) return 1;
    return (ll)log10(num) + 1;
}

vector<ll> divisors(ll x) {
    vector<ll> ans;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ans.pb(i);
            if (i * i != x) ans.pb(x / i);
        }
    }
    return ans;
}

vector<pair<ll, ll>> Factors(ll x) {
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ll cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            ans.pb({i, cnt});
        }
    }
    if (x > 1) ans.pb({x, 1});
    return ans;
}

/* ===================== COMBINATORICS ===================== */

ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    double res = 1;
    for (ll i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return (ll)(res + 0.01);
}

/* ===================== DATA STRUCTURES ===================== */

struct bag {
    ll cur_sum = 0;
    map<ll, ll> mp;

    void insert(ll x) {
        cur_sum += x;
        mp[x]++;
    }

    void remove(ll x) {
        cur_sum -= x;
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
    }

    ll sum() { return cur_sum; }

    ll getmax() {
        return mp.empty() ? -1 : prev(mp.end())->first;
    }

    ll getdistinct() { return mp.size(); }
};

/* ===================== DEBUG ===================== */
#define deb(a,n) cout<<#a<<" : "; for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n"; for(ll i=0;i<row;i++){ for(ll j=0;j<col;j++) cout<<mat[i][j]<<" "; cout<<endl; }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)

template <class S, class T>
ostream& operator <<(ostream& os, const pair<S, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator <<(ostream& os, const vector<T>& p) {
    os << "[ ";
    for (auto& it : p) os << it << " ";
    return os << "]";
}

template <class T>
ostream& operator <<(ostream& os, const unordered_set<T>& p) {
    os << "[ ";
    for (auto& it : p) os << it << " ";
    return os << "]";
}

template <class S, class T>
ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {
    os << "[ ";
    for (auto& it : p) os << it << " ";
    return os << "]";
}

template <class T>
ostream& operator <<(ostream& os, const set<T>& p) {
    os << "[ ";
    for (auto& it : p) os << it << " ";
    return os << "]";
}

template <class T>
ostream& operator <<(ostream& os, const multiset<T>& p) {
    os << "[ ";
    for (auto& it : p) os << it << " ";
    return os << "]";
}

template <class S, class T>
ostream& operator <<(ostream& os, const map<S, T>& p) {
    os << "[ ";
    for (auto& it : p) os << it << " ";
    return os << "]";
}

template <class T>
void dbs(string str, T t) {
    cout << str << " : " << t << "\n";
}

template <class T, class... S>
void dbs(string str, T t, S... s) {
    ll idx = str.find(',');
    cout << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}

template <class T>
void prc(T a, T b) {
    cout << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cout << ", ";
        cout << *i;
    }
    cout << "]\n";
}
void print(ll aa[], ll n) {
    for (ll i = 0; i < n; i++) {
        cout << aa[i] << " ";
    }
    cout << endl;
}
/* ===================== SOLUTION ===================== */

ll n,m, k;
ll a, b, c;
string s;
ll aa[1000100];

void solve() {
    cin>>n>>m>>k;
  vector<pair<ll,ll>> v;
  for(ll i=1;i<=n;i++){
    if(i%2){
       for(ll j=1;j<=m;j++)v.pb(make_pair(i,j));
    }else{
       for(ll j=m;j>=1;j--)v.pb(make_pair(i,j));
    }
  }
  ll i=0;
  while(k>1){
  cout<<2<<" ";
  cout<<v[i].ff<<" "<<v[i].ss<<" ";
  cout<<v[i+1].ff<<" "<<v[i+1].ss<<" ";
  cout<<endl;
  i+=2;
    k--;
  }

  cout<<n*m-i<<" ";
  for(ll j=i;j<n*m;j++){
    cout<<v[j].ff<<" "<<v[j].ss<<" ";
  }
}

/* ===================== MAIN ===================== */

signed main() {
    faster();
    ll tt = 1;
 //   cin >> tt;
    while (tt--) solve();
    return 0;
}