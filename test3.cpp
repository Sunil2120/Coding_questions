#include <iostream>
using namespace std;
int main() {
    cout << "print statement" << endl;
    double arr[4] = {14.5, 4.0, 10.7, 78.5};
    double *p1 = &arr[0];
    double *p2 = p1 + 3;
    cout << *p2 << " " << p2 - p1;
    return 0;
}


// Testing whether it has changed or not
