#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n,k,x;
	cin>>n>>k>>x;
	long long arr[n];
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	map<long long,long long> cost;
	for(long long i=1;i<n;i++){
		if(arr[i]-arr[i-1]>x){
			cost[(ceil((arr[i]-arr[i-1])*1.0/x)-1)]++;
			//cout<<(ceil((arr[i]-arr[i-1])*1.0/x)-1)<<endl;
		}
	}
	map<long long,long long>:: iterator it;
		
	for(it=cost.begin();it!=cost.end();it++){
		if(k>=it->first*it->second){
			k=k-it->first*it->second;
			it->second=0;
		}
		else{
			it->second=it->second-k/it->first;
			k=0;
		}
		if(k==0)
			break;
	}
	long long c=0;
	for(it=cost.begin();it!=cost.end();it++){
		c+=it->second;
	}
	c++;
	cout<<c<<'\n';
}