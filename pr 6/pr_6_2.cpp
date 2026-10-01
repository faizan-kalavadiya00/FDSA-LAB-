#include <iostream>
using namespace std;

class Node
{
public:
    string page;
    Node *next;

    Node(string p)
    {
        page = p;
        next = NULL;
    }
};

class Browser
{
    Node *top;
    string currentPage;

public:
    Browser(string page)
    {
        top = NULL;
        currentPage = page;
    }

    void visit(string page)
    {
        Node *newNode = new Node(currentPage);

        newNode->next = top;
        top = newNode;

        currentPage = page;

        cout << "Current Page: " << currentPage << endl;
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "No previous page" << endl;
            cout << "Current Page: " << currentPage << endl;
            return;
        }

        Node *temp = top;

        currentPage = top->page;
        top = top->next;

        delete temp;

        cout << "Current Page: " << currentPage << endl;
    }

    void display()
    {
        cout << "Current Page: " << currentPage << endl;
    }
};

int main()
{
    Browser browser("Home");

    int choice;
    string page;

    do
    {
        cout << endl;
        cout << "----- BROWSER MENU -----" << endl;
        cout << "1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current Page" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter page: ";
                cin >> page;
                browser.visit(page);
                break;

            case 2:
                browser.back();
                break;

            case 3:
                browser.display();
                break;

            case 4:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
