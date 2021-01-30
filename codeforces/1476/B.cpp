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
#define vl vector<ll>
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

/*
int iscomposite[Max1];
void sieve(){
	iscomposite[0]=1;
	iscomposite[1]=1;
	for(int i=2;i*i<Max1;i++){
		if(!iscomposite[i]){
			for(int j=i+i;j<Max1;j=j+i){
				iscomposite[j]=1;
			}
		}
	}
}
*/

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

ll nc2(ll n){
	return n*(n-1)/2;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll change[n];
	ll total[n];
	for(int i=0;i<n;i++){
		cin>>change[i];
		if(i>=1)
			total[i]=total[i-1]+change[i];
		else total[i]=change[i];
		//deb(total[i]);
	}
	ll count=0;
	ll delta=0;
	for(int i=1;i<n;i++){
		total[i-1]=total[i-1]+delta;
		ll a=change[i]*100;
		if(a*1.0/total[i-1]>k){
			//deb(delta);
			delta+=ceil(a*(1.0)/k)-total[i-1];
			//deb(delta);
		}
	}
	cout<<delta<<endl;
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

int main(){
	solve_t();
}
