#include <iostream>
using namespace std;

int main(){
    int N, report;
    cin >> N;
    int *arr = new int[N+1];
    for(int i=0;i<N;i++){
        cin >> report;
        arr[report]++;
    }
    int res = 0;
    for(int i=0;i<=N;i++)
        if(!arr[i]) cout << i << " ";
    cout << endl;
    return 0;
}
