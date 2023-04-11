#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int casenum, step, pos, temp;
	string command;
	vector<int> record;
	
	cin>>casenum;
		
	while(casenum--){
		cin>>step;
		pos=0;
		record.clear();
		
		while(step--){
			
			cin>>command;
			switch(command[0]){
				case'L':
					pos--;
					record.push_back(-1);
					break;
				case'R':
					pos++;
					record.push_back(1);
					break;
				case'S':
					cin>>command>>temp;
					pos+=record[temp-1];
					record.push_back(record[temp-1]);
					break;
			}
		}
		cout<<pos<<endl;
	}
	return 0;
}
