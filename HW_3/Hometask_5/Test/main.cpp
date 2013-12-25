#include <iostream>

using namespace std;


struct CycListElement
{
    int value;
    CycListElement *next;
};


void removeValueCycList(int i, CycListElement *head)
{
    CycListElement *curr;
    if (head != NULL)
    {
        curr = head;
        if (curr->value == i)
        {
            curr = head->next;
            while (curr->next != head)
                curr = curr->next;
            CycListElement *p = new CycListElement;
            p->next = head;
            curr->next = curr->next->next;
            head = head->next;
            delete p;

        }
        else
        {
            bool mark = true;
            while (mark)
            {
                if (curr->next == head)
                {
                    mark = false;
                }
                else if (curr->next->value == i)
                {
                    CycListElement *p = curr->next;
                    curr->next = curr->next->next;
                    p = NULL;
                    delete p;
                    mark = false;
                }
                else if (curr->next->value > i && curr->value < i)
                {
                    break;
                }
                if (mark)
                {
                    curr = curr->next;
                }
            }
        }
    }
}

void addValueCycList(int i, CycListElement *head)
{
    CycListElement *newEl = new CycListElement;
    newEl->value = i;
    if (head == NULL)
    {
        head = newEl;
        newEl->next = NULL;
    }
    else if (i <= head->value)
    {
        newEl->next = head;
        head = newEl;
    }
    else if (i > head->value)
    {
        CycListElement *tmp = head;
            while (tmp->next && i > tmp->next->value)
            {
                tmp = tmp->next;
            }
        if (tmp->next == head)
        {
            tmp->next = newEl;
            newEl->next = head;
        }
        else newEl->next = tmp->next;
        tmp->next = newEl;
    }
}

void printCycList(CycListElement *head)
{
    cout << "\n";
    CycListElement *curr = head;
    if (head->next == NULL)
    {
        cout << "No elements in the list";
    }
    else
    {
        cout << curr->value << " ";
        curr = curr->next;
        while(curr->next != head)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << curr->value << " ";
    }
}

    int main()
    {
            cout << "Enter the number of defenders: ";
            int n = 0;
            cin >> n;
            CycListElement *head = new CycListElement;
            head->value = 1;
            CycListElement *curr = new CycListElement;
            curr->next = head;
            head->next = curr;
            head->value = 1;
            curr->value = n;
            n--;
            while (n > 1)
            {
                CycListElement *tmp = new CycListElement;
                tmp->next = head->next;
                tmp->value = n;
                head->next = tmp;
                n--;
            }
            printCycList(head);
            cout << "\nEach ";
            cin >> n;
            cout << " will die";
            int c = 1;
            curr = head;
            while (head->next != head)
            {
                while (c != n - 1)
                {
                    curr = curr->next;
                    c++;
                }
                if (curr->next == head)
                {
                    head = head->next;
                }
                CycListElement *tmp = curr->next;
                curr->next = curr->next->next;
                tmp->next = NULL;
                delete[] tmp;
                c = 0;
            }
            cout << "\n" << head->value << " is lucky";
            /*cout << "\nFlavius ";
            cin >> n;
            while(head->next != head)
            {
                int i = 1;
                while (i < n - 1)
                {
                    curr = curr->next;
                    i++;
                }
                i = 1;
                if (head->next != head)
                {
                    CycListEl *p = curr->next;
                    curr->next = curr->next->next;
                    p = NULL;
                    delete p;
                    curr = curr->next;
                }
            }
            printCycList(head);
            */
    }


