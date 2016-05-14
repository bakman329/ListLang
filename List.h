/**
 * Defines a linked list with several manipulation methods
 * Also, defines a public method for parsing a string of instructions
 */

#ifndef LANGUAGE_LIST_H
#define LANGUAGE_LIST_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <functional>

class List {
private:
    // A linked list node, with a value, index, and successive node
    typedef struct Node Node;

    // The tail(first node) and head(last node) of the list
    Node *root, *head;

    // The list of the instructions of all running loops
    std::vector<std::string> loops;

    // Returns the number of non-null nodes in the list
    int length();

    // Returns a pointer to node at a given index
    // If there is no node at this index, returns nullptr
    Node *get(int index);

    // Pushes a node to the top of the list, making it the new head, with value x
    Node *push(double x);

    // Outputs a message, alerting that the attempted action is impossible, as the list is too small
    static void too_small_error();

    // Pops the head of the list, assigns the new head, and returns a pointer to it
    Node *pop();

    // If the list contains at least two nodes, pops the top two nodes, and returns an array of their values
    // Else, return nullptr
    double *pop_two();

    // Pops every node in the list
    void clear();

    // Creates a clone of the list's head, and pushes it's value
    Node *clone_head();

    // Pops the head of the list, and prints its value
    void head_pop_print();

    // Pops the head of the list, and prints its value as an ascii character
    void head_pop_print_ascii();

    // Pushes a given character as either a double or an ASCII character
    void push_char(char ch);

    // Takes input from the user, and pushes the first character of it
    void push_input_char();

    // Takes input from the user, and pushes it
    void push_input_string();

    // Prints every node of the list
    void print();

    // Takes a lambda function that takes one double
    // Tries to pop the top node of the stack, and executes the function with its value
    // If the pop fails, return false
    // Else, return true
    bool unary_function(std::function<void(double)> func);

    // Takes a lambda function that takes two doubles
    // Tries to pop the top two nodes of the stack, and executes the function with their values
    // If the pop fails, return false
    // Else, return true
    bool binary_function(std::function<void(double, double)> func);

    // Takes a lambda function that takes two doubles and returns a double
    // Tries to pop the top two nodes of the stack, and execute the function with their values, pushing the result
    // If the pop fails, return false
    // Else, return true
    bool arithmetic_binary_function(std::function<double(double, double)> func);

    // Begins a loop, parsing and running the contents of str until the head of the stack equals 0 when checked
    void loop(std::string str);

public:
    // Initializes an empty list, and an empty list of loops
    List();

    // Parses the instructions in str, then prints the list.
    // If quiet is true, only print upon an appropriate instruction
    void parse(std::string str, bool quiet);
};

#endif //LANGUAGE_LIST_H
