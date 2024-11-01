#include "list.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*
    private methods
*/

void List::_free_memory(int* i_pointer)
{
    delete [] i_pointer;
}

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
    
    _free_memory(_internal_arr);
    _internal_arr = new_arr;

    _size += 10;
}

void List::_quicksort(int pivot_i, int start_i)
{
    if (start_i < pivot_i)
    {
        int new_pivot = _partition(pivot_i, start_i);
        _quicksort(new_pivot - 1, start_i);
        _quicksort(count() - 1, new_pivot + 1);
    }
}

int List::_partition(int pivot_i, int start_i)
{
    int pivot_pos = start_i; // to keep track of where the pivot will be
    for (int i = start_i; i < pivot_i; i++)
    {
        if (_internal_arr[i] < _internal_arr[pivot_i])
        {
            int temp = _internal_arr[pivot_pos];
            _internal_arr[pivot_pos] = _internal_arr[i];
            _internal_arr[i] = temp;
            pivot_pos++;
        }
    }
    int temp = _internal_arr[pivot_pos];
    _internal_arr[pivot_pos] = _internal_arr[pivot_i];
    _internal_arr[pivot_i] = temp;

    return pivot_pos;
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

int List::count() const
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

int List::get_val(int idx) const
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


List* List::slice(int start, int end) const
{
    List* list = new List();
    try
    {
        if (start < 0 || end > count() + 1)
            throw (start);
        for (int i = start; i < end; i++)
            list->add(get_val(i));

        return list;
    }
    catch(int start)
    {
        cout << "slice args out of range" << endl;
        return list;
    }
    
}

void List::sort()
{
    // pivot will always be the last element
    _quicksort(count() - 1, 0);
}

void List::extend(const List *list)
{
    int count = list->count();

    for (int i = 0; i < count; i++)
    {
        this->add(list->get_val(i));
    }
}
int List::find(int val) const
{
    for (int i = 0; i < this->count(); i++)
    {
        if (this->get_val(i) == val)
            return i;
    }

    return -1;
}

bool List::contains(int val) const
{
    for (int i = 0; i < this->count(); i++)
    {
        if (this->get_val(i) == val)
            return true;
    }

    return false;
}

List::~List()
{
    _free_memory(_internal_arr);
}