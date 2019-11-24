#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    
    cout << 1 << "\n";
    cout << 100 << "\n";
    for(int i=0; i<100; i++) {
        cout << rand() % 1001 << " ";
    }
    cout << "\n";
    for(int i=0; i<100; i++) {
        cout << rand() % 1001 << " ";
    }
    cout << endl;

    return 0;
}