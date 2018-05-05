#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class Reservation{
                private:
                        string LastName;
                        Reservation *next;
                        
                friend class LinkedList;
                };
class LinkedList{
            private:
                    Reservation *head;
                    Reservation *curr;
            public:
                    LinkedList();
                    void addNode();
                    void cancelNode();
                    void printNode();
                    void searchNode();
                };
                
int main()
{
    int choice;
    LinkedList list;
    while(choice != 5)
   {
        cout << "\n1.) initialize list." << endl;
        cout << "2.) Print list." << endl;
        cout << "3.) Search list." << endl;
        cout << "4.) Cancel reservation." << endl;
        cout << "5.) Quit." << endl;
        
        cin >> choice;
                   
          switch(choice)
             {        
                  case 1:
                          list.addNode(); 
                          break;
                  case 2:
                          list.printNode();
                          break;
                  case 3:
                          list.searchNode();
                          break;
                  case 4:
                          list.cancelNode();
                          break;
                  case 5:
                          cout<<"exiting.\n";
                          system("pause");
                          exit(1);
             }
   }
    system("pause");
    return 0;
}

LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::addNode()
{
    Reservation *n = new Reservation;
    head = n;
    n->LastName = "smith";
    
    Reservation *t = new Reservation;
    t->LastName = "johnson";
    n->next = t;
    
    Reservation *p = new Reservation;
    p->LastName = "carrol";
    t->next = p;
    
    Reservation *z = new Reservation;
    z->LastName = "gomez";
    p->next = z;
    
    Reservation *j = new Reservation;
    j->LastName = "christ";
    z->next = j;
    j-> next = NULL;
    
    cout << "list initialized!\n";
}

void LinkedList::printNode()
{
    if(head == NULL)
    {
        cout << "no reservations are present at this time.\n";
        system("pause");
        return;
    }
    
    curr = head;
    
    while(curr != NULL)
    {
       cout << "\nReservation for: " << curr->LastName << endl;
       cout << "---------------\n";
       curr = curr->next;
    }
}

void LinkedList::searchNode()
{
    if(head == NULL)
    {
        cout << "no reservations are present at this time.\n";
        system("pause");
        return;
    }
    
    string last_name;
    curr = head;
    
    cout << "Enter the last name under the reservation.\n";
    cin >> last_name;
    
    while(curr->next != NULL && curr->LastName != last_name)
    {
        curr = curr->next;
    }
    if(curr->LastName == last_name)
    {
        cout << "\nReservation for: " << curr->LastName << endl;
        cout << "---------------\n";
    }
    else
    {
        cout << "No reservation found for " << last_name << endl;
        system("pause");
        return;
    }
}

void LinkedList::cancelNode()
{
    if(head == NULL) 
    {
        cout << "no reservations are present at this time.\n";
        system("pause");
        return;
    }
    string last_name;
    curr = head;
    
    cout << "Enter the last name of the reservation you want to cancel.\n";
    cin >> last_name;
    
    while(curr->next != NULL && curr->LastName != last_name)
    {
        curr = curr->next;
    }
    if(curr->LastName == last_name)
    {
        cout << "\nReservation for: " << curr->LastName << " was found."<< endl;
    }
    else
    {
        cout << "No reservation found for " << last_name << endl;
        system("pause");
        return;
    }
    curr = head;
    Reservation *d;
    d = head;
    
    if(head->LastName == last_name)
    {
        cout << "The reservation for " << head->LastName << " was cancelled." << endl;
        head = head->next;
        return;
    }
    while(d->LastName != last_name && d->next != NULL)
    {
        d = d->next;
    }
    while(curr->next != d)
    {
        curr = curr->next;
    }
    curr->next = d->next;
    cout << "The reservation for " << d->LastName << " was cancelled." << endl;
}
