#include <array>
#include <iostream>
using namespace std;

constexpr int TABLE_SIZE = 10;

int primaryHash(long long id) {
    return static_cast<int>((id % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE);
}

int secondaryHash(long long id) {
    // For a table of size 10, these jump sizes are all relatively prime to 10.
    // Therefore, a probe sequence can reach every slot instead of cycling through a subset.
    constexpr int jumpSizes[4] = {1, 3, 7, 9};
    int index = static_cast<int>((id % 4 + 4) % 4);
    return jumpSizes[index];
}

int main() {
    array<long long, TABLE_SIZE> table{};
    array<bool, TABLE_SIZE> occupied{};

    int n;
    cout << "Enter the number of student IDs: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid number of student IDs.\n";
        return 1;
    }

    cout << "Enter the student IDs:\n";
    for (int i = 0; i < n; ++i) {
        long long id;
        if (!(cin >> id)) {
            cout << "Invalid student ID.\n";
            return 1;
        }

        int first = primaryHash(id);
        int jump = secondaryHash(id);
        bool placed = false;

        // The second hash determines the jump after a collision.
        for (int attempt = 0; attempt < TABLE_SIZE; ++attempt) {
            int index = (first + attempt * jump) % TABLE_SIZE;
            if (!occupied[index]) {
                table[index] = id;
                occupied[index] = true;
                placed = true;
                cout << "Student ID " << id << " assigned to slot " << index
                     << " (jump " << jump << ").\n";
                break;
            }
        }

        if (!placed) {
            cout << "Hash table is full. Student ID " << id
                 << " could not be inserted.\n";
        }
    }

    cout << "\nFinal hash table (double hashing):\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Slot " << i << ": ";
        if (occupied[i]) cout << table[i];
        else cout << "Empty";
        cout << '\n';
    }

    return 0;
}
