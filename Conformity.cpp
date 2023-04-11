#include <bits/stdc++.h>

using namespace std;

int main(){
	
	map<string, int> course;
	vector<string> course_no;
	int total, max;
	int test;
	string input, line;
	while(cin>>test && test!=0){
		total=0;
		max=0;
		course.clear();
		
		for(int i=0;i<test;i++){
			line.clear();
			course_no.clear();
			
			for(int j=0;j<5;j++){
				cin>>input;
				course_no.push_back(input);/*get the combination and then sort it*/
			}
			sort(course_no.begin(), course_no.end());
			for(int j=0;j<5;j++){
				line+=course_no[j];
			}
			course[line]++;/*if somebody choose the course combination, +1*/
		}
		for(auto it=course.begin();it!=course.end();it++){
			if(it->second>max){
				max=it->second;
			}
		}
		for(auto it=course.begin();it!=course.end();it++){
			if(it->second==max){
				total+=max;/*if there are several popular combination, then calculate total people*/
			}
		}
		cout<<total<<endl;
	}
}
