#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		int dig=1, num=1;
		while(num%n!=0){/*無法整除，則把餘數*10再+1*/
			num%=n;
			num= num*10 +1;
			dig++;
		}
		cout<<dig<<endl;
	}
	return 0;
}
