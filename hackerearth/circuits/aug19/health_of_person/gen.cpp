#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int main(){
    freopen("test_case.txt","w",stdout);
    srand(time(0));
    clock_t start = clock();

    cout << 1 << endl;
    cout << N << " " << N << endl;
    for(int i=0;i<N;i++){
        cout << rand() << " ";
    }
    cout << endl;
    for(int i=0;i<N;i++){
        cout << rand() << " ";
    }

    clock_t end = clock();
    cerr << "Time: " << (double)(end-start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
