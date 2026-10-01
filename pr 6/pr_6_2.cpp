#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node *next;
};

class BrowserHistory
{
private:
    Node *top;

public:
    BrowserHistory()
    {
        top = NULL;
    }

    void visit(string page)
    {
        Node *newNode = new Node();

        newNode->page = page;
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        displayCurrentPage();
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "Error: No history left. Cannot go back.\n";
            return;
        }

        Node *temp = top;
        top = top->next;

        cout << "Going back from: " << temp->page << endl;

        delete temp;

        displayCurrentPage();
    }

    void displayCurrentPage()
    {
        if (top == NULL)
        {
            cout << "Current page: No page\n";
        }
        else
        {
            cout << "Current page: " << top->page << endl;
        }
    }

    ~BrowserHistory()
    {
        while (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    BrowserHistory browser;

    int choice;
    string page;

    while (choice <= 4)
    {
        cout << "\n----- WEB BROWSER -----\n";
        cout << "1. Visit Page\n";
        cout << "2. Back\n";
        cout << "3. Display Current Page\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter page name/URL: ";
            cin >> page;
            browser.visit(page);
            break;

        case 2:
            browser.back();
            break;

        case 3:
            browser.displayCurrentPage();
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