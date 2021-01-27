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
	ll a,b,k;
	cin>>a>>b>>k;
	ll boy[a+1]={0};
	ll girl[b+1]={0};
	ll x;
	for(ll i=0;i<k;i++){
		cin>>x;
		boy[x]++;
		//deb(x);
	}
	for(ll i=0;i<k;++i){
		cin>>x;
		girl[x]++;
	}
	ll c=0;
	for(ll i=1;i<=a;i++){
		if(boy[i]>=2){
			c+=nc2(boy[i]);
			//cout<<"Hi"<<i;
		}
	}
	//deb(c);
	for(ll i=1;i<=b;i++){
		if(girl[i]>=2){
			c+=nc2(girl[i]);
		}
	}
	//deb(c);
	//deb(girl[3]);
	ll total=nc2(k)-c;
	cout<<total<<endl;
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
