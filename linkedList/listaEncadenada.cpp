#include "listaEncadenada.h"

linkedList::linkedList() {//this is the constructor of the class

    head = NULL;
    tail = NULL;

}
void linkedList::createNode(int num, NodeType *&node ){ //this function creates a new node

    node = new NodeType;
    node -> data = num;
    node -> link = NULL;
}
void linkedList::insertnode(int num) { //create a node at the beginning of the list
    NodeType *node;
    createNode(num,node);
    if( head == NULL)
    {
        head = node;
        tail = head;
        cont++;
    }
    else
    {
        node -> link = head;
        head = node;
        node = NULL;
        cont++;
    }
}
void linkedList::appendNode(int num)  { //create a node at the end of the list
    NodeType *node;
    createNode(num,node);

    if( head == NULL) {
        head = node;
        tail = head;
        cont++;
    }
    else
    {
        tail -> link =  node;
        tail = tail -> link;
        node -> link = NULL;
        cont++;
    }

}
void linkedList::printList() {//this function prints the list on the screen
    NodeType *location;
    location = head;
    if (location != NULL) {
        cout << location -> data << "-> ";
        while (location -> link != NULL) {
            location = location -> link;
            cout << location -> data << "-> ";
        }
        cout << endl;
    }
    else
        cout<<"the list it's empty"<<endl;
}
void linkedList::searchANumber(int num) {//this function goes through the list looking for the indicated number

    NodeType *location;
    int count = 0;
    location = head;

    if(location == NULL)
    {
        cout << "The list its empty" << endl;
    }
    else
    {
        do {
            if (location -> data == num) {
                cout << "The number " << num << " it,s in the (" << count + 1 << ") position" << endl;
            }
            location = location -> link;
            cont++;
        } while (location != NULL);

        if (location == NULL)
            cout<< "The number you are looking for is not in the list " << endl;
    }
}
void linkedList::deleteANumber(int num) {

    NodeType *temp, *temp1, *location;
    location = head;


    if(head == NULL)
        cout<<"the list it's empty"<<endl;
    else if(location -> data == num)
    {
        deleteHead();
        cont--;
    }
    else {
        while (location -> link != NULL)
        {
            if (location -> link -> data == num)
            {
                temp = location;
                location = location->link;
                temp1 = location;
                location = location->link;
                temp1 -> link = NULL;
                temp -> link = location;
                delete temp1;
                cont--;
                return;

            }
            else
            {
                location = location->link;
            }
        }

        if(location -> link == NULL)
            cout<<"the number is't in the list"<<endl;
    }
}
void linkedList::orderList() {

    int swap = 0;
    NodeType *location;
    if(head == NULL)
        cout << "The list its empty" << endl;
    else
    {
        for (int i = 0; i < cont; i++)
        {
            location = head;
            do {
                if (location -> data > location -> link -> data) {
                    swap = location->link->data;
                    location -> link->data = location -> data;
                    location ->data = swap;
                }
                location = location -> link;
            } while (location -> link != NULL);
        }
        cout<<"The list has been ordered"<<endl;
    }
}
void linkedList::deleteHead() {

    NodeType *temp;
    if(head == NULL)
    {
        head = NULL;
        cout<<"The list its empty"<<endl;
    }
    else if(head -> link == NULL)
    {
        head = NULL;
        cont--;
        cout<<"The list its empty"<<endl;
    }
    else if(head -> link != NULL)
    {

        temp = head;
        head = head -> link;
        temp -> link = NULL;
        delete temp;
        cont--;
    }
}
void linkedList::deleteTail() {

    NodeType *temp,*location;
    location = head;

    if(head == NULL)
    {
        tail == NULL;
        cout<<"The list it's empty"<<endl;
    }
    else if(tail == head)
    {
        deleteHead();
        cont--;
    }
    else {

        while (location->link != tail) {
            location = location->link;
        }
        temp = tail;
        tail = location;
        tail -> link = NULL;
        delete temp;
        cont--;
    }
}
void linkedList::reverse() {
    NodeType *temp = NULL, *temp1 = NULL, *location;
    location = head;
    if(head == NULL)
    {
        cout<<"the list it's empty"<<endl;
        return;
    }
    else {
        while (location != NULL) {
            temp = location -> link;
            location -> link = temp1;
            temp1 = location;
            location = temp;
        }
        tail = head;
        head = temp1;
    }
}
void linkedList::insertAtPos(int pos, int num) {//allows you to place a node anywhere in the list

    NodeType *location,*temp, *temp1, *node;
    location = head;

    if(pos == 1)
    {
        insertnode(num);
        cont++;
    }
    else if(pos > cont)
    {
        appendNode(num);
        cont++;
    }
    else
    {
        pos--;
        for(int i = 1; i < pos;i++)
        {
            location = location -> link;
        }
        temp = location;
        temp1 = location -> link;
        createNode(num,node);
        location = node;
        location -> link = temp1;
        temp -> link = location;
        cont++;
    }

}
void linkedList::showMenu() { //this function show the menu


    int num = 0,opcion = 0;

    do{
        cout<< "1. if you want to print the list\n"
               "2. if you want to insert a node at the beginning\n"
               "3. if you want to insert a node at the end\n"
               "4. if you what to search a number\n"
               "5. if you what to delete a number\n"
               "6. if you want to order the list\n"
               "7. if you want to delete the head\n"
               "8. if you want to delete the tail\n"
               "9. if you want to reverse the list\n"
               "10. if you want to insert a number at a position\n"
               "11. if you want to know the size if the list\n"
               "12. exit\n"
               "Enter an option ";
        cin>>opcion;
        cout<<"\n";
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Enter a valid option" << endl;
            cin>>opcion;
        }
        switch(opcion) {
            case 1:
                printList();
                break;
            case 2:
                cout << "Enter the data of the node" << endl;
                cin >> num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout << "Enter the data of the node" << endl;
                    cin>>num;
                }
                insertnode(num);
                cout << "A new node has been created at the beginning" << endl;
                break;
            case 3:
                cout<<"Enter the data of the node"<<endl;
                cin>>num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<<"Enter the data of the node"<<endl;
                    cin>>num;
                }
                appendNode(num);
                cout<<"A new node has been created at the end\n";
                break;
            case 4:
                cout<<"Enter the number that you what to search "<<endl;
                cin>>num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<<"Enter the number that you what to search "<<endl;
                    cin>>num;
                }
                searchANumber(num);
                break;
            case 5:
                cout<<"Enter the number that you what to delete "<<endl;
                cin>>num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<<"Enter the number that you what to delete "<<endl;
                    cin>>opcion;
                }
                deleteANumber(num);
                break;
            case 6:
                orderList();
                cout<<"the list has been sorted\n";
                break;
            case 7:
                printList();
                deleteHead();
                cout<<"The head has been delete"<<endl;
                break;
            case 8:
                printList();
                deleteTail();
                cout<<"The tail has been delete"<<endl;
                break;
            case 9:
                reverse();
                break;
            case 10:
                int pos;
                cout<<"Enther the position and the data of the new node"<<endl;
                cin>>pos>>num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<<"Enther the position and the data of the new node"<<endl;
                    cin>>pos;
                    cin>>num;
                }
                insertAtPos(pos,num);

                break;
            case 11:
                cout<<"The length of the list is:"<<cont<<endl;
        }
    }while(opcion != 12);
}
