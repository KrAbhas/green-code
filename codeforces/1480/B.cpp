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

ll nc2(ll n){
	return n*(n-1)/2;
}

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

void solve(){
	ll hlife, hpow, n;
	cin>>hpow>>hlife>>n;
	//deb(hlife);
	//deb(hpow);
	//deb(n);
	ll mlife[n];
	ll mpow[n];
	int k=0;
	int maxm=0;
	for(int i=0;i<n;i++){
		cin>>mpow[i];
		if(mpow[i]>maxm){
			maxm=mpow[i];
			k=i;
		}
	}
	
	for(int i=0;i<n;i++){
		cin>>mlife[i];
		//deb(mlife[i]);
		//deb(hpow);
		mlife[i]=ceil(mlife[i]*1.0/hpow);
		//deb(mlife[i]);
		//deb(mpow[i]);
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		if(k!=i)
			sum=sum+(mpow[i]*mlife[i]);
		else {
			if(mlife>0)
				sum=sum+(mpow[i]*(mlife[i]-1));
		}
	}
	//deb(sum);
	if(sum<=hlife){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
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
