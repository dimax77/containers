#ifndef TEST2_H_
#define TEST2_H_

namespace s21{

    template <typename T>
    class List {
        struct Node {
            T *prev, *next;
            T val;
        };

        struct Iterator {

        };

        List() : Head(nullptr), Tail(nullptr) {};
        
    };

};
#endif TEST2_H_