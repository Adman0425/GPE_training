#include <bits/stdc++.h>

using namespace std;

const int maxn=50005;

struct Tire{
	int sz;
	map<string, int> g[maxn];
	
	void init();
	void insert(string s);
	void put(int u, int d);
}tree;

int main(){
	int n;
	string s;
	while(cin>>n && n){
		tree.init();
		for(int i=0;i<n;i++){
			cin>>s;
			s+='\\';
			tree.insert(s);
		}
		tree.put(0, 0);
		cout<<endl;
	}
	return 0;
}

void Tire::init(){
	sz=1;
	g[0].clear();
}

void Tire::insert(string s){
	int u=0;
	string word="";
	for(int i=0;i<s.length();i++){
		if(s[i]=='\\'){/*read reach to the end*/
			if(!g[u].count(word)){/*no such path existed yet*/
				g[sz].clear();/*clear the next space*/
				g[u][word]=sz++;
			}
			u=g[u][word];
			word="";
		}else{
			word+=s[i];
		}
	}
}

void Tire::put(int u, int d){
	for(auto it=g[u].begin();it!=g[u].end();it++){
		for(int j=0;j<d;j++){
			cout<<" ";
		}
		cout<<it->first<<endl;
		put(it->second, d+1);
	}
}
