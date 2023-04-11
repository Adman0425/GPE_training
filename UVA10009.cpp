#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int a[26];/*�O���C�@�ӫ������W�@�h����*/
vector<int> city_path[26];/*�O���C�@�ӫ�����ù�������u*/

int main(){
	int test;
	cin>>test;
	
	int n1, n2;
	string s1, s2;
	
	while(test--){
		int road, des;
		cin>>road>>des;
		
		memset(a, -1, sizeof(a));/*��l��a�̭����Ҧ���*/
		for(int i=0;i<26;i++){
			city_path[i].clear();/*��l��city_path�̪��Ҧ���*/
		}
		
		for(int i=0;i<road;i++){
			cin>>s1>>s2;
			n1=s1[0]-'A';/*�o��@�����������r���@���s�X*/
			n2=s2[0]-'A';/*�o��G�����������r���@���s�X*/
			a[n2]=n1;/*�N�@�������O���G���������W�h����*/
		}
		
		int cur;
		for(int i=0;i<26;i++){
			cur=i;
			city_path[i].push_back(cur);/*���N�ۤv�����O�J���|����*/
			
			while(a[cur]!= -1){/*�������s�b�W�h������*/ 
				city_path[i].push_back(a[cur]);/*��W�h�������s���O�J���|����*/
				cur=a[cur];/*�~��M�X�W�@�h*/ 
			}
		}
		
		for(int i=0;i<des;i++){
			cin>>s1>>s2;
			n1=s1[0]-'A';
			n2=s2[0]-'A';
			int root;
			
			for(int x:city_path[n1]){/*����ӫ�����ù�������|���̪񪺭��|�I*/ 
				for(int y:city_path[n2]){
					if(x==y){
						root=y;
						break;
					}
				}
				if(x==root) break;/*�p�G�@�������N�O�ت��a*/
			}
			
			for(int x=0;x<city_path[n1].size();x++){/*����X�@�����������|*/ 
				if(city_path[n1][x]==root) break;/*�J�쭫�|�I�N�����X�A���|�I�d���U���������A��X*/
				cout<<char('A'+city_path[n1][x]);
			}
			
			bool check_root = false;
			for(int x=city_path[n2].size()-1;x>=0;x--){/*�O�o�̫�@��S���F��A�n���e�@��*/
				if(city_path[n2][x]==root) check_root=true;/*�p�G�O���|�I�A�h�}�l�C�L���|*/
				if(check_root) cout<<char('A'+city_path[n2][x]);
			}
			cout<<endl;			
		}
	}
}
