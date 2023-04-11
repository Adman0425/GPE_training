#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>

using namespace std;

int main(){
	int n, m, runcase=1;
	string answer, input, output;
	bool ac, pe;
	
	while(scanf("%d", &n)!=EOF && n!=0){
		getchar();/*記得跳掉換行符號*/
		
		for(int i=0;i<n;i++){
			getline(cin, input);
			if(i){
				answer+='\n';/*第一行以外的行數就加上換行符號，然後把後面的接上去*/
				answer+=input;
			}else{
				answer=input;
			}
		}
		
		scanf("%d", &m);
		getchar();/*記得跳掉換行符號*/
		
		for(int i=0;i<m;i++){
			getline(cin, input);
			if(i){
				output+='\n';/*第一行以外的行數就加上換行符號，然後把後面的接上去*/
				output+=input;
			}else{
				output=input;
			}
		}
		
		ac=true;
		if(answer!=output){
			ac=false;
		}
		if(ac){/*如果ac，就輸出ac，並計算runcase*/
			cout<<"Run #"<<runcase<<": Accepted"<<endl;
			runcase++;
			cout<<runcase<<endl;
			continue;/*回到最外圈的while*/ 
		}
		
		pe=true;
		for(int i=0;i<answer.length();i++){
			if(!isdigit(answer[i])){/*把所有字元刪掉，比較數字是否正確，若數字正確卻非ac，那就是pe*/
				answer.erase(i, 1);
				i--;
			}
		}
		for(int i=0;i<output.length();i++){
			if(!isdigit(output[i])){
				output.erase(i, 1);
				i--;
			}
		}
		if(answer!=output){
			pe=false;
		}
		if(pe){
			cout<<"Run #"<<runcase<<": Presentation Error"<<endl;
			runcase++;
			continue;
		}
		
		cout<<"Run #"<<runcase<<": Wrong Answer"<<endl;
		runcase++;
	}
	
	return 0;
}
