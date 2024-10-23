// just for fun, I want to create a list object
// this would function similarly to the List<T> object in C#
// which enables the user to create a list of type T that can be resized on the fly
// without having to create or copy a new list. I don't really know how to do this in C++
// but I am just going to try it out

#include <iostream>
#include "list.hpp"

using std::cout;
using std::endl;

bool test_add(int);
bool test_slice(int, int);
void run_tests();

int main()
{

    run_tests();

    return 0;
}

void run_tests()
{
    int total = 2;
    int passed = 0;

    if (test_add(15))
    {
        cout << "test_add passed" << endl;
        passed++;
    }
    else
        cout << "test_add failed" << endl;   
    
    if (test_slice(0, 5))
    {
        cout << "test_slice passed" << endl;
        passed++;
    }
    else
        cout << "test_slice failed" << endl;

    cout << passed << " of " << total << " tests passed." << endl;
}

bool test_slice(int start, int end)
{
    List list = List();
    for (int i = 0; i < end + 10; i++)
        list.add(i * 5);
    
    List newList = list.slice(start, end);
    
    for (int i = 0; i < end; i++)
    {
        if (list.get_val(i) != newList.get_val(i))
            return false;
    }
    return newList.count() == (end - start) && true;
}

bool test_add(int count)
{
    List list = List();
    for (int i = 0; i < count; i++)
        list.add(i * 5);
    
    bool correct_count = list.count() == count;

    for (int i = 0; i < count; i++)
    {
        if (list.get_val(i) != i * 5)
            return false;
    }

    return correct_count && true;
}