#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define pb push_back
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl '\n'
#define loop(i,n) for(ll i = 0; i < n; i++)
#define loop1(i,n) for(ll i = 1; i <= n; i++)
#define REP(i,a,b) for (ll i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

struct DSU
{
    vector<int> parent;
    vector<int> GroupSize;

    DSU(int n)
    {  
        parent.resize(n + 10);
        GroupSize.resize(n + 10);

        for (int i = 0; i < n + 10; i++)
        {
            parent[i] = i;
            GroupSize[i] = 1;
        }
    }

    int FindLeader(int i)
    {
        if (parent[i] == i) return i;

        return parent[i] = FindLeader(parent[i]);
    }

    bool SameGroup(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        return leader1 == leader2;
    }


    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        if (leader1 == leader2) return;

        if (GroupSize[leader1] > GroupSize[leader2])
        {
            parent[leader2] = leader1;
            GroupSize[leader1] += GroupSize[leader2];
        }
        else
        {
            parent[leader1] = leader2;
            GroupSize[leader2] += GroupSize[leader1];
        }
    }

    int GetSize(int x)
    {
        int leader = FindLeader(x);
        return GroupSize[leader];
    }
};

bool isPrime(ll n)
{
    if (n <= 1)
    {
        return false;
    }

    for (ll i = 2; i*i <= n; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

ll power(ll a, ll b, ll m)
{
    ll result = 1;
    a = a % m;

    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }

    return result;
}

bool group(ll n, ll x, char g)
{
    if (g == 'a')
    {
        //cout << x << ' ' << n << nl;
        return x <= n;
    }

    return x > n;
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}

ll get(ll n, ll i)
{
    return (n&(1ll<<i)) ? 1 : 0;
}

ll on(ll n, ll i)
{
    return (n|(1ll<<i));
}

ll off(ll n, ll i)
{
    return (n&(~(1ll<<i)));
}

ll flip(ll n, ll i)
{ 
    return (n^(1ll<<i));
}

//const ll N = 2e5 + 10;

//ll a[N];
//ll n;


//ll memo[N];
//ll dp(ll i)
//{
	//if (i == n + 1)
		//return 0;
	
	//if (i > n + 1)
		//return 1e10;
		
	//if (memo[i] != -1)
		//return memo[i];
	
	//return memo[i] = min(dp(i + 1) + 1, dp(i + 1 + a[i]));
//}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n + 1], b[n + 1];
	
	loop1(i, n)
	{
		cin >> a[i];
	}
	
	loop1(i, n)
	{
		cin >> b[i];
	}
	
	ll l = 0, r = 2 * 1e9;
	ll ans = 0;
	while (l <= r)
	{
		ll cpK = k;
		
		ll mid = (l + r) / 2;
		
		loop1(i, n)
		{
			cpK -= max(a[i] * mid - b[i], 0ll);
			if (cpK < 0) break;
		}
		
		if (cpK >= 0)
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("tshirts.in","r",stdin);
    
    	
	//memset(memo, -1, sizeof(memo));
    int _ = 1;
    //cin >> _;
    while (_--)
    {
        solve();
    }
}
