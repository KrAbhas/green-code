#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
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
        int n, k;
        cin >> n >> k;
        int x;
        map<int,int> m;
        vector<int> v;
        for (int i = 0; i < n; i++) {
        	cin >> x;
        	m[x]++;
        	if (m[x] == 1)
        		v.pb(x);
        }
        sort (all(v));
        int l = 0; int r = 0;
        pi p = {-1, -1};
        bool ok = false;
        int s = -1;
        for (int i = 0; i < v.size(); i++) {
        	if (m[v[i]] >= k){
        		if (i > 0 && v[i] != v[i - 1] + 1)
        			ok = false;
        		if (!ok) {
        			l = i;
        			r = i;
        			ok = true;
        		}
        		else r = i;
        		if (s < r - l) {
        			s = r - l;
        			p = {l, r};
        		}
        	}
        	else {
        		ok = false;
        	}
        }
        if (p.first == -1)
        	cout << -1<< endl;
        else
        cout << v[p.first] << ' ' << v[p.second] << endl;
    }
    return 0;
}