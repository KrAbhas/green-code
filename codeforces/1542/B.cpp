#include<bits/stdc++.h>
using namespace std;
int main(){


	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long tt;
	cin>>tt;
	while(tt--){
		long long n,a,b;
		cin>>n>>a>>b;
		long long p=a;
		long long q=b;
		long long k=0;
		if(b==1){
			cout<<"Yes\n";
			continue;
		}
		if(n%b==1){
			cout<<"Yes\n";
			continue;
		}
		if(a==1){
			if(n%b==1)
				cout<<"Yes\n";
			else cout<<"No\n";
			continue;
		}

		for(long long i=a;n-i>=0;i*=a){
			//cout<<i<<" ";
			if((n-i)%q==0){
				cout<<"Yes\n";
				b=-1;
				break;
			}
			k=i;
		}
		if(b!=-1)
			cout<<"No\n";
	}
}