#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int isprime[50000], prime[50000];
int primelist(int n){
	memset(isprime, 1, sizeof(isprime));/*初始化，將1當作是質數*/
	isprime[0]=isprime[1]=0;
	int pcnt=0;
	
	for(int i=2;i<n;i++){
		if(isprime[i]){
			prime[pcnt++]=i;
			for(int j=i*i;j<n;j+=i){
				isprime[j]=0;
			}
		}
	}
	return pcnt;
}

int plist[1000001], ans[1000001];
int calclist(int pcnt, int l, int u){
	memset(plist, 0, sizeof(plist));
	
	for(int i=0;i<pcnt;i++){
		int s=(l-1)/prime[i]+1;
		if(s<2) s=2;
		for()
	}
}
