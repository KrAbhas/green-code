#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dist(pair<int,int> a, pair<int,int>b){
	return abs(a.first - b.first)+abs(a.second - b.second);
}

int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		int sum=0;
		if(b>0){
			sum=a*n+n*b;
		}
		else{
			int zgr=0;int ogr=0;
			int i=0;
			while(i<n){
				int z=0,o=0;
				while(s[i]=='0'){
					i++;
					z++;
				}
				while(s[i]=='1'){
					i++;
					o++;
				}
				if(z>0){
					zgr++;
				}
				if(o>0){
					ogr++;
				}
			}
			if(ogr<zgr){
				sum=a*n+b*ogr+b;
			}
			else{
				sum=a*n+b*zgr+b;
			}
		}
		cout<<sum<<"\n";
	}
}