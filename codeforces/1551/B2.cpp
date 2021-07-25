#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> seq(n);
		int x;
		vector<int> freq(n+1, 0);
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
			freq[seq[i]]++;
		}
		
		vector<vector<int>> col(n + 1);
		for (int i = 0; i <= n; i++) {
			if (freq[i] >= k) {
				for (int j = 1; j <= k; j++) {
					col[i].push_back(j);
				}
			}
		}

		int r = 0;
		for (int i = 0; i < n + 1; i++) {
			if (freq[i] > 0 && freq[i] < k) {
				for (int j = 0; j < freq[i]; j++) {
					if (r > k) {
						r = r % k;
					}
					if (r == 0) {
						r = k;
					}
					col[i].push_back(r);
					r++;
				}
			}
		}
		if (r > k) {
			r = r % k;
		}
		if (r == 0) {
			r = k;
		}
		//cout << r<<":\n";
		if(r != k){
			for (int i = n; i >= 0; i--) {
				if(r == 0)
					break;
				if (freq[i] > 0 && freq[i] < k) {
					for (int j = 0; j < freq[i]; j++) {
						if (r == 0)
							break;
						col[i].pop_back();
						r--;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (!col[seq[i]].empty()){
				cout << col[seq[i]].back() << " ";
				col[seq[i]].pop_back();
			}
			else cout << "0 ";
		}
		cout << "\n";
	}
}

