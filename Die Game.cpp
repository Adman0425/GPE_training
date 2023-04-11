#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int step;
	while(cin>>step && step!=0){
		string command;
		int temp;
		int dice[3]={1, 2, 3};/*top, north, west*/
		
		for(int i=0;i<step;i++){
			cin>>command;
			temp=dice[0];/*top*/
			
			if(command.compare("north")==0){
				dice[0]=7-dice[1];
				dice[1]=temp;
			}else if(command.compare("south")==0){
				dice[0]=dice[1];
				dice[1]=7-temp;
			}else if(command.compare("east")==0){
				dice[0]=dice[2];
				dice[2]=7-temp;
			}else if(command.compare("west")==0){
				dice[0]=7-dice[2];
				dice[2]=temp;
			}
		}
		cout<<dice[0]<<endl;
	}
	return 0;
}
