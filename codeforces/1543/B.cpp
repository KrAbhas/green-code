#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long tt;
	cin>>tt;
	while(tt--){
		long long n;
		cin>>n;
		int a;
		long long s=0;
		for(int i=0;i<n;i++){
			cin>>a;
			s+=a;
		}
		cout<<((s%n)*(n-s%n))<<"\n";
	}
}