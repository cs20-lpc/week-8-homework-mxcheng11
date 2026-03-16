#include <stdexcept>

template <typename T>
LinkedListStack<T>::LinkedListStack()
{ 
    top = nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    top = nullptr;
    this->length = 0;
    copy(copyObj);
}


template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    // loop through linked list, deleting each node
    while (top != nullptr)
    {
        Node<T> *curr = top;
        top = top->next;
        delete curr;
    }
    // reset length 
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    // check if initial stack is empty 
    if (copyObj.top == nullptr) {
        top = nullptr;
        this->length = 0;
        return;
    }

    else {
        // create new node for the top of the stack
        top = new Node<T>(copyObj.top->data);
        this->length = copyObj.length;

        // traverse the original and new stack
        Node<T> *currCopy = copyObj.top->next; // start from the second node in the original stack
        Node<T> *currNew = top; // start from the top of the new stack

        // loop through the original stack, creating new nodes in the new stack
        while (currCopy != nullptr) {
            currNew->next = new Node<T>(currCopy->data); // create a new node with the same data
            currNew = currNew->next; // move to next node in the new stack
            currCopy = currCopy->next; // move to next node in the original stack
        }
    }
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    // verify stack isn't empty
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty, cannot peek.");
    }

    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    // verify stack isn't empty
    if (isEmpty())
    {
        throw std::runtime_error("no elements to pop, stack is empty");
    }

    //
    Node<T> *temp = top; 
    top = top->next; 
    delete temp;
    
    // update length 
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    // create new node 
    Node<T> *newNode = new Node<T>(elem);

    //point new node to top
    newNode->next = top; 

    // point top to new node 
    top = newNode;

    // update length
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty()) 
    {
         throw std::runtime_error("Stack is empty, cannot rotate.");
    }

    // one node
    if (this->length == 1) return; 

    // left rotation: top node to bottom 
    if (dir == Stack<T>::LEFT)
    {
        Node<T> *oldTop = top;
        top = top->next;
        oldTop->next = nullptr;

        Node<T> *curr = top;

        //traverse to the end of the stack
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        // point last node to old top
        curr->next = oldTop;   
    }

    // right rotation: bottom node to top
    else if (dir == Stack<T>::RIGHT)
    {
        Node<T> *curr = top;
        Node<T> *prev = nullptr;

        // traverse to the end of the stack
        while(curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        // point last node to top
        curr->next = top;

        // point previous node to null
        prev->next = nullptr;

        // update top to last node
        top = curr; 
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
