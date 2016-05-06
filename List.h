#ifndef LANGUAGE_LIST_H
#define LANGUAGE_LIST_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

class List {
private:
    typedef struct Node Node;
    Node *root, *head;

    int length();
    Node *get(int index);
    Node *push(double x);
    void too_small_error();
    Node *pop();
    double *pop_two();
    void clear();
    Node *clone_head();
    void head_pop_print();
    void print();

public:
    List();

    void parse(std::string str);
};

#endif //LANGUAGE_LIST_H
