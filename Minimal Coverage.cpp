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
            if (L == 0 && R == 0) break;/*兩者皆為0，則結束輸入*/
            seg[N] = {L, R};
            N++;/*計算共有幾個片段*/ 
        }
        
        sort(seg, seg+N);/*排序*/ 
        
		L = 0;
        vector <pii> ans;
        int i = 0;
        while (L < M){
            bool find = false;
            int mxR = 0, mxI = -1;
            
			while (i < N){
                if (seg[i].F <= L){/*找出區段左界最小*/ 
                    find = true;
                    if (seg[i].S > mxR){/*區段右界最大*/ 
                        mxR = seg[i].S;
                        mxI = i;
                    }
                }else break;
                i++;
            }
            if (!find) break;/*沒有符合條件的區段*/ 
            else {
                ans.push_back(seg[mxI]);
                L = mxR;/*將上一個區段的最大右界記做左界，尋找下一個區段*/ 
            }
        }
        
		if (L >= M) {/*此時L是記最大右界*/ 
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
