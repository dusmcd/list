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
        List _merge_sort(const List *list);
        List _merge(const List *left, const List *right);

    public:
        List();
        List(int init_size);
        void add(int num);
        void extend(const List *list);

        // returns the index for the given value
        // returns -1 if the value is not found
        int find(int val) const;
        bool contains(int val) const;
        int get_val(int idx) const;
        void set_val(int idx, int val);
        List sort();
        List slice(int start, int end) const;
        int count() const;
};





#endif