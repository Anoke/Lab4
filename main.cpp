#include <iostream>
#include "fun.h"
using namespace std;
using namespace fun;

int main() {
    Menu m;
    int f1 = 1;

    while (f1 == 1) {
        m.choseFunc();
        m.runFunc();

        cout << "Continue?"<<endl;
        cout << "1 - Yes"<<endl;
        cout << "2 - No"<<endl;

        cin >> f1;
    }
    return 0;
}