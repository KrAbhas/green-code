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
	string s;
	cin>>s;
	int c=0;
	int d=0;
	int e=0;
	int f=0;
	for(int i=1; i<s.length(); i++){
		if(s[i-1]=='A' && s[i]=='B'){
			s[i-1]='@';
			s[i]='@';
			if(i+1<s.length() && s[i+1]=='A'){
				e++;
				s[i+1]='@';
			}
			c++;
		}
		if(s[i-1]=='B' && s[i]=='A'){
			s[i-1]='@';
			s[i]='@';
			if(i+1<s.length() && s[i+1]=='B'){
				f++;
				s[i+1]='@';
			}
			d++;
		}
	}
	if(c>=1 && d>=1){
		printf("YES");
	}
	else if(c>=1 || d>=1){
		//printf("hi");
		if(c>1 && e>=1){
			printf("YES");
		}
		else if(d>1 && f>=1){
			printf("YES");
		}
		else printf("NO");
	}
	else{
		printf("NO");
	}
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