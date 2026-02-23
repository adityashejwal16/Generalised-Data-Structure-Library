////////////////////////////////////////////////////////////////////////////////////
// 
//                     Generalised Data Structure Library
//
////////////////////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------
    Type               Name Of Class For node                 Name of class for Functionality
-------------------------------------------------------------------------------------------------

 Singly Linear             SinglyLLLnode                             SinglyLLL        Done
 Singly Circular           SinglyCLLnode                             SinglyCLL        Done
 Doubly Linear             DoublyLLLnode                             DoublyLLL        Done
 Doubly Circular           DoublyCLLnode                             DoublyCLL        Done
 Satck                     Stacknode                                 Stack            Done
 Queue                     Queuenode                                 Queue            Done
 ------------------------------------------------------------------------------------------------
*/



#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//                Singly Linear Linked List using Generic approach
/////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public :
       T data;
       SinglyLLLnode<T> *next;

       SinglyLLLnode(T no)
       {
        this->data = no;
        this->next=NULL;
       }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T>* first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);    
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    InsertFirst
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to insert node at first position
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> :: InsertFirst(T no)   
{
    SinglyLLLnode<T>* newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    InsertLast
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to insert node at last position
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T>* newn = NULL;
    SinglyLLLnode<T>* temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)     
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    DeleteFirst
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to Delete node at first position
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    DeleteLast
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to Delete node at Last position
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    Display
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to Display nodes value
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T>* temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   // New code
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    Count
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to Count Number of node
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    InsertAtPos
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to insert At position
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T>* temp = NULL;
    SinglyLLLnode<T>* newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//  
//     Function name :    DeleteAtPos
//     Input :            data of node
//     Output :           nothing
//     Description :      Used to Delete at position
//     Author :           Aditya Dipak Shejwal
//     Date :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T>* temp = NULL;
    SinglyLLLnode<T>* target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}




///////////////////////////////////////////////
// Doubly Linear Link List code Generic approach
//////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

       DoublyLLLnode(T no)
       {
          this->data = no;
          this->next = NULL;
          this->prev = NULL;
       }
};

template<class T>
class DoublyLLL
{
    private:

        DoublyLLLnode<T> * first;
        int iCount;
   
     public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked list Gets Created\n";

    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first==NULL)
    {
       this->first=newn;
    }
    else
    {
       newn->next=this->first;
       this->first->prev=newn;
       this->first=newn;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;

   DoublyLLLnode<T> *temp=NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first==NULL)
    {
       this->first=newn;
    }
    else
    {
       temp = this->first;

       while(temp->next != NULL)
       {
         temp = temp->next;
       }

       temp->next=newn;
       newn->prev=temp;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt =0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalide Position\n";
        return;
    }
    if(pos==1)
    {
       this->InsertFirst(no);
    }
    else if(pos==this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt =1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;  // Right Side   Dia
 
        temp->next=newn;
        newn->prev=temp;       // Left Side Dia

        this->iCount++;
    }
}

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)       // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first=NULL;
    }
    else                                   
    { 
        this->first=this->first->next;
        delete this->first->prev;
        this->first->prev=NULL;
    }
    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)      
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first=NULL;
    }
    else                                  
    { 
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next=NULL;
    }
    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt =0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalide Position\n";
        return;
    }
    if(pos==1)
    {
       this->DeleteFirst();
    }
    else if(pos==this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt =1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;

        this->iCount--;
    }
}

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp=NULL;

    temp = this->first;

    cout<<"\nNULL";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}


////////////////////////////////////////////////////////////////////////////
//           Doubly Circular Linked List Usiong Ganeric Approch
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode 
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
       {
            this -> data = no;
            this -> next = NULL;
            this -> prev = NULL;
       }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;
    
    public:

           DoublyCLL();
           void InsertFirst(T);
           void InsertLast(T);
           void DeleteFirst();
           void DeleteLast();
           int Count();
           void Display();
           void InsertAtPos(T, int);
           void DeleteAtPos(int); 
       
        
};

template<class T>
 DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Object Of DoublyCL Gets Created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        newn -> next = first;
        first -> prev = newn;
        first = newn;
    }
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
}

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(this -> first == NULL && this -> last == NULL) // LL Is Empty
    {
        this->first = newn;
        this->last = newn;
    }
    else  // LL Contain one or more
    {
        this -> last -> next = newn;
        newn -> prev = this -> last;
        this -> last = newn;
    }
        this -> last -> next = this -> first;
        this -> first -> prev = this->last;
}


