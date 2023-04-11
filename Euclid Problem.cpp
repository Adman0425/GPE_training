#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int gcd(int A, int B, int&X, int&Y){
	if(A%B==0){
		X=0;
		Y=1;
		return B;
	}
	
	if(B%A==0){
		Y=0;
		X=1;
		return A;
	}
	
	if(A>=B){
		int x, y;
		int value=gcd(A+B*(-A/B), B, x, y);
		X=x;
		Y=y+x*(-A/B);
		return value;
	}
	
	if(B>=A){
		int x, y;
		int value=gcd(A, B+A*(-B/A), x, y);
		X=x+y*(-B/A);
		Y=y;
		return value;
	}
}

int main(){
	int a, b, value;
	while(cin>>a>>b){
		int X, Y;
		int value=gcd(a, b, X, Y);
		cout<<X<<" "<<Y<<" "<<value<<endl;
	}
	return 0;
}
