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

void travel(int a,int b, vector<int>v[], int arr[][4]){
	
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	stack<int> v;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0){
			v.push(arr[i]);
		}
		else if(v.top()<arr[i]){
			v.push(arr[i]);
		}

	}
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		if(v.top()==arr[i]){
			printi(arr[i]);
			v.pop();
			while(!st.empty()){
				printi(st.top());
				st.pop();
			}
		}
		else{
			st.push(arr[i]);
		}
	}
	printf("\n");
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
