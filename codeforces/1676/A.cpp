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
        string s;
        cin >> s;
        int a = s[0] + s[1] + s[2] - 3 * 'a';
        int b = s[3] + s[4] + s[5] - 3 * 'a';
        if (a == b)
        	cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}