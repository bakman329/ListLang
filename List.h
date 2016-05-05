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

    double *pop_two();

public:
    List();

    int length();
    Node *get(int index);
    Node *push(double x);
    Node *pop();
    void clear();
    Node *clone_head();

    void head_pop_print();

    void parse(std::string str);

    void print();
};

#endif //LANGUAGE_LIST_H
