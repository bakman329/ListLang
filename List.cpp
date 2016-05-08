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
    loops = std::vector<std::string>();
    loops.push_back("");
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

void List::too_small_error() {
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
    double len = length();
    for (int i = 0; i < len; i++) {
        pop();
    }
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
    std::cout << head->value;
    pop();
}

void List::head_pop_print_ascii() {
    if (head == nullptr){
        too_small_error();
        return;
    }
    std::cout << (char) head->value;
    pop();
}

void List::push_char(char ch) {
    if (isdigit(ch)) {
        push(ch - '0');
    }
    else if (isalpha(ch)) {
        push((double) ch);
    }
}

void List::push_input_char() {
    std::string str;
    std::cout << ">>> ";
    std::cin >> str;
    push_char(str[0]);
}

void List::push_input_string() {
    std::string str;
    std::cout << ">>> ";
    std::cin >> str;
    for (char ch : str) {
        push_char(ch);
    }
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

void List::loop(std::string str) {
    while (head->value != 0) {
        parse(str, true);
    }
}

void List::parse(std::string str, bool quiet) {
    bool should_print = true;
    bool loop_mode = false;
    loops.clear();
    for (char token : str) {
        // TODO: Implement nested loops, to allow for if statements in loops
        if (token == '[') {
            loop_mode = true;
            continue;
        }
        if (token == ']') {
            loop_mode = false;
            loop(loops[0]);
            loops[0] = "";
            continue;
        }
        if (loop_mode) {
            loops[0] += token;
            continue;
        }

        if (isalnum(token)) {
            push_char(token);
            continue;
        }

        // TODO: Refactor and optimize
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
                push(param1 == param0);
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
                push(param1 > param0);
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
                push(param1 < param0);
                break;
            }
            case ':': {
                double *list = pop_two();
                if (list == nullptr) {
                    too_small_error();
                    break;
                }
                double param0 = list[0];
                double param1 = list[1];
                push(param0);
                push(param1);
                break;
            }
            case '!': {
                Node *node = pop();
                if (node == nullptr) {
                    too_small_error();
                    break;
                }
                push((node->value == 0) ? 1 : 0);
                break;
            }
            case '.':
                head_pop_print();
                should_print = false;
                break;
            case '\"':
                head_pop_print_ascii();
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
            case '~': {
                push_input_char();
                break;
            }
            case '`': {
                push_input_string();
                break;
            }

            default:
                break;
        }
    }

    if (should_print && !quiet) {
        print();
    }
}