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

int vtos(vector<int> v){
	//int l=v.size();
	int n=0;
	for(int k: v){
		n=n*10+k;
	}
	return n;
}

void solve(){
	int n,k;
	cin>>n>>k;
	int minm,maxm;
	for(int i=0;i<k;i++){
		vector<int> v;
		while(n){
			int x=n%10;
			v.push_back(x);
			n=n/10;
		}
		sort(v.begin(),v.end());
		minm=vtos(v);
		sort(v.begin(),v.end(),greater<int>());
		maxm=vtos(v);
		n=maxm-minm;
	}
	printi(n);
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
