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
	int n;
	inputi(n);
	vector<int> odd;
	vector<int> even;
	int o=0; int e=0;
	int k;
	for(int i=0;i<n;++i){
		inputi(k);
		if(k%2==0){
			even.push_back(k);
			e++;
		}
		else {
			odd.push_back(k);
			o++;
		}
	}
	//printi(e);
	//printi(o);
	ll s=(e)*n-((e*(e+1))/2);
	//printi(s);
	int q=0;
	for(int i=0;i<o;i++){
		k=odd[i];
		if(k==1)
			continue;
		for(int j=i+1;j<o;j++){
			s+=__gcd(k,odd[j]*2)>1;
		}
	}
	if(q>=1){
		s++;
	}
	printi(s);
	printf("\n");
}
 
void solve_t(){
	int t;
	inputi(t);
	int i=0;
	while(t--){
		i++;
		//printf("Case #%i: ", i);
		solve();
	}
}
 
int main(){

	solve_t();
}