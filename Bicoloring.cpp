#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int visited[200];/*�ˬd�`�I�O�_���L*/ 
int color[200];/*�O���`�I�C��1��2*/ 
vector<int>graph[200];/*�`�I���Y*/ 
int check =0;

void dfs(int now){
	visited[now]=1;/*��ܴM�X�L���I*/
	
	for(int i=0;i<(int)graph[now].size();i++){/*�M�X�Ҧ��P��s�����I*/ 
		int next = graph[now][i];
		
		if(color[next]==0){/*�Y�۾F�I�٨S�ۦ�L*/ 
			color[next]=0-color[now];/*�]���ۤ��C��*/ 
		}
		if(color[next]==color[now]){/*�Y�X�{�ۦP�C��A�O���C�⭫��*/
			check++;
		}
		
		if(visited[next]==0){/*�Y�U���I�٨S���L�A�N�~��M�X*/ 
			dfs(next);
		}
	}
}

int main(){
	int vertex, edge;
	while(cin>>vertex){
		if(vertex==0){/*��J0�Y����*/ 
			return 0;
		}
		
		for(int i=0;i<200;i++){/*��l�ư}�C*/
			visited[i] = 0;
			color[i] = 0;
			graph[i].clear();
		}
		
		check = 0;/*�O�o�k�s�A�_�h�|��d�W�����Ʀr*/
		
		cin>>edge;
		for(int j=0;j<edge;j++){/*�إ����Y��*/
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
