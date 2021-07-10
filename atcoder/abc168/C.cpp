#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double a,b,h,m;
	cin>>a>>b>>h>>m;
	h=h+(m/60.0);
	double k=h/12.0<1.0?h/12.0:(1-h/12.0);
	double hrdeg=(k*360*M_PI/180.0);
	k=m/60.0<1?m/60.0:(1-m/60.0);
	double mindeg=(k*360*M_PI/180.0);
	k=abs(hrdeg-mindeg)<360*M_PI/180?abs(hrdeg-mindeg):(360*M_PI - abs(hrdeg-mindeg));
	//cout<<k<<endl;
	double relcos=(cos(k));
	double relsin=sin(k);
	double l=relsin*a;
	double base=abs(b-relcos*a);
	//cout<<l<<" "<<(relcos*a)<<endl;
	double hyp=sqrt(base*base+l*l);
	cout<<setprecision(20)<<hyp;
}