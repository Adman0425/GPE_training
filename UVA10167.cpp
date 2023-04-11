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
		for(int i=0;i<2*n;i++){/*Ū�J�������m*/
			cin>>p[i].x>>p[i].y;
		}
		bool flag=false;/*����٨S�����νu*/ 
		int right, left;
		
		for(int i=-500;i<=500;i++){/*�@�ղմ���AB�O�_�ŦX���νu����*/ 
			for(int j=-500;j<=500;j++){
				right=left=0;
				for(int a=0;a<2*n;a++){
					if(p[a].x*i+p[a].y*j==0) break;/*���������*/ 
					if(p[a].x*i+p[a].y*j>0) left++;/*�������䪺����ƶq*/ 
					if(p[a].x*i+p[a].y*j<0) right++;
				}
				if(left==right && left+right==2*n){/*����ƶq�۵��A�åB�`�M���T*/ 
					A=i;
					B=j;
					flag = true;/*��ܤw�g�����νu*/ 
					break;
				}
			}
			if(flag) break;/*�����νu�A�]�����X�j��*/ 
		}
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}
