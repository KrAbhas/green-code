#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		map<int ,long long> elem;
		int a;
		long long s=0;
		long long c=0;
		for(int i=0;i<n;i++){
			cin>>a;
			if(elem.find(a)!=elem.end())
				c=c+elem[a];
			elem[a]+=i+1;
			s=s+c;
		}
		cout<<s<<"\n";
	}
}