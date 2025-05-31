#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* link;

    Node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};

class Linked_list
{
public:
    Node* head;
    int size;

    Linked_list()
    {
        this->head = NULL;
        this->size = 0;
    }

    // Insert At End
    void InsertAtFront(int data)
    {
        Node* newNode = new Node(data);
        newNode->link = this->head;
        this->head = newNode;
        this->size++;
    }

    void InsertAtEnd(int data)
    {
        Node* newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node*ptr = this->head;
            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }
            ptr->link = newNode;
            this->size++;
        }
    }
    void InsertAtIndex()
    {    
        int index,data;
        cout << "Enter Index Number To Insert :- ";
        cin >> index;
        if (index >= 0 && index < this->size)
        {                    
            cout << endl;
            cout << "Enter Element To Insert :- ";
            cin >> data;

            Node* ptr = this->head;
            Node* newNode = new Node(data);
            for (int i = 0; i < index - 1; i++)
            {
                ptr = ptr->link; 
            }
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
        else
        {
            cout << "Sorry ! The Index Is Out Of Bount";
        }
    }
   
    void DeleteAtFront() 
    {
        if (this->head == NULL)
        {
            cout << "Therefor ! The List Is Empty" << endl;
            return;
        }
        else
        {
            this->head = this->head->link;
        }
        
    }

    void DeleteAtEnd()
    {
        if (this->head == NULL)
        {
            cout << "Therefor ! The List Is Empty" << endl;
            return;
        }
        else
        {
            Node* ptr = this->head;

            while (ptr->link->link != NULL)
            {
                ptr = ptr->link;
            }
            ptr->link = NULL;
        }
    }

    void DeleteAtIndex(int index) 
    {
        if (this->head == NULL)
        {
            cout << "Therefore ! The List Is Empty" << endl;
            return;
        }
        
        if (index >= 0 && index < this->size)
        {
            Node* ptr = this->head;
            for (int i = 0; i < index; i++)
            {
                ptr = ptr->link;
            }
            ptr->link = ptr->link->link;
        }
        else
        {
            cout << "Sorry ! Index Is Out Of Bound" << endl;
        } 
        cout << endl;
    }
    
    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *link = NULL;
        while (current != NULL)
        {
            link = current->link; 
            current->link = prev;
            prev = current;       
            current = link;       
        }
        head = prev;
    }

    void Update(int data_1,int index)
    {
        Node* ptr = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->link;    
        }
        ptr->link->data = data_1;
    }

    void printview()
    {
        if (this->head == NULL)
        {
            cout << endl << "---- Sorry Linked List Is Empty ----" << endl;
        }

        else
        {
            Node* ptr = this->head;
            cout << "Given Linked List is :- " << endl;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->link;
            }
            cout << endl;
        }
    }
};

int main()
{
    Linked_list l;
    int choice,element,index;

    do
    {
        cout << endl << endl << "----- Program's -----" << endl << endl;        
        cout << "Press 1 To Insert At Front." << endl;
        cout << "Press 2 To Insert At End." << endl;
        cout << "Press 3 To Insert At Index." << endl;
        cout << "Press 4 To Delete At Front." << endl;
        cout << "Press 5 To Delete At End." << endl;
        cout << "Press 6 To Delete At Index." << endl;
        cout << "Press 7 To Update." << endl;
        cout << "Press 8 To View List." << endl;
        cout << "Press 9 To Reverse List." << endl;
        cout << "Enter Your Choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "---- Your Program Is Sucessfully Executed. ----" << endl;
            break;
        
        case 1:
            cout << "Enter Element To Insert :- ";
            cin >> element;
            l.InsertAtFront(element);
            break;
        
        case 2:
            cout << "Enter Element To Insert :- ";
            cin >> element;
            l.InsertAtEnd(element);
            break;
        
        case 3:
            l.InsertAtIndex();
            break;
        
        case 4:
            l.DeleteAtFront();
            break;
        
        case 5:
            l.DeleteAtEnd();
            break;
        
        case 6:
            cout << "Enter Index Number To Delete :- ";
            cin >> index;
            cout << endl;
            l.DeleteAtIndex(index);
            break;
        
        case 7:
            cout << "Enter Index Number To Update :- ";
            cin >> index;
            cout << endl;
            cout << "Enter Element To Replace :- ";
            cin >> element;
            l.Update(element,index);
            break;

        case 8:
            l.printview();
            break;
        
    
        case 9:
            cout<<"----------" << endl;
            cout<<"Original Linked List :- " << endl;
            l.printview();
            l.reverse();
            cout << "Reversed LinkedList :- " << endl;
            l.printview();
            cout<<"----------" << endl;
            break;  
            
        default:
            cout << "Wrong Choice !" << endl;
            break;
        }

    } while (choice != 0);
    
    return 0;
}