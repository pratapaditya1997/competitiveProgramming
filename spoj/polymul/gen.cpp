#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    
    cout << 1 << "\n";
    cout << 9 << "\n";
    for(int i=0; i<10; i++) {
        cout << rand() % 9999 + 2 << " ";
    }
    cout << "\n";
    for(int i=0; i<10; i++) {
        cout << rand() % 9999 + 2 << " ";
    }
    cout << endl;

    return 0;
}