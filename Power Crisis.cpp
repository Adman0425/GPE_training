#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main(){
	int region, n, g;
	while(scanf("%d", &region)==1 && region!=0){
		region--;
		/*記得-1，因為第一個區域會先被斷電*/
		
		for(n=1;n<region;n++){
			g=0;
			for(int m=1;m<=region;m++){
			/*產生最後一區停電編號*/
				g = (g+n)%m;	
			}
			if(g==11){
				break;
				/*如果是13區就表示找到答案*/ 
			}
		}
		printf("%d\n", n);
	}
	return 0;
}
