#ifndef DLIST_H_
#define DLIST_H_

template <typename T> class dlist {
    public:
    friend class iterator;
    private:
    friend class dnode;
    class dnode {
        public:
        friend class dlist<T>;
        friend class iterator;
        dnode(T node_val) :val(node_val) {}
        dnode() {}
        ~dnode() {}
        void print_val() {std::cout << val << "\n"}
        dnode *next;
        dnode *prev;
        T val;
    }
}

#endif  // DLIST_H