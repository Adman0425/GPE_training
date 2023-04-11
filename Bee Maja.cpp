#include <bits/stdc++.h>

using namespace std;

int offset[5][2]={{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
pair<int, int> maja[102000];

int main(){
	for(int i=1, j=1, k=0;i<100200;i+=j, j+=6, k++){
		maja[i]=make_pair(0, k);
		for(int a=0;a<k;a++){
			maja[i-a]=make_pair(a, k-a);/*right down side*/
		}
		int cur=i;
		for(int m=0;m<5;m++){
			for(int n=0;n<k;n++){
				int x=maja[cur].first+offset[m][0];
				int y=maja[cur].second+offset[m][1];
				maja[cur+1]=make_pair(x, y);
				cur++;
			}
		}
	}
	int wille;
	while(cin>>wille){
		cout<<maja[wille].first<<" "<<maja[wille].second<<endl;
	}
	return 0;
}
