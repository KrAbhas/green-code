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
	string n;
	cin>>n;
	int a=0;
	int pos;
	int val;
	for(int i=n.length()-1;i>=0;i--){
		for(int j=i-1;j>=-1;j--){
			for(int k=j-1;k>=-2;k--){
				
				if(k>-1 && j>-1)
					val=((int)(n[k]-'0'))*100+((int)(n[j]-'0'))*10+((int)(n[i]-'0'));
				else if(k==-1 && j>-1){
					val=((int)(n[j]-'0'))*10+((int)(n[i]-'0'));
				}
				else if(k<=-1 && j==-1)
					val=((int)(n[i]-'0'));
				if(val%8==0 && val>100){
					//deb((int)(n[k]-'0'));
					//cout<<i<<" "<<j<<" "<<k<<"\n";
					//cout<<val;
					cout<<"YES\n";
					a=val;
					pos=k;
					//if(val!=0)
					for(i=0;i<pos;i++){
						cout<<n[i];
					}
					cout<<val;
					return;
				}
				else if(val%8==0 && val<=100){
					cout<<"YES\n";
					cout<<val;
					printf("\n");
					return;
				}
				//deb(j);
			}
		}
	}
	if(a==0){
		cout<<"NO\n";
		return;
	}
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
	solve();
}
