#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define os tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e18 + 7;
const int maxx = 2 * 1e5 + 10;
const int mn = 1010;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        os s;
        ll ans = 0;
        int x;
        for (int i = 0; i < n; i++) {
        	cin >> x;
        	ll l = sz(s) - s.order_of_key(x);
        	ans += l;
        	s.insert(x);
        }
        cout << ans << endl;
    }
    return 0;
}