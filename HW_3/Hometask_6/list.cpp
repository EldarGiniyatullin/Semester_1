#include "list.h"
#include <iostream>

void printList(List &myList)
{
    cout << "\n";
    ListElement *curr = myList.first;
    if (myList.first == NULL)
    {
        cout << "No elements in the list";
    }
    else
    {
        while(curr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }
    delete curr;
}

void addValueList(int i, List &myList)
{
    ListElement *newEl = new ListElement;
    newEl->value = i;
    if (myList.first == NULL)
    {
        myList.first = newEl;
        newEl->next = NULL;
    }
    else if (myList.first != NULL)
    {
        ListElement *tmp = myList.first;
        myList.first = newEl;
        newEl->next = tmp;
    }
}

List addValueUpSortedList(int i, List &myList)
{
    ListElement *newEl = new ListElement;
    newEl->value = i;
    if (myList.first == NULL)
    {
        myList.first = newEl;
        newEl->next = NULL;
    }
    else if (i <= myList.first->value)
    {
        newEl->next = myList.first;
        myList.first = newEl;
    }
    else if (i > myList.first->value)
    {
        ListElement *tmp = myList.first;
            while (tmp->next && i > tmp->next->value)
            {
                tmp = tmp->next;
            }
        if (!tmp->next)
        {
            tmp->next = newEl;
            newEl->next = NULL;
        }
        else newEl->next = tmp->next;
        tmp->next = newEl;
    }
    return myList;
}

List removeValueList(int i, List &myList)
{
    ListElement *curr;
    curr = myList.first;
    if (myList.first != NULL)
    {
        if (curr->value == i)
        {
            ListElement *p = myList.first;
            myList.first = myList.first->next;
            p->next = NULL;
            delete p;
        }
        else
        {
            bool mark = true;
            while (mark)
            {
                if (curr->next->value == i)
                {
                    ListElement *p = curr->next;
                    curr->next = curr->next->next;
                    p->next = NULL;
                    delete p;
                    mark = false;
                }
                else if (curr->value > i && curr->next->value < i)
                {
                    break;
                }
                if (curr->next == NULL)
                    mark = false;
                if (mark)
                {
                    curr = curr->next;
                }
            }
        }
    }
    return myList;
}

void sortUpInceptionList(List &myList)
{
    if (myList.first != NULL && myList.first->next != NULL) // проверка на количество элементов в списке (больше ли одного)
    {
        ListElement *curr = myList.first;
        if (myList.first->value > myList.first->next->value)  //сортировка первых 2-х элементов
        {
            int i = myList.first->next->value;
            removeValueList(i, myList);
            addValueUpSortedList(i, myList);
        }
        if (curr->next != NULL)
        {
            while (curr->next->next != NULL)
            {
                    while (curr->next->next != NULL && curr->value > curr->next->value)  //следующий элемент, если он меньше curr, будет отбрасываться за него
                                      //и следующий за ним станет следующим за curr; метка curr держится на одном и том же элементе до тех пор, пока
                                        //следующий за ним элемент не станет больше или равным ему, тогда только метка curr переходит на этот самый следующий элемент
                    {
                        int i = curr->next->value;  //запоминается перетаскиваемое значение
                        ListElement *tmp = curr->next; //удаляется элемент
                        curr->next = curr->next->next;  //с перетаскиваемым значением
                        delete tmp;
                        addValueUpSortedList(i, myList);  //функция добавления значения в отсортированный массив взята из задачи 4;
                                                           // функция добавления начнет пробегать с головы списка, так как не представляется возможным
                                                           //в односвязном списке движение от хвоста к голове, как показано в алгоритмах сортировки вставками;
                                                          // так как вплоть до curr список отсортирован и значение в curr больше i, то
                                                          //функция дальше curr не уйдет, а неперетаскиваемое значение вставится по назначению
                    }
                if (curr->next->next != NULL)
                    curr = curr->next;
            }
            if (curr->value > curr->next->value)  //сортировка последнего элемента списка
            {
                int i = curr->next->value;
                ListElement *tmp = curr->next;
                curr->next = NULL;
                delete tmp;
                addValueUpSortedList(i, myList);
            }
        }
    }
}
