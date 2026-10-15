#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    int lastDigit = abs(n % 10);

    // a) Check if the number is even
    if (n % 2 == 0) {
        cout << "a) The number is even." << endl;
    } else {
        cout << "a) The number is odd." << endl;
    }

    // b) Check if the number ends with 7
    if (lastDigit == 7) {
        cout << "b) The number ends with 7." << endl;
    } else {
        cout << "b) The number does not end with 7." << endl;
    }

    // c) Check if the last digit is even
    if (lastDigit % 2 == 0) {
        cout << "c) The last digit is even." << endl;
    } else {
        cout << "c) The last digit is odd." << endl;
    }

    return 0;
}
