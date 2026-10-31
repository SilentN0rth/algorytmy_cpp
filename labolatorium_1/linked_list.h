#pragma once

#include <cstddef>
template <typename T>
class linked_list{
    public:
    struct node {
        T data;
        node *prev;
        node *next;
    };

    typedef int (*data_cmp)(T,T);

    linked_list() : head(NULL), tail(NULL), count(0) {}
    size_t size() const { return count; }

    private:
        node *head;
        node *tail;
        size_t count;

};
