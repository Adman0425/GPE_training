#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	double stu[1000], sum, sum1, sum2, avg;
	int n;
	
	while(cin>>n){
		if(n==0) break;/*讀到0就結束*/
		sum=sum1=sum2=avg=0;
		
		for(int i=0;i<n;i++){
			cin>>stu[i];
			sum+=stu[i]*100;/**100來計算總合*/
		}
		avg=(double)sum/n;
		avg=floor(avg+0.5)/100.0;/*算出平均分攤的錢*/ 
		
		for(int i=0;i<n;i++){
			if(stu[i]>avg){/*多付*/ 
				sum1+=stu[i]-avg;
			}else{/*少付*/ 
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
