#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int test;/*有幾組測試*/
	cin>>test;
	
	int house[500]={0};/*用來記錄每一家的門牌號碼*/ 
	int people;/*這一組中有幾家*/ 
	int distance[test]={0};/*用來記錄該組的距離總和*/ 
	int i=0;
	
	for(i=0;i<test;i++){
		cin>>people;
		for(int j=0;j<people;j++){/*讀入門牌號碼*/ 
			int num;
			cin>>num;
			house[j]=num;
		}
		
		sort(house, house+people);/*升序排序門牌號碼*/ 
		/*for(int j=0;j<people;j++){
			cout<<house[j]<<" ";
		}*/
				
		int mid = floor(people/2);/*取得中位數*/ 
		/*cout << mid<<endl;*/
		int des = house[mid];/*取得中位數的門牌號*/ 
		/*cout << des <<endl;*/
		
		for(int j=0;j<people;j++){/*計算該組距離和*/ 
			distance[i]+= abs(house[j]-des);
			/*cout << distance <<" ";*/
		}
		
	}
	for(int a=0;a<test;a++){/*輸出結果*/ 
		cout << distance[a] <<endl;
	}
	
	return 0; 
}
