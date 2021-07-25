#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int chars[26][n];
		int freq[26];
		//vector<string> vs(n);
		string vs;
		for (int i = 0; i < n; i++) {
			cin >> vs;
			int l = vs.length();

			//const freq array
			memset (freq, 0, sizeof(freq));
			for (int j = 0; j < l; j++) {
				freq[vs[j] - 'a']++;
			}

			//const of chars to map takability
			for (int j = 0; j < 26; j++) {
				chars[j][i] = freq[j] - l + freq[j];
			}
		}

		//computing max
		int maxm = 0;
		for (int i = 0; i < 26; i++) {
			sort(chars[i], chars[i] + n, greater<int>());
			int s = 0;
			int j = 0;
			while (j < n) {
				if (s + chars[i][j] <= 0){
					break;
				}
				s += chars[i][j];
				j++;
			}
			maxm = max (maxm, j);
		}
		cout << maxm << "\n";
	}
}

