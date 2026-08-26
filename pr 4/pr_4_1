#include <iostream>
using namespace std;

class Node
{
public:
    int token;
    Node *next;

    Node(int value)
    {
        token = value;
        next = NULL;
    }
};

void insertFront(Node *&head, int token)
{
    Node *newNode = new Node(token);

    newNode->next = head;
    head = newNode;
}

void insertEnd(Node *&head, int token)
{
    Node *newNode = new Node(token);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPosition(Node *&head, int token, int position)
{
    if (position <= 0)
    {
        insertFront(head, token);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        insertEnd(head, token);
        return;
    }

    Node *newNode = new Node(token);

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = NULL;

    int operations;

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++)
    {
        int choice;
        int token;
        int position;

        cout << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        // EXIT
        if (choice == 4)
        {
            cout << "Thank you." << endl;
            break;
        }

        cout << "Enter patient token: ";
        cin >> token;

        if (choice == 1)
        {
            insertFront(head, token);
        }
        else if (choice == 2)
        {
            insertEnd(head, token);
        }
        else if (choice == 3)
        {
            cout << "Enter position: ";
            cin >> position;

            insertPosition(head, token, position);
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        cout << "Current Queue: ";
        display(head);
    }

    return 0;
}