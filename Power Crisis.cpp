#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main(){
	int region, n, g;
	while(scanf("%d", &region)==1 && region!=0){
		region--;
		/*�O�o-1�A�]���Ĥ@�Ӱϰ�|���Q�_�q*/
		
		for(n=1;n<region;n++){
			g=0;
			for(int m=1;m<=region;m++){
			/*���ͳ̫�@�ϰ��q�s��*/
				g = (g+n)%m;	
			}
			if(g==11){
				break;
				/*�p�G�O13�ϴN��ܧ�쵪��*/ 
			}
		}
		printf("%d\n", n);
	}
	return 0;
}
