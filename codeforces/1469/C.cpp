#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define deb(x) cout<<#x<<" "<<x<<endl
#define fo(i,n) for(int i=0;i<n;i++)
#define nl cout<<endl;
#define inputi(a) scanf("%d",&a)
#define inputl(a) scanf("%lld",&a)
#define printi(a) printf("%d ",a)
#define printl(a) printf("%lld ",a)
#define vi vector<int>
const ll Max2=1e9+7;
const int Max1=1e6+1;
 
template<typename... T>
void read(T&&... arg){
	((cin>>arg),...);
}
 
template<typename... T> 
void write(T&&... arg){ //rvalue reference (new to cpp)
	((cout<<arg<<" "),...);
	//cout<<endl;
}

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		ll a[n];
		for(int i=0;i<n;i++) cin>>a[i];

		ll maxm=a[0];
		ll minm=a[0];
		ll c,d;
		int p=0;
		for(int i=1;i<n;i++){
			c=maxm;
			d=minm;
			maxm+=k-1;
			minm-=k-1;
			
			self_max(minm, a[i]);
			self_min(maxm, a[i]+k-1);
			
			if(maxm<minm){
				//cout<<"NO\n";
				p=1;
				break;
			}
		}
		//printl(minm);
		if(p==0 && minm>a[n-1])
			p=1;

		p==1?cout<<"NO\n":cout<<"YES\n";
	}
}