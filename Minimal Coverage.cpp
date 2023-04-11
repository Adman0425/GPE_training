#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pii pair<int,int>
#define F first
#define S second
 
pii seg[100005];
 
int main() {
    int T, M;
    cin >> T;/*testcase*/
    
	while (T--){
        cin >> M;
        int L, R, N = 0;
        
		while (cin >> L >> R){
            if (L == 0 && R == 0) break;/*��̬Ҭ�0�A�h������J*/
            seg[N] = {L, R};
            N++;/*�p��@���X�Ӥ��q*/ 
        }
        
        sort(seg, seg+N);/*�Ƨ�*/ 
        
		L = 0;
        vector <pii> ans;
        int i = 0;
        while (L < M){
            bool find = false;
            int mxR = 0, mxI = -1;
            
			while (i < N){
                if (seg[i].F <= L){/*��X�Ϭq���ɳ̤p*/ 
                    find = true;
                    if (seg[i].S > mxR){/*�Ϭq�k�ɳ̤j*/ 
                        mxR = seg[i].S;
                        mxI = i;
                    }
                }else break;
                i++;
            }
            if (!find) break;/*�S���ŦX���󪺰Ϭq*/ 
            else {
                ans.push_back(seg[mxI]);
                L = mxR;/*�N�W�@�ӰϬq���̤j�k�ɰO�����ɡA�M��U�@�ӰϬq*/ 
            }
        }
        
		if (L >= M) {/*����L�O�O�̤j�k��*/ 
            cout << ans.size() << "\n";
            for (auto i: ans){
                cout << i.F << " " << i.S << "\n";
            }
        } else {
            cout << "0\n";
        }
        cout << "\n";
    }
    return 0;
}