template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(this -> first == NULL && this -> last == NULL)  // LL Is Empty
    {
        return;
    }
    else if(this -> first == this -> last) // 1 Node
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> first = this -> first -> next;
        delete this -> first -> prev;

        (this -> last) -> next = this -> first;
        (this -> first) -> prev = this -> last;
    }
}

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this->first == this->last) // 1 Node
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> last = this -> last -> prev;
        delete this -> last -> next;

        this -> last -> next = this -> first;
        this -> first -> prev = this -> last;
    }
}


template<class T>
void DoublyCLL<T> :: Display()
{
    if(first == NULL && last == NULL)
    {
        cout<<"Linked List Is Empty\n";
        return;
    }

    DoublyCLLnode<T> *temp = first;
    cout<<"<=>";

    do
    {
        cout<<" |"<<temp -> data<<"| <=>";
        temp = temp -> next;
    }while(temp != first);

    cout<<"\n";
}

template<class T>
int DoublyCLL<T> :: Count()
{
   DoublyCLLnode<T> *temp = first;
    int iCount = 0;
    if(first==NULL && last==NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        temp = temp -> next;
    }while(temp != first);

    return iCount;
}

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    int iCount = 0;
    int i = 0;
    DoublyCLLnode<T> *temp = NULL;

    iCount=Count();

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalide Position\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i=1; i < pos -1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp ->next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
    }
}

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    int iCount = 0;
    int i = 0;
   DoublyCLLnode<T> *temp = NULL;
   DoublyCLLnode<T> *newn = NULL;

    iCount=Count();

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalide Position\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = this -> first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
}


//////////////////////////////////////////////////////////////////////////////
//           Singly Circular Linked List Usiong Ganeric Approch
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:

        T data;
        SinglyCLLnode<T> *next;
        SinglyCLLnode<T> *last;

       SinglyCLLnode(T no)
      {
          this->data=no;
          this->next=NULL;
          this->last=NULL;
      }

};

template<class T>
class SinglyCLL
{
    private:
         
           SinglyCLLnode<T> *first;
           SinglyCLLnode<T> *last;
           int iCount;

    public:
         
           SinglyCLL();
           void InsertFirst(T);
           void InsertLast(T);
           void DeleteFirst();
           void DeleteLast();
           int Count();
           void Display();
           void InsertAtPos(T, int);
           void DeleteAtPos(int);        
};


template<class T>
 SinglyCLL<T> :: SinglyCLL()
{
   cout<<"Object of SinglyCLL gets created.\n";
   this->first=NULL;
   this->last=NULL;

}

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        newn->next=this->first;
        this->first=newn;
    }
    this->last->next=this->first;
    this->iCount++;

}

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        this->last->next=newn;
        this->last=newn;
    }
    this->last->next=this->first;
    this->iCount++;
}

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
    return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;

    }
    else
    {
        temp = this->first;
        this->first=this->first->next;
        delete temp;

        this->last->next=this->first;
    }
    this->iCount--;
}

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
    return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;

    }
    else
    {
        temp = this->first;
        while(temp->next != this->last)
        {
            temp=temp->next;
        }
        delete this->last;
        this->last=temp;
        this->last->next=this->first;
    }
    this->iCount--;
}

template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = this->first;
    
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }while(temp != first);

    cout<<"\n";
}

template<class T>
int SinglyCLL<T> :: Count()
{
     if(first == NULL)
        return 0;

    SinglyCLLnode<T>* temp = first;
    int iCount = 0;

    do
    {
        iCount++;
        temp = temp->next;
    } while(temp != first);

    return iCount;
    
}

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int Pos)
{
    SinglyCLLnode<T> *newn = NULL;
    SinglyCLLnode<T> *temp = this->first;
    int iCount = 0;
    int i =0;

    iCount = Count();
    
    
    if(Pos < 1 || Pos > iCount+1)
    {
        cout<<"Invalide position";
        return;
    }
    if(Pos==1)
    {
    InsertFirst(no);
    }
    else if(Pos==iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        newn->data=no;
        newn->next=NULL;

        for(i =1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int Pos)
{ 
    SinglyCLLnode<T> *temp = this->first;
    int iCount = 0;
    int i =0;
    SinglyCLLnode<T> *target = NULL;

    iCount = Count();
    
    
    if(Pos < 1 || Pos > iCount)
    {
        cout<<"Invalide position";
        return;
    }
    if(Pos==1)
    {
    DeleteFirst();
    }
    else if(Pos==iCount)
    {
        DeleteLast();
    }
    else
    {
        temp=this->first;

        for(i =1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        target = temp->next;

        temp->next=target->next;
        delete target;
    }
}

///////////////////////////////////////////////////////////////////////////
//                        Stack using Generic approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
   public:
       T data;
       Stacknode<T> *next;

       Stacknode(T no)
       {
         this->data=no;
         this->next=NULL;
       }
};

template<class T>
class Stack
{
   private:
        Stacknode<T> *first;
        int iCount;

    public:
         Stack();

         void push(T);     
         T pop();          
         T peep();
         void Display();
         int Count();
           
};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully\n";
    this->first=NULL;
    this->iCount=0;
}
template<class T>
void Stack<T> :: push(T no)
{ 
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn ->next = this->first;

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template<class T>
T Stack<T> :: pop()
{
   T Value = 0;
   Stacknode<T> *temp = this->first;

   if(this->first == NULL)
   {
     cout<<"Stack is empty\n";
     return -1;
   }

   Value = this->first->data;

   this->first=this->first->next;
   delete temp;
   
   this->iCount--;
   return Value;
}

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

   if(this->first == NULL)
   {
     cout<<"Stack is empty\n";
     return -1;
   }

   Value = this->first->data;
   return Value;
}
template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp=temp->next;
    }
}
template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        
        int iCount;

    public:
        Queue();

        void enqueue(T);          
        T dequeue();              
        void Display();
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully...\n";

    this->first = NULL;
    this->last = NULL;

    this->iCount = 0;
}

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }

    cout<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////// End OF Library ///////////////////////////////////////////////////////

