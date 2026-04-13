#include <iostream>
using namespace std;
void print7(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << " ";
        }
        for (int j = 0; j < (2 * (n - i)) - 1; j++) {
            cout << "*";
        }
        for (int j = 0; j <= i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n) {
    for (int i = 0; i < n * 2; i++) {
        if (i < 5) {
            for (int j = 0; j < n - i; j++) {
                cout << " ";
            }
            for (int j = 0; j < (2 * i) + 1; j++) {
                cout << "*";
            }
            for (int j = 0; j < n - i; j++) {
                cout << " ";
            }
        }
        else {
            int newI = i - n;
            for (int j = 0; j <= newI; j++) {
                cout << " ";
            }
            for (int j = 0; j < (2 * (n - newI)) - 1; j++) {
                cout << "*";
            }
            for (int j = 0; j <= newI; j++) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print10(int n) {
    for (int i = 0; i < (2 * n) - 1; i++) {

        if (i < n) {
            for (int j = 0; j < i + 1; j++) {
                cout << "*";
            }
        }
        else {
            int newI = i - n;
            for (int j = 0; j < n - newI - 1; j++) {
                cout << "*";
            }
        }

        cout << endl;
    }
}
void print11(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if ((i + j) % 2 == 0) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
}
void print12(int n) {
    int startingSpaces = n + 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1;
        }
        for (int j = 0; j < startingSpaces; j++) {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++) {
            cout << i - j + 1;
        }
        cout << endl;
        startingSpaces -= 2;
    }
}
void print13(int n) {
    int count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << count << " ";
            count++;
        }

        cout << endl;
    }
}
void print14(int n) {
    for (int i = 0; i < n; i++) {
        for (char j = 'A'; j < 'A' + i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print17(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (char j = 'A'; j < 'A' + i; j++) {
            cout << j;
        }
        for (int j = 0; j < n - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}