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
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
        	cin >> s[i];
        }
        int mn = maxx;
        for (int i = 0; i < n; i++) {
        	for (int j = i + 1; j < n; j++) {
        		int c = 0;
        		for (int k = 0; k < m; k++) {
        			c += abs(s[i][k] - s[j][k]);
        		}
        		mn = min(mn, c);
        	}
        }
        cout << mn << endl;
    }
    return 0;
}