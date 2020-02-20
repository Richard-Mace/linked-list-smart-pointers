/* 
 * File:   main.cpp; Simple driver for LinkedList.
 * Author: richm
 *
 * Created on 24 January 2020, 10:21
 */

#include <cstdlib>
#include "LinkedList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    LinkedList<int> list;
    
    cout << "Allocating Nodes... ";
    for (int i = 0; i < 10; ++i) {
        list.push(i);
    }
    cout << "done!\n";
    
    cout << "The list now contains: \n";
    cout << list << endl;
    
    list.pop();
    list.pop();
    list.pop();
    cout << "After 3 pop()'s\n";
    list.print(cout);
    
    // copy the list
    cout << "Creating list2 as copy of list using copy  ...\n";
    LinkedList<int> list2 = std::move(list);
    
    cout << "After copying, list is: \n";
    cout << list << endl;
    cout << "and list2 is:\n";
    cout << list2 << endl;
    
    list2.pop();
    list2.pop();
    list2.pop();
    cout << "After 3 pop()'s list 2 is:\n";
    cout << list2 << endl;
    
    cout << "peek() on list 2 returns: " << list2.peek() << endl;
    cout << "... Another peek() on list2 returns: " << list2.peek() << endl;
    
    list.clean();
    try {
        cout << "peek() on list returns: " << list.peek() << endl;
    }
    catch (out_of_range& e) {
        cout << "\nEXCEPTION: " << e.what() << endl;
    }
    
    cout << "Now after cleaning the list2...\n";
    list2.clean();
    cout << list2 << endl;
    
    return 0;
}

