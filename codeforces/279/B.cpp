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

//int arr[1e5+1];
void solve(){
	int n, t;
	cin>>n>>t;
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
		//printi(a[i]);
	}

	ll mx=0;
	ll total=0;
	int k=1;
	for(int i=1;i<=n;i++){
		while(k<=n && a[k]-a[i-1]<=t){
			k++;
		}
		self_max(mx,k-i);
		//deb(mx);
	}
	printi(mx);
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