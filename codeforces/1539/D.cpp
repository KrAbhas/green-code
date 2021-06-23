#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool my_cmp(pair<ll,ll> &a,pair<ll,ll>&b){
	return a.second<b.second;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;
	vector<pair<ll,ll>> vec;
	ll a,b;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>b;
		vec.push_back({a,b});
	}
	sort(vec.begin(),vec.end(),my_cmp);
	ll hptr,lptr;
	hptr=n-1;
	lptr=0;
	ll cost=0;
	ll pro=0;
	//cout<<"h";
	while(hptr>=lptr){
		//cout<<lptr<<hptr<<endl;
		if(pro>=vec[lptr].second){
			//cout<<"a";
			pro+=vec[lptr].first;
			cost+=vec[lptr].first;
			vec[lptr].first=0;
			lptr++;
		}
		else{
			if(vec[lptr].second>=vec[hptr].first+pro){
				//cout<<"c";
				pro+=vec[hptr].first;
				cost+=vec[hptr].first*2;
				vec[hptr].first=0;
				hptr--;
			}
			else{
				//cout<<"b";
				ll d=vec[lptr].second-pro;
				pro+=d;
				cost+=d*2;
				vec[hptr].first-=d;
				//cout<<d;
			}
			//cout<<cost<<" ";
		}
	}
	cout<<cost<<'\n';
}