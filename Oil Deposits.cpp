#include <bits/stdc++.h>

using namespace std;

void visit(bool isvisited[][105], char map[][105], int a, int b){
	if(map[a][b]=='@' && !isvisited[a][b]){
		isvisited[a][b]=true;
		
		visit(isvisited, map, a-1, b);
		visit(isvisited, map, a+1, b);
		visit(isvisited, map, a, b+1);
		visit(isvisited, map, a, b-1);
		visit(isvisited, map, a-1, b+1);
		visit(isvisited, map, a-1, b-1);
		visit(isvisited, map, a+1, b+1);
		visit(isvisited, map, a+1, b-1);
	}
}

int main(){
	
	int m, n;
	
	while(~scanf("%d%d", &m, &n) && m!=0){
		int oilcount=0;
		char map[105][105]={0};
		bool isvisited[105][105]={0};
		
		gets(map[0]);
		
		for(int a=1;a<=m;a++){
			gets(map[a]+1);
		}
		
		for(int a=1;a<=m;a++){
			for(int b=1;b<=n;b++){
				if(map[a][b]=='@' && !isvisited[a][b]){
					oilcount++;
					visit(isvisited, map, a, b);
				}
			}
		}
		cout<<oilcount<<endl;
	}
	return 0;
}
