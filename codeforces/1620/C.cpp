#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tt;
	cin >> tt;
	while (tt--){
		ll n, k, x;
		cin >> n >> k >> x;
		vector<char> str(n);
		vector<ll> freq;
		vector<string> form;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		for (int i = 0; i < n; i++) {
			int c = 0;
			while (i < n && str[i] == '*') {
				c++;
				i++;
			}
			if (c > 0){
				freq.push_back(c);
				i--;
			}
		}
		int f = freq.size();
		int t = 0;
		for (int i = f - 1; i >= 0; i--) {
			freq[i] = freq[i] * k + 1;
			if (i != f - 1)
				freq[i] = (freq[i + 1] * freq[i]);
			if (x <= freq[i]){
				t = i;
				break;
			}
		}
		vector<int> vec;
		x--;
		for (int i = t; i < f - 1; i++) {
			vec.push_back((x / freq[i + 1]));
			x = x % freq[i + 1];

		}
		vec.push_back(x);
		string temp = "";
		for (int i = 0; i < k; i++) {
			temp += 'b';
		}
		//cout << t << endl;

		int v = 0;
		int c = 0;
		while (c < n && v <= t) {
			if (c == 0 && str[c] == '*')
				v++;
			if (c < n - 1 && str[c] == 'a' && str[c + 1] == '*')
				v++;
			if (str[c] == 'a') {
				cout << 'a';
			}
			c++;
			if (v > t) 
				break;
		}
		for (int i = 0; i < vec.size(); i++) {
			//cout << vec[i] << endl;
			if (k != 0) {
				for (int j = 0; j < vec[i] / k; j++) {
					cout<<temp;
				}
				//cout << vec[0] / k;
				for (int j = 0; j < vec[i] % k; j++)
					cout<<'b';
			}
			while (c < n) {
				if (str[c] == 'a')
					cout << 'a';
				if (c < n - 1 && str[c] == 'a' && str[c + 1] == '*') {
					c++;
					break;
				}
				c++;
			}
		}
		
		cout << endl;
	}
}