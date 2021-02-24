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

//observation 1: because d itself is lucky, if we can make k,
//we can make k + any multiple of d
//
//formulate the problem as: for every 0<=i<d, what is the minimum x where x%d==i
// such that x can be written as sum of lucky numbers?
//-->this is a preprocessing thing as it is independent of the query
//
//example 1: q=3 d=7
// so if we can make x, we can make x+7(x+14, x+21...)
//
//so we want to know for each i=0,...,6
// what is the minimum x (where x%7==i) such that you can make x?
//
//observation 2: strategy for finding these key "x" values --> approach like a
// knapsack problem
//
void solve(){
	
	
}

void solve_t(){
	int t;
	cin>>t;

	const int maxm=100;
	vector<vector<bool>> can(10, vector<bool>(maxm));

	for(int d=0;d<=9;++d){
		auto &makable=can[d];
		makable[0]=1;
		for(int i=0;i<100;++i){
			int d0=i%10, d1=i/10;
			if(d0==d || d1==d || makable[i]){//check if the number is lucky
				for(int j=0;j+i<maxm;++j){
					//if j is lucky, then j+i is also lucky
					makable[j+i]=makable[i+j] || makable[j];
				}
			}
		}
	}
	
	while(t--){
		int n, luck;
		cin>>n>>luck;
		int q;
		for(int i=0;i<n;i++){
			cin>>q;
			if(q>=100 || can[luck][q])
				cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}

int main(){
	solve_t();
}
