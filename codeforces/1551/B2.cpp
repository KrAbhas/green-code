#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>>tt;
	while(tt--){
		int n, m;
		cin >> n >> m;
		int s[n];
		map<int,int>arr;
		//memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++){
			cin >> s[i];
			arr[s[i]] += 1;
		}
		
		int c = 0;
		map<int,vector<int>> dist;
		for (auto i = arr.begin(); i != arr.end(); i++){
			if (i->second <= m){
				c += i->second;
				dist[i->second].push_back(i->first);
			}
			else{
				dist[m].push_back(i->first);
				c += m;
			}
		}
		//cout<<c<<endl;
		int k = c / m;
		int t = 1;
		int r = 0;
		int p = 0;
		arr.clear();
		map<int,pair<int,int>> vec;
		map<int,vector<int>>:: reverse_iterator it;
		for (it = dist.rbegin(); it != dist.rend(); it++) {
			while(!it->second.empty()){
				int j = (it->second).back();
				//cout<<j<<"- ";
				(it->second).pop_back();
				vec[j].first = t;
				t = (t + it->first - 1) % m;
				if(t == 0)
					t = m;
				if (t - it->first + 1 <= 1)
					r++;
				if(r > k){
					if (vec[j].first != 1)
						vec[j].second = m;
					else vec[j].second = 0;
					p = 1;
					break;
				}
				vec[j].second = t;
				t++;
				t = t % m;
				if(t == 0)
					t = m;
				//cout<<j<<" * "<<vec[j].first<<" "<<vec[j].second<<endl;
			}
			if(p == 1)
				break;
		}

		for(int i = 0; i < n; i++){
			if (vec[s[i]].second != 0) {
				cout << vec[s[i]].second << " ";
				if(vec[s[i]].second == vec[s[i]].first) {
					vec[s[i]].second = 0;
					continue;
				}
				vec[s[i]].second--;
				if(vec[s[i]].second == 0)
					vec[s[i]].second = m;
			}
			else cout << "0 ";
		}
		cout << "\n";
	}
}