///////////////////////////  Main Start ///////////////////////////////////
int main()
{
   /////////////////////////////////// SinglyL link list Main ////////////////////////////////////////////////   
    
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    delete obj;

//////////////////////////////////////// DoublyLLL Main ///////////////////////////////////////////////////////////

DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

      cout<<"Number of Element are :"<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of Element are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of Element are :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();

    cout<<"Number of Element are :"<<dobj->Count()<<"\n";
    

    dobj->InsertAtPos('$',4);
    dobj->Display();

    cout<<"Number of Element are :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();

    cout<<"Number of Element are :"<<dobj->Count()<<"\n";


      delete dobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************  SinglyCLL link list main   *********************************************

    SinglyCLL<int> *cobj = new SinglyCLL<int>();
    int iBet = 0;   // change iRet to iBet 

    cobj->InsertFirst(51);
    cobj->InsertFirst(21);
    cobj->InsertFirst(11);

    cobj->Display();
    iBet = cobj->Count();
    cout<<"Number of nodes are :" <<iBet<<"\n";

    cobj->InsertLast(101);
    cobj->InsertLast(111);
    cobj->InsertLast(121);

    cobj->Display();
    iBet = cobj->Count();
    cout<<"Number of nodes are :" <<iBet<<"\n";

    cobj->DeleteFirst();
    
    cobj->Display();
    iBet = cobj->Count();
    cout<<"Number of nodes are :" <<iBet<<"\n";

    cobj->DeleteLast();

    cobj->Display();
    iBet = cobj->Count();
    cout<<"Number of nodes are :" <<iBet<<"\n";

    cobj->InsertAtPos(105,4);

    cobj->Display();
    iBet = cobj->Count();
    cout<<"Number of nodes are :" <<iBet<<"\n";

    cobj->DeleteAtPos(4);
    cobj->Display();
    iBet = cobj->Count();
    cout<<"Number of nodes are :" <<iBet<<"\n";

    delete cobj;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************  DoublyCL link list main   *********************************************

DoublyCLL<int> dcobj;
    int iDet = 0;

    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);

    dcobj.Display();

    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dcobj.InsertLast(101);
    dcobj.InsertLast(111);
    dcobj.InsertLast(121);
    
    dcobj.Display();

    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj.DeleteFirst();
    dcobj.Display();

    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj.DeleteLast();

    dcobj.Display();

    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj.InsertAtPos(105,4);

    dcobj.Display();

    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj.DeleteAtPos(4);

    dcobj.Display();

    iRet = dcobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


////////////////////////////////// Stack Mian /////////////////////////////////////////////////////////

      Stack<char> *sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');

    sobj->Display();
    cout<<"NUmber od element in Stack are : "<<sobj->Count()<<"\n";

    cout<<"return Value of peep is : "<<sobj->peep()<<"\n";

    sobj->Display();
    cout<<"NUmber od element in Stack are : "<<sobj->Count()<<"\n";

    cout<<"poped element is is : "<<sobj->pop()<<"\n";

     sobj->Display();
    cout<<"NUmber od element in Stack are : "<<sobj->Count()<<"\n";

    cout<<"poped element is is : "<<sobj->pop()<<"\n";

     sobj->Display();
    cout<<"NUmber od element in Stack are : "<<sobj->Count()<<"\n";

    sobj->push('E');
     sobj->Display();
    cout<<"NUmber od element in Stack are : "<<sobj->Count()<<"\n";

    delete sobj;

    ///////////////////////////////// Queue Main ///////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}