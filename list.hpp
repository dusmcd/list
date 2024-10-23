#ifndef LIST_HPP
#define LIST_HPP

// just to get going, I am only going to implement this with integers
// once I get that working, I may add in generics

class List
{
    private:
        int* _internal_arr;
        int _size = 10;
        int _last_idx_val = -1;
        void _resize_arr();
        List _merge_sort(List list);
        List _merge(List left, List right);

    public:
        List();
        List(int init_size);
        void add(int num);
        void extend(List list);
        int get_val(int idx);
        void set_val(int idx, int val);
        List sort();
        List slice(int start, int end);
        int count();
        ~List();
};





#endif