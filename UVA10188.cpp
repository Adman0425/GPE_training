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
		getchar();/*�O�o��������Ÿ�*/
		
		for(int i=0;i<n;i++){
			getline(cin, input);
			if(i){
				answer+='\n';/*�Ĥ@��H�~����ƴN�[�W����Ÿ��A�M���᭱�����W�h*/
				answer+=input;
			}else{
				answer=input;
			}
		}
		
		scanf("%d", &m);
		getchar();/*�O�o��������Ÿ�*/
		
		for(int i=0;i<m;i++){
			getline(cin, input);
			if(i){
				output+='\n';/*�Ĥ@��H�~����ƴN�[�W����Ÿ��A�M���᭱�����W�h*/
				output+=input;
			}else{
				output=input;
			}
		}
		
		ac=true;
		if(answer!=output){
			ac=false;
		}
		if(ac){/*�p�Gac�A�N��Xac�A�íp��runcase*/
			cout<<"Run #"<<runcase<<": Accepted"<<endl;
			runcase++;
			cout<<runcase<<endl;
			continue;/*�^��̥~�骺while*/ 
		}
		
		pe=true;
		for(int i=0;i<answer.length();i++){
			if(!isdigit(answer[i])){/*��Ҧ��r���R���A����Ʀr�O�_���T�A�Y�Ʀr���T�o�Dac�A���N�Ope*/
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
