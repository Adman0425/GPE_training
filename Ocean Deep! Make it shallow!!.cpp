#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	char s;
	long long ans = 0;
	
	while(s=getchar()){
		if(s==-1) break;
		if(s=='1' || s=='0'){/*讀入二進制數字，注意此時s是字元 ! 不是數字 !*/
			ans = (ans<<1)+s-'0';/*左移，轉成十進位數字儲存*/
			if(ans>=131071){
				ans%=131071;
			} 
		}else if(s=='#'){
			if(ans==0){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
				ans=0;
		}
	}
}
	return 0;
}
