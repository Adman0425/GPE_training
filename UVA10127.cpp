#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		int dig=1, num=1;
		while(num%n!=0){/*�L�k�㰣�A�h��l��*10�A+1*/
			num%=n;
			num= num*10 +1;
			dig++;
		}
		cout<<dig<<endl;
	}
	return 0;
}
