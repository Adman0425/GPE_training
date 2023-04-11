#include <iostream>

using namespace std;

struct point{
	int x;
	int y;
};

point p[100];

int main(){
	int n, A, B;
	while(cin>>n && n!=0){
		for(int i=0;i<2*n;i++){/*讀入草莓的位置*/
			cin>>p[i].x>>p[i].y;
		}
		bool flag=false;/*表示還沒找到切割線*/ 
		int right, left;
		
		for(int i=-500;i<=500;i++){/*一組組測試AB是否符合切割線條件*/ 
			for(int j=-500;j<=500;j++){
				right=left=0;
				for(int a=0;a<2*n;a++){
					if(p[a].x*i+p[a].y*j==0) break;/*不能切到草莓*/ 
					if(p[a].x*i+p[a].y*j>0) left++;/*紀錄兩邊的草莓數量*/ 
					if(p[a].x*i+p[a].y*j<0) right++;
				}
				if(left==right && left+right==2*n){/*草莓數量相等，並且總和正確*/ 
					A=i;
					B=j;
					flag = true;/*表示已經找到切割線*/ 
					break;
				}
			}
			if(flag) break;/*找到切割線，因此跳出迴圈*/ 
		}
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}
