#include <bits/stdc++.h>

using namespace std;

int main(){
	long long s, d;
	while(cin>>s>>d){
		while(d!=0){
			d-=s;
			if(d<=0){
				cout<<s<<endl;
				break;
			}else{
				s++;
			}
		}
	}
	return 0;
} 
