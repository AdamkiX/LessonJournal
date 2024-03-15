#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using namespace std;
// declaring node class
template<typename T>
struct node {
    node<T>* next;
    T data;
};
// declaring linked list class
template<typename T>
class MyList
{
public:
    node<T>* head;
    node<T>* last;
    int size = 0;
    MyList<T>()                            // Konstruktor bezargumentowy
    {
        head = NULL;
        last = NULL;
    }
    MyList(const MyList<T>& copy)           // Konstruktor kopiuj¹cy
    {
        head = nullptr;
        node<T>* ptr = copy.head;
        while (ptr != nullptr)
        {
            Push(ptr->data);
            ptr = ptr->next;
        }
    }      
    void Push(T data)                       // Dodawanie elementu do listy
    {
        if (!head)                          // Pierwszy element
        {
            head = new node<T>;
            head->data = data;
            head->next = NULL;
            last = head;
            size++;
        }
        else                                // Drugi element
        {
            if (last == head) 
            {
                last = new node<T>;
                last->data = data;
                last->next = NULL;
                        head->next = last;
                size++;
            }
            else                            // Trzeci i kolejne elementy
            {
                node<T>* i = new node<T>;
                i->data = data;
                i->next = NULL;
                last->next = i;
                last = i;
                size++;
            }
        }
    }
    void Delete(int index)
    {
        if (index == 0)                             // Usuniêcie Pierwszego elementu
        {
            node<T>* curr = this->head;
            this->head = this->head->next;
            free(curr);
            size--;
        }
        else if (index > 0 && index < size)          // Usuniêcie elementów, które s¹ miêdzy pierwszym, a ostatnim
        {
            node<T>* curra = this->head;
            node<T>* currb = this->head;
            for (int i = 0; i < index-1; ++i)
            {
                curra = curra->next;
                currb = currb->next;
            }
            currb = currb->next;
            curra->next = currb->next;
            free(currb);
            size--;
        }
        else                                        // Usuniêcie ostatniego elementu z listy
        {
            node<T>* curr = this->last;
            for (int i = 0; i < index - 1; i++)
            {
                curr = curr->next;
            }
            this->last = curr;
            this->last->next = NULL;
            size--;
        }
    }
    T Get(int index)                        // Wyszukanie elementu
    {
        if (index == 0) 
        {
            return this->head->data;
        }
        else {
            node<T>* curr = this->head;
            for (int i = 0; i < index; ++i) 
            {
                curr = curr->next;
            }
            return curr->data;
        }
    }
    void SortGrowing()                          // Sortowanie rosn¹co
    {
        bool sorted = false;
        node<T>* key = head;
        node<T>* pointr = head->next;
        do
        {

            if (pointr->data >= key->data)
            {
                if (pointr->next != NULL)
                {
                    pointr = pointr->next;
                }
                else
                {
                    if (key->next == NULL)
                        sorted = true;
                    else
                    {
                        key = key->next;
                        if (key->next != NULL)
                        {
                            pointr = key->next;
                        }
                        else
                            sorted = true;

                    }
                }
            }
            else
            {
                T temp = key->data;
               // cout << "temp:" << temp << endl;
                key->data = pointr->data;
                pointr->data = temp;
            }

        } while (sorted == false);

    }
    void SortDescending()                               // Sortowanie malej¹co
    {
        bool sorted = false;
        node<T>* key = head;
        node<T>* pointr = head->next;
        do
        {

            if (pointr->data <= key->data)
            {
                if (pointr->next != NULL)
                {
                    pointr = pointr->next;
                }
                else
                {
                    if (key->next == NULL)
                        sorted = true;
                    else
                    {
                        key = key->next;
                        if (key->next != NULL)
                        {
                            pointr = key->next;
                        }
                        else
                            sorted = true;

                    }
                }
            }
            else
            {
                T temp = key->data;
                // cout << "temp:" << temp << endl;
                key->data = pointr->data;
                pointr->data = temp;
            }

        } while (sorted == false);

    }

    ~MyList<T>()                            // Destruktor
    {
        int temp_size = size;
        for (int i = 0; i < temp_size; i++)
        {
            Delete(0);
        }
    }
};
#endif