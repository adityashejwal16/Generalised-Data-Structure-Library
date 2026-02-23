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