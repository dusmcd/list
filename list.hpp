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
        void _quicksort(int pivot_i, int start_i);
        int _partition(int pivot_i, int start_i);
        void _free_memory(int* i_pointer);

    public:
        List();
        List(int init_size);
        ~List();
        void add(int num);
        void extend(const List *list);

        // returns the index for the given value
        // returns -1 if the value is not found
        int find(int val) const;
        bool contains(int val) const;
        int get_val(int idx) const;
        void set_val(int idx, int val);
        void sort();
        
        // don't forget to free this pointer after use
        List* slice(int start, int end) const;
        int count() const;
        void forEach(void (*callback)(int));

        // don't forget to free up this pointer after use
        List* where(bool (*callback)(int));

        int operator[](int i) const;
};





#endif