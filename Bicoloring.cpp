#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int visited[200];/*檢查節點是否走過*/ 
int color[200];/*記錄節點顏色1或2*/ 
vector<int>graph[200];/*節點關係*/ 
int check =0;

void dfs(int now){
	visited[now]=1;/*表示尋訪過該點*/
	
	for(int i=0;i<(int)graph[now].size();i++){/*尋訪所有與其連結的點*/ 
		int next = graph[now][i];
		
		if(color[next]==0){/*若相鄰點還沒著色過*/ 
			color[next]=0-color[now];/*設成相反顏色*/ 
		}
		if(color[next]==color[now]){/*若出現相同顏色，記為顏色重複*/
			check++;
		}
		
		if(visited[next]==0){/*若下個點還沒走過，就繼續尋訪*/ 
			dfs(next);
		}
	}
}

int main(){
	int vertex, edge;
	while(cin>>vertex){
		if(vertex==0){/*輸入0即停止*/ 
			return 0;
		}
		
		for(int i=0;i<200;i++){/*初始化陣列*/
			visited[i] = 0;
			color[i] = 0;
			graph[i].clear();
		}
		
		check = 0;/*記得歸零，否則會遺留上次的數字*/
		
		cin>>edge;
		for(int j=0;j<edge;j++){/*建立關係圖*/
			int v1, v2;
			cin>>v1>>v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		
		color[0]=1;
		dfs(0);
		
		if(check){
			cout<<"NOT BICOLORABLE."<<endl;
		}else{
			cout<<"BICOLORABLE."<<endl;
		}
	}
}
