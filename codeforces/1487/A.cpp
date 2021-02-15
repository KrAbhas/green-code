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

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

ll nc2(ll n){
	return n*(n-1)/2;
}

int stotime(string s,string form){
	//int n=8;
	int k;
	int min;
	if(form[0]=='A'){
		//cout<<"here\n";
		k=stoi(s.substr(0,2));
		k=k%12;
		min=stoi(s.substr(3,5));
	}
	else{
		int l=stoi(s.substr(0,2));
		k=12+l%12;
		min=stoi(s.substr(3,5));
	}
	int t=(k+10)*100+min;
	return t;
}

int getdistinct(vector<char> f, vector<char> s){
	int c=0;
	sort(f.begin(),f.end());
	for(char ch:s){
		if(binary_search(f.begin(),f.end(),ch)){
			c++;
		}
	}
	return c;
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int k=arr[0];
	int i=0;
	while(arr[i]==k){
		i++;
	}
	printi(n-i);
	printf("\n");
}

void solve_t(){
	sieve();
	int t;
	cin>>t;
	while(t--){
		//cout<<"hello";
		solve();
	}
}

int main(){
	solve_t();

}
