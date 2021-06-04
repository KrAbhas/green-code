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
	int p1=-1;
	int p2=-1;
	int s1=0;
	int s2=0;
	int k=0;
	for(int i=0;i<4;i++){
		inputi(k);
		if(s2>s1){
			swap(s1,s2);
			swap(p1,p2);
		}
		if(k>s2){
			s2=k;
			p2=i;
		}
	}
	if(s2>s1){
		swap(s1,s2);
		swap(p1,p2);
	}
	if(abs(p1-p2)>1){
		printf("Yes\n");
	}
	else if(abs(p1-p2)==1 && ((p1==1 && p2==2)||(p1==2 && p2==1))){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
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