#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(){
	
	int c;
	cin>>c;
	for(int i=0;i<c;i++){
		int ins, p=0, a[101];/*an array to record the instruction*/
		cin>>ins;
		string s;
		getline(cin, s);/*get enter*/
		for(int j=0;j<ins;j++){
			getline(cin, s);
			//cout<<s<<endl;
			if(s=="LEFT"){
				a[j]=-1;
			}else if(s=="RIGHT"){
				a[j]=1;
			}else{
				int index;
				string s1, s2;
				stringstream ss(s);
				ss>>s1>>s2>>index;
				a[j]=a[index-1];
			}
			p+=a[j];
		}
		
		cout<<p<<endl;
	}
	
	
	return 0;
} 
