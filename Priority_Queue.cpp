//Steffen Steffen
//This program creates a queue using an unsorted doubly linked list before sorting
//it in the same queue 
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class Queue_Node{
            private:
                string Name;
                string Status;
                float Price;
                int Mins;
                int key;
                Queue_Node *next;
                Queue_Node *prev;
            friend class Queue;
                };
class Queue{
            private:
                Queue_Node *front;
                Queue_Node *rear;
                Queue_Node *curr;
            public:
                Queue();
                void priority_queue();
                void remove_priority();
            };
int main()
{
    Queue queue;
    int choice;
    while(choice != 3)
    {
        
        cout << "\n\nWelcome to the priority queue!\n";
        cout << "1.) Set information of passengers.\n";
        cout << "2.) Print priority queue.\n";
        cout << "3.) Exit.\n";
        cout << "Select an option.\n";
        cin >> choice;
    
        switch(choice)
        {
            case 1:
                    queue.priority_queue();
                    break;
            case 2:
                    queue.remove_priority();
                    break;
            case 3: 
                    cout << "exiting" <<endl;
                    exit(1);
                
        }
                
    }
   
    system("pause");
    return 0;
}

Queue::Queue()
{
    front = NULL;
}
        
 void Queue::priority_queue()
 {
    Queue_Node *t = new Queue_Node;
    front = t;
    t->Name = "Jones";
    t->Status = "GOLD";
    t->Price = 437;
    t->Mins = 30;
    t->key = 0;
    
    Queue_Node *v = new Queue_Node;
    
    v->Name = "Smith";
    v->Status = "PLAT";
    v->Price = 385;
    v->Mins = 38;
    v->key = 0;
    v->prev = t;
    t->next = v;
    
    Queue_Node *p = new Queue_Node;
    
    p->Name = "Lee";
    p->Status = "NONE";
    p->Price = 600;
    p->Mins = 58;
    p->key = 0;
    v->next = p;
    p->prev = v;
    
    Queue_Node *z = new Queue_Node;
    
    z->Name = "Harris";
    z->Status = "SLVR";
    z->Price = 486;
    z->Mins = 45;
    z->key = 0;
    p->next = z;
    z->prev = p;
    
    Queue_Node *c = new Queue_Node;
     
    c->Name = "White";
    c->Status = "GOLD";
    c->Price = 451;
    c->Mins = 60;
    c->key = 0;
    c->prev = z;
    z->next = c;
    c->next = NULL;
    
    curr = front;
    string current;
    //add to key by frequent flyer status
    while(curr != NULL)
    {
        current = curr->Status;
        string::const_iterator it = current.begin();
        if(*it == 'G')
        {
            curr->key = curr->key + 20;
        } 
        if(*it == 'P')
        {
            curr->key = curr->key + 0;
        }
        if(*it == 'S')
        {
            curr->key = curr->key + 30;
        }
        if(*it == 'N')
        {
            curr->key = curr->key + 40;
    }
      curr = curr->next;
      }
    curr = front;
    //add to key by price paid
    while(curr != NULL)
    {
        if(curr->Price > 500)
        {
            curr->key = curr->key + 0;
        }
        if(curr->Price <= 500 && curr->Price >= 451)
        {
            curr->key = curr->key + 5;
        }
        if(curr->Price <= 450 && curr->Price >= 401)
        {
            curr->key = curr->key + 10;
        }
        if(curr->Price <= 400 && curr->Price >= 351)
        {
            curr->key = curr->key + 15;
        }
        if(curr->Price <= 350 && curr->Price >= 301)
        {
            curr->key = curr->key + 20;
        }
        curr = curr->next;
    }
    //add to key by minutes prior to departure
    curr = front;
    while(curr != NULL)
    {
        curr->Mins = (60 - curr->Mins);
        curr->key = curr->key + curr->Mins;
        curr = curr->next;
    }
    // arrange nodes in order from least to greatest by key
    for(Queue_Node *i = front; i->next != NULL; i = i->next)
     {
        for (Queue_Node *s = i->next; s != NULL; s = s->next)
         {
            if(i->key > s->key)
            {
            swap(i->key, s->key);
            swap(i->Name, s->Name);
            swap(i->Status,s->Status);
            swap(i->Mins, s->Mins);
            swap(i->Price, s->Price);
            }
         }
      }
    cout << "Priority Queue complete!" << endl;
    system("pause");
}
     
void Queue::remove_priority()
{
    //Queue_Node *temp;
    
    if(front == NULL)   
    {
        cout << "ERROR. There isn't anybody here!\n";   
        system("pause");
    }
    else//display queue in appropriate order
    {   
        cout << "The individuals in the queue hold priority in the following order: " << endl;
        cout << "NAME" << setw(9) << "Status" << setw(12) << "Price Paid" << setw(13) << "Minutes Late" << setw(6) << "Key" << endl;
        cout << "====" << setw(9) << "======" << setw(12) << "==========" << setw(13) << "============" << setw(6) << "===" << endl;
        cout << front->Name << setw(7) << front->Status << setw(9) << front->Price << setw(11)<< front->Mins << setw(9) << "*" << front->key << "*" << endl;
        front = front->next;
        cout << front->Name << setw(7) << front->Status << setw(9) << front->Price << setw(11)<< front->Mins << setw(9) << "*" << front->key << "*" << endl;
        front = front->next;
        cout << front->Name << setw(9) << front->Status << setw(9) << front->Price << setw(11)<< front->Mins << setw(9) << "*" << front->key << "*" << endl;
        front = front->next;
        cout << front->Name << setw(6) << front->Status << setw(9) << front->Price << setw(11)<< front->Mins << setw(9) << "*" << front->key << "*" << endl;
        front = front->next;
        cout << front->Name << setw(7) << front->Status << setw(9) << front->Price << setw(11)<< front->Mins << setw(9) << "*" << front->key << "*" << endl;
        front = NULL;
    }
       
}

    
    
    
    
    
    
    

