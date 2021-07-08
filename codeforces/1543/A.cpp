#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long long tt;
	cin>>tt;
	while(tt--){
		long long a,b;
		cin>>a>>b;
		long long c=abs(b-a);
		if(c==0)
			cout<<"0 0\n";
		else{
			long long res=(min(a,b)%c);
			long long k=min(res,c-res);
			cout<<c<<" "<<(k)<<"\n";
		}
	}
}