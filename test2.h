#ifndef TEST2_H_
#define TEST2_H_

namespace s_21{

    template <typename T>
    class List {
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef struct Iterator iterator;
        // typedef const struct Iterator const_iterator;
        typedef size_t size_type;
        
        public:
        struct Node {
            value_type *prev, *next;
            value_type val;
        };
        struct Iterator {
            Node* node_pointer;
            begin() {
                return Head;
            }
            end() {
                return Tail;
            }

        };
        // const struct Iterator {

        // };


        //  Constructors

        public:
        List() : Head(nullptr), Tail(nullptr) {};
        List(size_t n);

        // Methods

        private:
        Node *Head, *Tail;
        size_type size;
        size_type capacity;

        public:
        
    };

    

};
#endif  // TEST2_H_