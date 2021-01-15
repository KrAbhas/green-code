#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << " " << x << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define nl cout << endl;
#define inputi(a) scanf("%d", &a)
#define inputl(a) scanf("%lld", &a)
#define printi(a) printf("%d ", a)
#define printl(a) printf("%lld ", a)
#define vi vector<int>
#define vl vector<ll>
const ll Max2 = 1e9 + 7;
const int Max1 = 1e6 + 1;

template <typename... T>
void read(T &&... arg)
{
    ((cin >> arg), ...);
}

template <typename... T>
void write(T &&... arg)
{ //rvalue reference (new to cpp)
    ((cout << arg << " "), ...);
    //cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int m;
    	cin>>m;
    	ll k[n];
    	ll c[m];
    	int a;
    	for(int i=0;i<n;i++){
    		cin>>k[i];
    	}
    	for(int i=0;i<m;i++){
    		cin>>c[i];
    	}
    	sort(k,k+n,greater<ll>());
    	int counter=0;
    	int flag=0;
    	ll s=0;
    	for(int i=0;i<n;i++){
    		if(flag==0){
    			if(c[k[i]-1]<=c[counter]){
    				//printl(c[counter]);
    				flag=1;
    				s+=c[k[i]-1];
    			}
    			else
    				s=s+c[counter];
    		}
    		else{
    			s+=c[k[i]-1];
    		}
    		counter++;
    	}
    	cout<<s<<endl;
    }
}