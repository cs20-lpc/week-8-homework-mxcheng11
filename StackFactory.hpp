#include <iostream>
#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"

template <typename T>
class StackFactory {
    public:
        static Stack<T>* GetStack(int maxSize = 0)
        {
            if (maxSize == 0)
                return new LinkedListStack<T>();
            else 
                return new ArrayStack<T>(maxSize);
        }

};