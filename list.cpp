#include "list.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*
    private methods
*/

void print_list(List list)
{
    for (int i = 0; i < list.count(); i++)
        cout << list.get_val(i) << " ";
    
    cout << endl;
}
void List::_resize_arr()
{
    int* new_arr = new int[_size + 10];
    for (int i = 0; i < _size; i++)
        new_arr[i] = _internal_arr[i];
    
    delete [] _internal_arr;
    _internal_arr = new_arr;
    _size += 10;
}

List List::_merge_sort(List *list)
{
    if (list->count() == 1)
        return *list;
    
    int middle = list->count() / 2;
    List left = list->slice(0, middle);
    List right = list->slice(middle, list->count());

    List r_left = _merge_sort(&left);
    List r_right = _merge_sort(&right);
    return _merge(&r_left, &r_right);
}

List List::_merge(List *left, List *right)
{
    List merged_list = List();
    int left_i = 0;
    int right_i = 0;

    while(true)
    {
        if (left_i > left->count() - 1)
        {
            // add the rest of the right array to the merged list
            List remaining = right->slice(right_i, right->count());
            merged_list.extend(&remaining);
            break;
        }
        else if (right_i > right->count() - 1)
        {
            // add the rest of the left array to the merged list
            List remaining = left->slice(left_i, left->count());
            merged_list.extend(&remaining);
            break;
        }
        else if (left->get_val(left_i) <= right->get_val(right_i))
        {
            merged_list.add(left->get_val(left_i));
            left_i++;
        }
        else if (right->get_val(right_i) <= left->get_val(left_i))
        {
            merged_list.add(right->get_val(right_i));
            right_i++;
        }
    }

    return merged_list;
}


/*
    public methods
*/

List::List()
{
    _internal_arr = new int[10];
}

List::List(int init_size)
{
    _internal_arr = new int[init_size];
}

int List::count()
{
    return _last_idx_val + 1;
}

void List::add(int num)
{
    if (_last_idx_val + 1 >= _size)
    {
        _resize_arr();
    }
    _internal_arr[_last_idx_val + 1] = num;
    _last_idx_val++;
}

int List::get_val(int idx)
{
    try {
        if (idx > _last_idx_val)
            throw (idx);
        return _internal_arr[idx];
    } catch(int idx) {
        cout << "index " << idx << " is out of bounds" << endl;
        return -1;
    }
}


List List::slice(int start, int end)
{
    List list = List();
    try
    {
        if (start < 0 || end > this->count() + 1)
            throw (start);
        for (int i = start; i < end; i++)
            list.add(this->get_val(i));

        return list;
    }
    catch(int start)
    {
        cout << "slice args out of range" << endl;
        return list;
    }
    
}

List List::sort()
{
    return _merge_sort(this);
}

void List::extend(List *list)
{
    int count = list->count();

    for (int i = 0; i < count; i++)
    {
        this->add(list->get_val(i));
    }
}

List::~List()
{
    // delete [] _internal_arr;
    // _internal_arr = nullptr;
}