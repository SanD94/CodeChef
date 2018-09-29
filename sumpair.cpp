#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 100010

int main(){
    int T,N,D;
    cin >> T;
    while(T--){
	cin >> N >> D;
	int arr[MAXN];
	for(int i=0;i<N;i++) cin >> arr[i];
	sort(arr,arr+N);
	long long int res = 0;
	for(int i=N-1;i>=0;i--) 
	    if(i > 0 && arr[i]-arr[i-1] < D) {
		res += arr[i]+arr[i-1];
		i--;
	    }

	cout << res << endl;
    }

    return 0;
}
