#ifndef Node_H_INCLUDED
#define Node_H_INCLUDED

#include <exception>

class NodeException : public std::exception {

    private:
        std::string msg;
    public:
        explicit NodeException(const char* message): msg(message){ }

        explicit NodeException(const std::string& message) : msg(message) { }

        virtual ~NodeException() throw() { }

        virtual const char* what() const throw () {
        return msg.c_str();
        }
};

template <class T> class Node{
private:
    T* dataPtr;
    Node<T>* prev;
    Node<T>* next;


public:
    Node<T>();
    Node(const T&);
    ~Node();
    T& getData();
    T* getdataPtr();
    Node<T>* getPrev();
    Node<T>* getNext();

    void setPrev(Node<T>*);
    void setDataPtr(T*);
    void setData(const T&);
    void setNext(Node<T>*);
};

template <class T>
Node<T>::Node(){
    prev = nullptr;
    next = nullptr;
    dataPtr = nullptr;

}
template <class T>
Node<T>::Node(const T& e) : Node<T>() {   //se activa y manda llamar el otro constructor.
    dataPtr = new T(e);

    if(dataPtr == nullptr){
            throw NodeException("Unavailable Memory when creating new Node");

    }
}
template <class T>
Node<T>::~Node(){
  delete dataPtr;
}
template <class T>
T* Node<T>::getdataPtr(){
    return dataPtr;
}
template <class T>
T& Node<T>::getData(){
    if(dataPtr == nullptr){
        throw NodeException("Unaccesible Memory");
    }
    return *dataPtr; //de-reference dataPtr
}
template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}
template <class T>
Node<T>* Node<T>::getPrev(){
    return prev;
}
template <class T>
void Node<T>::setDataPtr(T* p){
    dataPtr = p;
}
template <class T>
void Node<T>::setData(const T& e){
    if(dataPtr == nullptr){
        dataPtr = new T(e);
        if(dataPtr == nullptr){
            throw NodeException("Unavailable Memory, setData");
        }
    }
    else{
    *dataPtr = e;
    }
}
template <class T>
void Node<T>::setNext(Node<T>* p){
    next = p;
}

template <class T>
void Node<T>::setPrev(Node<T>* p){
    prev = p;
}
#endif // Node_H_IRRNCLUDED
