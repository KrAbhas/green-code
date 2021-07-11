#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
struct segtree{
	int size;
	vector<int> gcd;
	void init() {
		size = 1;
		while(size < n) size *= 2;
		gcd.assign(2 * size - 1, 0);
	}

	void build(vector<int>& v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)v.size())
				gcd[x] = v[lx];
			return;
		}
		int m = (lx + rx) / 2;
		build(v, 2 * x + 1, lx, m);
		build(v, 2 * x + 2, m, rx);
		gcd[x] = __gcd(gcd[2 * x + 1], gcd[2 * x + 2]);
	}

	void build(vector<int>& v) {
		build(v, 0, 0, size);
	}

	void print(){
		for (int i = 0; i < 2 * size - 1; i++)
			cout<< gcd[i]<< " ";
		cout<<endl;
	}

	int compgcd(int l, int r, int x, int lx, int rx) {
		if(lx > r || rx < l) {
			return 0;
		}
		if(rx <= r && lx >= l) {
			return gcd[x];
		}
		int m = (lx + rx) / 2;
		
		int g1 = compgcd(l, r, 2 * x + 1, lx, m);
		int g2 = compgcd(l, r, 2 * x + 2, m + 1, rx);
		//cout<<lx<<" "<<m<<" "<<rx<<endl;
		//cout<<g1<<" "<<g2<<" "<<endl;
		return __gcd(g1, g2);
	}

	int compgcd(int l, int r){
		return compgcd(l, r, 0, 0, size-1);
	}
};

bool good(int x, segtree& st, vector<int>& vec){
	int r;
	for(int i = 0; i < n; i++) {
		if(x > i) {
			r = st.compgcd(i,x);
		}
		else {
			int a,b;
				
				a = st.compgcd(i, n-1);
			
				b = st.compgcd(0, x);
			r = __gcd(a, b);
		}
		//cout<< r<< " "<< i <<" " << x<< endl;
		if(r != st.gcd[0])
			return false;
		x++;
		x = x % n;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int tt;
	cin>>tt;
	while(tt--){
		cin>>n;
		int x;
		int gc[n];
		segtree st;
		st.init();
		vector<int> vec;
		int t = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			vec.push_back(x);
			if(i > 0 && vec[i] != vec[i-1])
				t++;
			//cout << vec[i]<< " ";
		}
		if(t == 0){
			cout<<"0\n";
			continue;
		}
		//cout<<endl;
		//st.print();
		st.build(vec);
		//st.print();
		int l = 0;
		int r = n-1;
		//cout<<st.gcd[0]<<endl;
		while(r > l + 1) {
			int m = (l + r) / 2;
			//cout <<m <<" ";
			if(good(m, st, vec))
				r = m;
			else l = m;
		}
		//cout<<endl;
		cout << (r) << "\n";
	}

}