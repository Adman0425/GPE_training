#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int test;/*���X�մ���*/
	cin>>test;
	
	int house[500]={0};/*�ΨӰO���C�@�a�����P���X*/ 
	int people;/*�o�@�դ����X�a*/ 
	int distance[test]={0};/*�ΨӰO���Ӳժ��Z���`�M*/ 
	int i=0;
	
	for(i=0;i<test;i++){
		cin>>people;
		for(int j=0;j<people;j++){/*Ū�J���P���X*/ 
			int num;
			cin>>num;
			house[j]=num;
		}
		
		sort(house, house+people);/*�ɧǱƧǪ��P���X*/ 
		/*for(int j=0;j<people;j++){
			cout<<house[j]<<" ";
		}*/
				
		int mid = floor(people/2);/*���o�����*/ 
		/*cout << mid<<endl;*/
		int des = house[mid];/*���o����ƪ����P��*/ 
		/*cout << des <<endl;*/
		
		for(int j=0;j<people;j++){/*�p��ӲնZ���M*/ 
			distance[i]+= abs(house[j]-des);
			/*cout << distance <<" ";*/
		}
		
	}
	for(int a=0;a<test;a++){/*��X���G*/ 
		cout << distance[a] <<endl;
	}
	
	return 0; 
}
