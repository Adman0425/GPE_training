#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, n;
	map<string, int> dic;
	
	while(cin>>m>>n){
		for(int i=0;i<m;i++){
			char temp[20];
			int num;
			scanf("%s%d", temp, &num);
			dic[string(temp)]=num;
		}
		
		for(int i=0;i<n;i++){
			string essay;
			int sum=0;
			while(cin>>essay && essay!="."){
				sum+=dic[essay];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
