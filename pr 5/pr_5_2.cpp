#include <iostream>
#include <string>
using namespace std;

struct SNode
{
    string name;
    SNode *next;
};

SNode *shead = NULL;

void singlyJoin(string name, int position)
{
    SNode *newNode = new SNode();
    newNode->name = name;

    if (shead == NULL)
    {
        shead = newNode;
        newNode->next = shead;
        return;
    }

    if (position <= 1)
    {
        SNode *last = shead;

        while (last->next != shead)
            last = last->next;

        newNode->next = shead;
        last->next = newNode;
        shead = newNode;
        return;
    }

    SNode *temp = shead;

    for (int i = 1; i < position - 1 && temp->next != shead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void singlyLeave(string name)
{
    if (shead == NULL)
        return;

    SNode *current = shead;
    SNode *previous = NULL;

    do
    {
        if (current->name == name)
        {
            if (current == shead)
            {
                if (shead->next == shead)
                {
                    delete shead;
                    shead = NULL;
                    return;
                }

                SNode *last = shead;

                while (last->next != shead)
                    last = last->next;

                shead = shead->next;
                last->next = shead;
            }
            else
            {
                previous->next = current->next;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != shead);
}

void singlyDisplay()
{
    if (shead == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    SNode *temp = shead;

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != shead);

    cout << endl;
}

struct DNode
{
    string name;
    DNode *prev;
    DNode *next;
};

DNode *dhead = NULL;

void doublyJoin(string name, int position)
{
    DNode *newNode = new DNode();
    newNode->name = name;

    if (dhead == NULL)
    {
        dhead = newNode;
        newNode->next = dhead;
        newNode->prev = dhead;
        return;
    }

    if (position <= 1)
    {
        DNode *last = dhead->prev;

        newNode->next = dhead;
        newNode->prev = last;
        last->next = newNode;
        dhead->prev = newNode;
        dhead = newNode;
        return;
    }

    DNode *temp = dhead;

    for (int i = 1; i < position - 1 && temp->next != dhead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void doublyLeave(string name)
{
    if (dhead == NULL)
        return;

    DNode *current = dhead;

    do
    {
        if (current->name == name)
        {
            if (current->next == current)
            {
                delete current;
                dhead = NULL;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == dhead)
                dhead = current->next;

            delete current;
            return;
        }

        current = current->next;

    } while (current != dhead);
}

void doublyDisplay()
{
    if (dhead == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    DNode *temp = dhead;

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != dhead);

    cout << endl;
}

int main()
{
    cout << "Singly Circular Linked List" << endl;

    singlyJoin("A", 1);
    cout << "After A joins: ";
    singlyDisplay();

    singlyJoin("B", 2);
    cout << "After B joins: ";
    singlyDisplay();

    singlyJoin("C", 3);
    cout << "After C joins: ";
    singlyDisplay();

    singlyJoin("X", 2);
    cout << "After X joins at position 2: ";
    singlyDisplay();

    singlyLeave("B");
    cout << "After B leaves: ";
    singlyDisplay();

    singlyLeave("A");
    cout << "After A leaves: ";
    singlyDisplay();

    cout << endl;

    cout << "Doubly Circular Linked List" << endl;

    doublyJoin("A", 1);
    cout << "After A joins: ";
    doublyDisplay();

    doublyJoin("B", 2);
    cout << "After B joins: ";
    doublyDisplay();

    doublyJoin("C", 3);
    cout << "After C joins: ";
    doublyDisplay();

    doublyJoin("X", 2);
    cout << "After X joins at position 2: ";
    doublyDisplay();

    doublyLeave("B");
    cout << "After B leaves: ";
    doublyDisplay();

    doublyLeave("A");
    cout << "After A leaves: ";
    doublyDisplay();

    return 0;
}