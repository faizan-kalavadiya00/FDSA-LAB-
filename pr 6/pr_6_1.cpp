#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
private:
    int stack[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int tray)
    {
        if (isFull())
        {
            cout << "Error: Stack is full. Cannot place tray.\n";
            return;
        }

        top++;
        stack[top] = tray;

        cout << "Tray " << tray << " placed successfully.\n";
        displayTop();
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty. Cannot take tray.\n";
            return;
        }

        cout << "Tray " << stack[top] << " taken.\n";
        top--;

        displayTop();
    }

    void displayTop()
    {
        if (isEmpty())
        {
            cout << "Current top: No tray (Stack is empty)\n";
        }
        else
        {
            cout << "Current top tray: " << stack[top] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, tray;

   while(choice<=4) 
    {
        cout << "\n----- CAFETERIA TRAY STACK -----\n";
        cout << "1. Place Tray\n";
        cout << "2. Take Tray\n";
        cout << "3. Display Top Tray\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter tray number: ";
            cin >> tray;
            s.push(tray);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.displayTop();
            break;

        case 4:
            cout << "Program terminated.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    
    } 

    return 0;
}