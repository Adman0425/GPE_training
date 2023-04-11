#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int a[26];/*記錄每一個城市的上一層城市*/
vector<int> city_path[26];/*記錄每一個城市到羅馬的路線*/

int main(){
	int test;
	cin>>test;
	
	int n1, n2;
	string s1, s2;
	
	while(test--){
		int road, des;
		cin>>road>>des;
		
		memset(a, -1, sizeof(a));/*初始化a裡面的所有值*/
		for(int i=0;i<26;i++){
			city_path[i].clear();/*初始化city_path裡的所有值*/
		}
		
		for(int i=0;i<road;i++){
			cin>>s1>>s2;
			n1=s1[0]-'A';/*得到一號城市的首字母作為編碼*/
			n2=s2[0]-'A';/*得到二號城市的首字母作為編碼*/
			a[n2]=n1;/*將一號城市記做二號城市的上層城市*/
		}
		
		int cur;
		for(int i=0;i<26;i++){
			cur=i;
			city_path[i].push_back(cur);/*先將自己本身記入路徑之中*/
			
			while(a[cur]!= -1){/*當此城市存在上層城市時*/ 
				city_path[i].push_back(a[cur]);/*把上層城市的編號記入路徑之中*/
				cur=a[cur];/*繼續尋訪上一層*/ 
			}
		}
		
		for(int i=0;i<des;i++){
			cin>>s1>>s2;
			n1=s1[0]-'A';
			n2=s2[0]-'A';
			int root;
			
			for(int x:city_path[n1]){/*找到兩個城市往羅馬的路徑中最近的重疊點*/ 
				for(int y:city_path[n2]){
					if(x==y){
						root=y;
						break;
					}
				}
				if(x==root) break;/*如果一號城市就是目的地*/
			}
			
			for(int x=0;x<city_path[n1].size();x++){/*先輸出一號城市的路徑*/ 
				if(city_path[n1][x]==root) break;/*遇到重疊點就停止輸出，重疊點留給下面那部分再輸出*/
				cout<<char('A'+city_path[n1][x]);
			}
			
			bool check_root = false;
			for(int x=city_path[n2].size()-1;x>=0;x--){/*記得最後一格沒有東西，要往前一格*/
				if(city_path[n2][x]==root) check_root=true;/*如果是重疊點，則開始列印路徑*/
				if(check_root) cout<<char('A'+city_path[n2][x]);
			}
			cout<<endl;			
		}
	}
}
