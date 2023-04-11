#include <bits/stdc++.h>

using namespace std;

int main(){
	
	char ch;
	vector<string> com;
	
	ch=getchar();
	while(1){
		if(isdigit(ch)){/*number, need to search the word to replicate*/
			if(ch=='0'){
				break;
			}
			int num=0;
			while(isdigit(ch)){/*the number may have several digits, so remember to get the whole number*/
				num=num*10+(ch-'0');
				ch=getchar();
			}
			int size=com.size();
			string temp=com[size-num];
			com.erase(com.begin()+size-num);
			com.push_back(temp);
			
			cout<<temp;
						
		}else{/*not numbers*/
			if(isalpha(ch)){/*exactly alphabets*/
				string str;
				while(isalpha(ch)){/*get string*/
					str+=ch;
					ch=getchar();
				}
				
				com.push_back(str);
				cout<<str;
				
			}else{/*space or dots, etc.*/
				cout<<ch;
				ch=getchar();
			}
			
		}
		
	}
	return 0;
}
