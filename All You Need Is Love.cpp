#include <bits/stdc++.h>

using namespace std;

int gcd(int n1, int n2){
	return n2==0? n1:gcd(n2, n1%n2);
}

int main(){
	int test, case_num=1;
	cin>>test;
	for(int i=0;i<test;i++){
		string s1, s2;
		cin>>s1>>s2;
		int n1=stoi(s1, nullptr, 2);
		int n2=stoi(s2, nullptr, 2);
		if(gcd(n1, n2)!=1){/*not mutual primed*/
			cout<<"Pair #"<<case_num<<": All you need is love!"<<endl;
			case_num++;
		}else{
			cout<<"Pair #"<<case_num<<": Love is not all you need!"<<endl;
			case_num++;
		}
	}
}
