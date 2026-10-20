#include <iostream>
#include <list>
#include <vector>
using namespace std;

constexpr int TABLE_SIZE = 10;

int hashCode(long long code) {
    
    return static_cast<int>((code % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE);
}

int main() {
    vector<list<long long>> shelves(TABLE_SIZE);

    int n;
    cout << "Enter the number of book codes: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid number of book codes.\n";
        return 1;
    }

    cout << "Enter the book codes:\n";
    for (int i = 0; i < n; ++i) {
        long long code;
        if (!(cin >> code)) {
            cout << "Invalid book code.\n";
            return 1;
        }

        int shelf = hashCode(code);
        shelves[shelf].push_back(code);
    }

    cout << "\nFinal shelf contents (chaining):\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Shelf " << i << ": ";
        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            for (long long code : shelves[i]) {
                cout << code << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
