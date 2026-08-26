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

void deleteByValue(Node *&head, int token)
{
    if (head == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    if (head->token == token)
    {
        Node *temp = head;
        head = head->next;

        delete temp;

        cout << "Token deleted" << endl;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->token == token)
        {
            Node *deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Token deleted" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Token not found" << endl;
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

void reverseDisplay(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    reverseDisplay(head->next);

    cout << head->token << " ";
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
        cout << "4. Delete Token" << endl;
        cout << "5. Display Front to Back" << endl;
        cout << "6. Display Back to Front" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient token: ";
            cin >> token;

            insertFront(head, token);
        }
        else if (choice == 2)
        {
            cout << "Enter patient token: ";
            cin >> token;

            insertEnd(head, token);
        }
        else if (choice == 3)
        {
            cout << "Enter patient token: ";
            cin >> token;

            cout << "Enter position: ";
            cin >> position;

            insertPosition(head, token, position);
        }
        else if (choice == 4)
        {
            cout << "Enter patient token to delete: ";
            cin >> token;

            deleteByValue(head, token);
        }
        else if (choice == 5)
        {
            cout << "Queue from Front to Back: ";
            display(head);
        }
        else if (choice == 6)
        {
            cout << "Queue from Back to Front: ";
            reverseDisplay(head);
            cout << endl;
        }
        else if (choice == 7)
        {
            cout << "Program ended" << endl;
            break;
        }

        if (choice >= 1 && choice <= 4)
        {
            cout << "Current Queue: ";
            display(head);
        }
    }

    return 0;
}