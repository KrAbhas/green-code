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

int finddrive(int k, int x){
	int c=0;
	while(k%x==0){
		k=k/x;
		c++;
	}
	return c;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;
        queue<int>v;
        ll p=0;
        int it=0;
        ll s=0;
        //cout<<"hi";
        int q=Max1;
        for(int i=0;i<n;i++){
        	int a;
        	cin>>a;
        	int b=min(finddrive(a,x),q);
        	if(b<q){
        		q=b;
        	 	p=s;
        	}
        	s+=a;
        }
        cout<<(s*(q+1))+p<<endl;
    }
}