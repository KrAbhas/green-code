#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n];
		ll a=0;
		ll b=0;
		for(int i=0;i<n;++i){
			cin>>arr[i];
			if(i%2==0)
				a=a+arr[i];
			else
				b=b+arr[i];
		}
		int c=0;
		if(b>a)
			c=1;
			
		for(int i=0;i<n;++i){
			if(i%2==c)
				cout<<arr[i]<<" ";
			else cout<<"1 ";
		}
		cout<<endl;
	}
}
