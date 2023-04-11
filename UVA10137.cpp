#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	double stu[1000], sum, sum1, sum2, avg;
	int n;
	
	while(cin>>n){
		if(n==0) break;/*Ū��0�N����*/
		sum=sum1=sum2=avg=0;
		
		for(int i=0;i<n;i++){
			cin>>stu[i];
			sum+=stu[i]*100;/**100�ӭp���`�X*/
		}
		avg=(double)sum/n;
		avg=floor(avg+0.5)/100.0;/*��X�������u����*/ 
		
		for(int i=0;i<n;i++){
			if(stu[i]>avg){/*�h�I*/ 
				sum1+=stu[i]-avg;
			}else{/*�֥I*/ 
				sum2+=avg-stu[i];
			}
		}
		if(sum1<sum2){
			cout<<"$"<<fixed<<setprecision(2)<<sum1<<endl;
		}else{
			cout<<"$"<<fixed<<setprecision(2)<<sum2<<endl;
		}
	}
	return 0;
}
