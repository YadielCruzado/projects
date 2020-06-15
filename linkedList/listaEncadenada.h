//
// Created by yadie on 5/31/2020.
//

#ifndef LISTASENCADENADAS_LISTAENCADENADA_H
#define LISTASENCADENADAS_LISTAENCADENADA_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class linkedList {

    struct NodeType{
        int data;
        NodeType *next;
    };

private:

    NodeType *head, *tail;
    int cont = 0;

public:
    linkedList();
    void createNode(int,NodeType *&);//Create a new node
    void insertnode(int);//Create a node at the beginning of the list
    void appendNode(int);//Create a node at the end of the list
    void printList();//Prints the list on the screen
    void searchANumber(int);//This function goes through the list looking for the indicated number
    void deleteANumber(int);//delete a node from the list
    void orderList();//order the list
    void deleteHead();//delete de first node of the list
    void deleteTail();//delete the las node of the list
    void reverse();//tis function revert the list
    void insertAtPos(int,int);//insert a node in a given position
    void showMenu();//Show the menu
};

#endif //LISTASENCADENADAS_LISTAENCADENADA_H
