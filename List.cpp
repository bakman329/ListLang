#include "List.h"

struct Node {
    double value;
    int index;
    Node *next;
};

List::List() {
    root = new Node;
    root->index = 0;
    head = root;
    head->next = nullptr;
}

int List::length() {
    int count = 0;
    Node *temp = root;
    while (temp->next != nullptr) {
        temp = temp->next;
        count++;
    }

    return count;
}

Node *List::get(int index) {
    Node *temp = root;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp;
}

Node *List::push(double x) {
    head->next = new Node;
    int old_index = head->index;
    head = head->next;
    head->next = nullptr;
    head->value = x;
    head->index = old_index + 1;
    return head;
}

void too_small_error() {
    std::cout << "Error: Stack too small\n";
}

Node *List::pop() {
    if(length() < 1) {
        too_small_error();
        return nullptr;
    }
    Node *prev = get(head->index - 1);
    head = prev;
    Node *old_head_next = new Node;
    old_head_next->value = head->next->value;
    old_head_next->index = head->next->index;
    free(head->next);
    head->next = nullptr;
    return old_head_next;
}

double *List::pop_two() {
    static double list[2];
    if (length() >= 2) {
        list[0] = pop()->value;
        list[1] = pop()->value;
        return list;
    }
    else {
        return nullptr;
    }
}

void List::clear() {
    while (pop() != nullptr) {};
}

Node *List::clone_head() {
    if (length() < 1) {
        too_small_error();
        return nullptr;
    }
    return push(head->value);
}

void List::head_pop_print() {
    if (head == nullptr){
        too_small_error();
        return;
    }
    std::cout << head->value << '\n';
    pop();
}

void List::print() {
    Node *temp = root;
    int count = 0;
    std::cout << "{";
    while (temp->next != nullptr) {
        std::cout << temp->next->value;
        temp = temp->next;
        if (temp->next != nullptr) {
            std::cout << ", ";
        }
        count++;
    }
    std::cout << "}\n";
}

void List::parse(std::string str) {
    bool should_print = true;
    for (char token : str) {
        if (isdigit(token)) {
            push(token - '0');
            continue;
        }

        switch (token) {
            case '+': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param0 + param1);
                break;
            }
            case '-': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param1 - param0);
                break;
            }
            case '*': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param0 * param1);
                break;
            }
            case '/': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param1 / param0);
                break;
            }
            case '^': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(std::pow(param1, param0));
                break;
            }
            case '=': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param0 == param1);
                break;
            }
            case '>': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param0 > param1);
                break;
            }
            case '<': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param0 < param1);
                break;
            }
            case '.':
                head_pop_print();
                should_print = false;
                break;
            case ',':
                pop();
                break;
            case '@':
                clear();
                break;
            case '#':
                print();
                should_print = false;
                break;
            case '_':
                clone_head();
                break;
            default:
                break;
        }
    }

    if (should_print) {
        print();
    }
}


