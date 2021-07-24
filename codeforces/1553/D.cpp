#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>>tt;
	while(tt--){
		string s,t;
		cin>>s>>t;
		int n,m;

		n = (int) s.size();
		m = (int) t.size();

		if(n<m){
			cout<<"NO\n";
			continue;
		}
		int j = n - 1;
		int c = 0;
		for(int i = m - 1; i >= 0; i--) {
			while (j >= 0 && s[j] != t[i]) {
				j -= 2;
			}
			if(j < 0)
				break;
			if (s[j] == t[i])
				c++;
			j -= 1;
		}
		if (c == m) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}

