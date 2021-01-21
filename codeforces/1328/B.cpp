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
const int Max3=1e5+1;
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

//char dp[Max3]={'a'};
void solve(ll n){
	ll k;
	cin>>k;
	ll i;
	for(i=1;i<=n;++i){
		if(k<=i*(i-1)/2){
			break;
		}
	}
	ll p=n-i+1;
	ll q=p+(i*(i-1)/2-k)+1;
	for(i=1;i<=n;i++){
		if(i==p || i==q){
			cout<<'b';
		}
		else cout<<'a';
	}
}

void solve_t(){
	int t;
	cin>>t;
	//m=0;
	//dp[m]=0;
	while(t--){
		ll n;
		cin>>n;
		solve(n);
		cout<<"\n";
	}
}

int main(){

	solve_t();
}