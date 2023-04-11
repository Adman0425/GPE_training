#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m;
	int milk[1000005];
	
	while(cin>>n>>m){
		
		int left=0, right=0, mid=0;
		
		for(int i=0;i<n;i++){
			cin>>milk[i];
			right+=milk[i];
			if(milk[i]>left) left=milk[i];
		}
				
		while(left<right){
			
			int sum=0, amount=0;
			mid=(left+right)/2;
			
			for(int j=0;j<n;j++){
				sum+=milk[j];
				
				if(sum>mid){
					amount++;
					sum=milk[j];
				}else if(sum==mid){
					amount++;
					sum=0;
				}
			}
			if(sum>0) amount++;
		
			if(amount>m){
				left=mid+1;
			}else{
				right=mid;
			}
		}
		
		cout<<left<<endl;
	}
	return 0;
} 
