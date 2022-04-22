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
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e18 + 7;
const int maxx = 2 * 1e5 + 10;
const int mn = 1010;

ll cnt(map<string, ll> &d)
{
    int sum = 0;
    for (auto i : d)
        sum += (i.second * (i.second - 1)) / 2;
  
    return sum% inf;
}

ll differ(vector<string> &array, int m)
{
    map<string, ll> ch, sa;
    for (auto s : array)
    {
        sa[s]++;
        for (int i = 0; i < m; i++)
        {
            string t = s.substr(0, i) + "//" + s.substr(i + 1);
            ch[t]++;
        }
    }
    return (cnt(ch) - cnt(sa) * m) % inf;
}
  
// Driver Code
int main()
{
	int tt;
	cin >> tt;
    while (tt--){
        int n, m = 2;
        cin >> n;
        vector<string> array(n);
        for (int i = 0; i <n ;i++)
        cin>>array[i];
        cout << differ(array, m) << endl;
    }
    return 0;
}