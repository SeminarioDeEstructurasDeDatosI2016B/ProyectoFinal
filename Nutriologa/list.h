#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <iostream>
#include <string>
#include <fstream>

#include "node.h"

class ListException : public std::exception {

    private:
        std::string msg;
    public:
        explicit ListException(const char* message): msg(message){ }

        explicit ListException(const std::string& message) : msg(message) { }

        virtual ~ListException() throw() { }

        virtual const char* what() const throw () {
        return msg.c_str();
        }
};

template <class T> class List{
        private:
            Node<T>* header;

            bool isValid(Node<T>*);

            void copyAll(const List<T>&);
            //void sortData();

        public:

            List();
            List(const List<T>&);
            ~List();

            bool isEmpty();


            void insertData(Node<T>*, const T&);
            void deleteData(Node<T>*);

            Node<T>* getFirst();
            Node<T>* getLast();
            Node<T>* getPrev(Node<T>*);
            Node<T>* getNext(Node<T>*);
            Node<T>* findData(const T&);

            T retrieve(Node<T>*);

            void print();

            void deleteAll();

            void writeToDisk(std::string);
            void readFromDisk(std::string);

            List<T>& operator = (const List<T>&);

};

using namespace std;

template <class T>
List<T>::List(){
    header = new Node<T>;
    if(header == nullptr){
        throw ListException("Unavailable Memory , Create List ");

    }

    header->setPrev(header);
    header->setNext(header);
}

template <class T>
List<T>::List(const List<T>& l) : List<T>(){
    copyAll(l);
}

template <class T>
List<T>& List<T>::operator = (const List<T>& l){
    deleteAll();

    copyAll(l);

    return *this;

}
template <class T>
void List<T>::copyAll(const List<T>& l){

    Node* aux = l.header->getNext();
    Node* lastInserted = nullptr;
    Node* newNode;

    while(aux != l.header){
        try{
        newNode = new Node(aux->getData());
    }catch(NodeException ex){
        throw ListException("Error");
            }

        if(newNode == nullptr){
            throw ListException("Memory not available to copy List");
            }

        if(lastInserted == nullptr){
            header->setNext(newNode);
            newNode->setPrev(header);
            }
        else{
            lastInserted->setNext(newNode);
            newNode->setPrev(lastInserted);
            }

        lastInserted = newNode;

        aux = aux->getNext();
        }

        header->setPrev(lastInserted);
        lastInserted->setNext(header);
       
}

template <class T>
List<T>::~List(){
    deleteAll();

}

template <class T>
bool List<T>::isEmpty(){
        return header->getNext() == header;
}

template <class T>
void List<T>::insertData(Node<T>* p, const T& e){
        if(p != nullptr and !isValid(p)){
            throw ListException("Invalid Insert Position");
            }

        Node<T>* aux;
        try{
            aux = new Node<T>(e);
        }catch (NodeException ex){
            string msg;
            msg = "Error while creating Node for Insertion";
            msg += ex.what();

            throw ListException(msg);
            }
        if(aux == nullptr){
            throw ListException("Memory not available when trying to insert");
        }

        if(p == nullptr){
                p = header;
         
            aux->setPrev(p);
            aux->setNext(p->getNext());

            p->getNext()->setPrev(aux);
            p->setNext(aux);
        }
}


template <class T>
void List<T>::deleteData(Node<T>* p){
        if(!isValid(p)){
            throw ListException("Invalid delete position");
        }
            p->getPrev()->setNext(p->getNext());
            p->getNext()->setPrev(p->getPrev());


            delete p;
}

template <class T>
Node<T>* List<T>::getFirst(){
        if(isEmpty()){
            return nullptr;
        }

        return header->getNext();
}

template <class T>
Node<T>* List<T>::getLast(){
        if(isEmpty()){
            return nullptr;
        }
        return header->getPrev();
}

template <class T>
Node<T>* List<T>::getPrev(Node<T>* p){
        if(!isValid(p) or p == header->getNext()){
            return nullptr;
        }

            return p->getPrev();
}

template <class T>
Node<T>* List<T>::getNext(Node<T>* p){
        if(!isValid(p) or p == header->getPrev()){
            return nullptr;
        }
        return p->getNext();
}

template <class T>
Node<T>* List<T>::findData(const T& e){
        Node<T>* aux = header->getNext;
        while(aux != header){
            if(aux->getData() == e){
                return aux;
            }
            aux = aux->getNext();
        }
        return nullptr;
}

template <class T>
T List<T>::retrieve(Node<T>* p){
        if(!isValid(p)){
            throw ListException("Invalid retrieve position");
        }

        try{
            return p->getData();
        }catch(NodeException ex){
            string msg = "Error";
            msg += ex.what();
            
            throw ListException(msg);
        }

        }
        return p->getData();
}
/*
template <class T>
void List<T>::sortData(){
}
*/
template <class T>
void List<T>::deleteAll(){
        Node<T>* aux = header->getNext();
        while(header->getNext() != header){
            aux = header->getNext();

            header->setNext(header->getNext()->getNext());

            delete aux;
        }
        header->setPrev(header);
}

template <class T>
bool List<T>::isValid(Node<T>* p){
        Node<T>* aux = header->getNext();
        while(aux != header){
            if(aux == p){
                return true;
            }
            aux = aux->getNext();
        }
        return false;
}
template <class T>
void List<T>::print(){ /// recorrido circular !
        Node<T>* aux = header->getNext();
        while(aux != header){
            std::cout << aux ->getData() << ".";

            aux = aux->getNext();
        }

}

template <class T>
void List<T>::writeToDisk(std::string fileName){

        std::ofstream myFile;

        myFile.open(fileName, myFile.trunc);
        if(!myFile.is_open()){
            throw ListException("Could not open file");
        }


        Node<T>* aux = header->getNext();
        while(aux != header){

            myFile << aux->getData();

            aux = aux->getNext();
        }

        myFile.close();
}

template <class T>
void List<T>::readFromDisk(std::string fileName){
        std::ifstream myFile;
        myFile.open(fileName);

        if(!myFile.is_open()){
           throw ListException("Could not open file");
       }

        T myData;

        while(myFile >> myData){
           insertData(getLast(), myData);
        }
        myFile.close();
}
#endif // LIST_H_INCLUDED
