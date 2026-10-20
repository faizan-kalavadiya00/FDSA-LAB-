#include <array>
#include <iostream>
using namespace std;

constexpr int TABLE_SIZE = 10;

int main() {
    array<long long, TABLE_SIZE> table{};
    array<bool, TABLE_SIZE> occupied{};

    int n;
    cout << "Enter the number of vehicle registrations: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid number of registrations.\n";
        return 1;
    }

    cout << "Enter the registration numbers:\n";
    for (int i = 0; i < n; ++i) {
        long long registration;
        if (!(cin >> registration)) {
            cout << "Invalid registration number.\n";
            return 1;
        }

       
        int index = static_cast<int>((registration % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE);
        bool placed = false;

       
        for (int probe = 0; probe < TABLE_SIZE; ++probe) {
            if (!occupied[index]) {
                table[index] = registration;
                occupied[index] = true;
                placed = true;
                cout << "Vehicle " << registration << " assigned to slot " << index << ".\n";
                break;
            }
            index = (index + 1) % TABLE_SIZE; 
        }

        if (!placed) {
            cout << "Parking lot is full. Vehicle " << registration
                 << " could not be parked.\n";
        }
    }

    cout << "\nFinal parking table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Slot " << i << ": ";
        if (occupied[i]) cout << table[i];
        else cout << "Empty";
        cout << '\n';
    }

    return 0;
}
