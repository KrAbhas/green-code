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

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

void solve(){
	int n;
	cin>>n;
	for(int i=0;i*2020<=n;i++){
		int k=(n-i*2020)/2021;
		double d=(n-i*2020)*1.0/2021;
		if(k==d){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		//deb(t);
		solve();
		//deb(t);
	}
}

int main(){

	solve_t();
}