#ifndef LANGUAGE_LIST_H
#define LANGUAGE_LIST_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

class List {
private:
    typedef struct Node Node;
    Node *root, *head;
    std::vector<std::string> loops;

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
    void loop(std::string str);

public:
    List();

    void parse(std::string str, bool quiet);
};

#endif //LANGUAGE_LIST_H
