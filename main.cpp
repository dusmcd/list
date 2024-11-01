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
bool test_sort();
bool test_extend();
bool test_find();
bool test_contains();
void run_tests();

int main()
{

    run_tests();

    return 0;
}

void run_tests()
{
    int total = 6;
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
    if (test_extend())
    {
        cout << "test_extend passed" << endl;
        passed++;
    }
    else
        cout << "test_extend failed" << endl;
    if (test_sort())
    {
        cout << "test_sort passed" << endl;
        passed++;
    }
    else
        cout << "test_sort failed" << endl;
    if (test_find())
    {
        cout << "test_find passed" << endl;
        passed++;
    }
    else
        cout << "test_find failed" << endl;
    if (test_contains())
    {
        cout << "test_contains passed" << endl;
        passed++;
    }
    else
        cout << "test_contains failed" << endl;

    cout << passed << " of " << total << " tests passed." << endl;
}

bool test_slice(int start, int end)
{
    List list = List();
    for (int i = 0; i < end + 10; i++)
        list.add(i * 5);
    
    List* newList = list.slice(start, end);
    
    for (int i = start; i < end; i++)
    {
        if (list.get_val(i) != newList->get_val(i))
            return false;
    }
    bool count_equals = newList->count() == (end - start);
    delete newList;
    return count_equals;
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

bool test_sort()
{
    List list = List();
    int nums[7] = {-1, 6, 0, 1, 2, 10, 5};
    int sorted_nums[7] = {-1, 0, 1, 2, 5, 6, 10};
    for (int i = 0; i < 7; i++)
        list.add(nums[i]);
    
    list.sort();

    for (int i = 0; i < 7; i++)
    {
        if (list.get_val(i) != sorted_nums[i])
            return false;
    }

    return true;
}

bool test_extend()
{
    List list = List();
    List another_list = List();

    for (int i = 0; i < 10; i++)
    {
        if (i > 4)
            another_list.add(i + 1);
        else
            list.add(i + 1);
    }
    
    list.extend(&another_list);

    for (int i = 0; i < 10; i++)
    {
        if (i > 4 && list.get_val(i) != another_list.get_val(i - 5))
        {

            cout << "another_list[" << i - 5 << "]: " << another_list.get_val(i - 5) << endl;
            return false;
        }
    }

    return true;
}

bool test_find()
{
    List list = List();
    int nums[7] = {2, 4, 6, 8, 10, 12, 14};
    for (int i = 0; i < 7; i++)
        list.add(nums[i]);
    
    return list.find(6) == 2 && list.find(15) == -1;
}

bool test_contains()
{
    List list = List();
    int nums[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        list.add(nums[i]);
    
    return list.contains(3) && !list.contains(10);
}