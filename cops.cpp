#include <iostream>

using namespace std;


int main(){

    int T,x,y,M;

    cin >> T;
    while(T--){
	cin >> M >> x >> y;
	int range = x*y, cops;
	int houses[102] = {};
	for(int i=0;i<M;i++) {
	    cin >> cops;
	    int start = cops-range <= 0 ? 1 : cops-range;
	    int end = cops+range+1 > 100 ? 101 : cops+range+1;
	    houses[start] ++;
	    houses[end] --;
	}
	int res=0;
	int secure = 0;
	for(int i=1;i<=100;i++){
	    secure += houses[i];
	    if(!secure) res++;
	}
	cout << res << endl;
    }

    return 0;
}
