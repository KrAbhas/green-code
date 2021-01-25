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
	ll n;
	cin>>n;
	int a=2;int b=3;
	int c=n;
	for(int i=2;i<n/(i*(i+1));i++){
		//int k=n/(i*(i+1));
		for(int j=i+1;true;j++){
			int k=n/(i*j);
			if(j>=k){
				break;
			}
			double d=n*1.0/(i*j);
			//deb(k);
			//deb(d);
			if(k==d){
				c=k;
				a=i;
				b=j;
				cout<<"YES\n";
				cout<<a<<" "<<b<<" "<<c<<endl;
				return;
			}
			
		}
	}
	cout<<"NO\n";
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