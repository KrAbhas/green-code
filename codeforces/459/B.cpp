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
	//vi v;
	ll a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	ll mn=a[0];
	int i=0;
	ll xmx,xmn;
	xmx=xmn=0;
	while(i<n && a[i]==mn){
		xmn++;
		i++;
	}
	i=n-1;
	ll mx=a[i];
	while(i>=0 && a[i]==mx){
		xmx++;
		i--;
	}
	//deb(xmx);
	//deb(xmn);
	printl(mx-mn);
	if(mx==mn)
		printl(xmx*(xmx-1)/2);
	else
		printl(xmx*xmn);
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

int main(){

	solve();
}