#include <iostream>
#include <string>
#include "Stack.hpp"
#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"
#include "StackFactory.hpp"

using namespace std;

int main()
{
    cout << "STACK TESTS\n\n";
    
    // TEST 1: Create stacks
    cout << "TEST 1: Create stacks\n";
    Stack<int>* linked = StackFactory<int>::GetStack();
    Stack<int>* array = StackFactory<int>::GetStack(5);
    
    cout << "  linked empty: " << linked->isEmpty() << " (1)\n";
    cout << "  array empty: " << array->isEmpty() << " (1)\n\n";
    
    // TEST 2: Push operations
    cout << "TEST 2: Push 10,20,30\n";
    linked->push(10); array->push(10);
    linked->push(20); array->push(20);
    linked->push(30); array->push(30);
    
    cout << "  linked top: " << linked->peek() << " (30)\n";
    cout << "  array top: " << array->peek() << " (30)\n";
    cout << "  linked len: " << linked->getLength() << " (3)\n";
    cout << "  array len: " << array->getLength() << " (3)\n\n";
    
    // TEST 3: Pop operation
    cout << "TEST 3: Pop once\n";
    linked->pop(); array->pop();
    
    cout << "  linked top: " << linked->peek() << " (20)\n";
    cout << "  array top: " << array->peek() << " (20)\n";
    cout << "  linked len: " << linked->getLength() << " (2)\n";
    cout << "  array len: " << array->getLength() << " (2)\n\n";
    
    // TEST 4: Exceptions
    cout << "TEST 4: Exceptions\n";
    Stack<int>* empty = StackFactory<int>::GetStack();
    
    try { empty->peek(); cout << "  peek fail\n"; } 
    catch (const exception& e) { cout << "  peek ok: " << e.what() << "\n"; }
    
    try { empty->pop(); cout << "  pop fail\n"; } 
    catch (const exception& e) { cout << "  pop ok: " << e.what() << "\n\n"; }
    
    // TEST 5: Rotate
    cout << "TEST 5: Rotate\n";
    LinkedListStack<int>* rot = new LinkedListStack<int>();
    
    // Empty rotate
    try { rot->rotate(Stack<int>::LEFT); cout << "  empty rotate fail\n"; } 
    catch (const exception& e) { cout << "  empty rotate ok: " << e.what() << "\n"; }
    
    // Single element
    rot->push(5);
    rot->rotate(Stack<int>::LEFT);
    cout << "  single element after rotate: " << rot->peek() << " (5)\n";
    rot->clear();
    
    // Two elements
    rot->push(10); rot->push(20);
    cout << "  two elements original: "; rot->print();
    rot->rotate(Stack<int>::LEFT);
    cout << "  after LEFT: "; rot->print();
    rot->rotate(Stack<int>::RIGHT);
    cout << "  after RIGHT: "; rot->print();
    rot->clear();
    
    // Three elements
    rot->push(10); rot->push(20); rot->push(30);
    cout << "  three original (30,20,10): "; rot->print();
    rot->rotate(Stack<int>::LEFT);
    cout << "  after LEFT (20,10,30): "; rot->print();
    rot->rotate(Stack<int>::RIGHT);
    cout << "  after RIGHT (30,20,10): "; rot->print();
    
    delete rot;
    cout << "\n";
    
    // TEST 6: String stack
    cout << "TEST 6: String stack\n";
    Stack<string>* strLinked = StackFactory<string>::GetStack();
    Stack<string>* strArray = StackFactory<string>::GetStack(5);
    
    strLinked->push("Hello"); strArray->push("Hello");
    strLinked->push("World"); strArray->push("World");
    
    cout << "  linked top: " << strLinked->peek() << " (World)\n";
    cout << "  array top: " << strArray->peek() << " (World)\n";
    cout << "  linked len: " << strLinked->getLength() << " (2)\n";
    cout << "  array len: " << strArray->getLength() << " (2)\n\n";
    
    // TEST 7: Mixed ops
    cout << "TEST 7: Mixed ops\n";
    Stack<int>* mixLinked = StackFactory<int>::GetStack();
    Stack<int>* mixArray = StackFactory<int>::GetStack(5);
    
    mixLinked->push(5); mixArray->push(5);
    mixLinked->push(15); mixArray->push(15);
    mixLinked->pop(); mixArray->pop();
    mixLinked->push(25); mixArray->push(25);
    
    cout << "  linked top: " << mixLinked->peek() << " (25)\n";
    cout << "  array top: " << mixArray->peek() << " (25)\n";
    cout << "  linked len: " << mixLinked->getLength() << " (2)\n";
    cout << "  array len: " << mixArray->getLength() << " (2)\n\n";
    
    // Clean up
    delete linked; delete array; delete empty;
    delete strLinked; delete strArray;
    delete mixLinked; delete mixArray;
    
    cout << "ALL TESTS DONE\n";
    return 0;
}