#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int ww, hh;
		cin >> ww >> hh;
		int x1, y1, x2, y2;
		int w, h;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> w >> h;
		if (w + (x2 - x1) > ww && h + y2 - y1 > hh) {
			cout << -1 << endl;
			continue;
		}
 		int m = INT_MAX;
		//0,0
		int k =	INT_MAX;
		if (x2 - x1 + w <= ww)
			k = min(k, max(0, w - x1));
		if (y2 - y1 + h <= hh)
			k = min(k, max(0, h - y1));
		if (x2 - x1 + w <= ww)		
			k = min (k, max(0, x2 - ww + w));
		if (y2 - y1 + h <= hh)
			k = min (k, max(0, y2 - hh + h));
		cout << k << endl;
	}
	return 0;
}       	