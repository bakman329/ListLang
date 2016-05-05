#ifndef LANGUAGE_OPTIONS_H
#define LANGUAGE_OPTIONS_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "List.h"

class Options {
private:
    static void help_message();
    static void shell();
    static void read_file(char *filename);
    static void handle_options(char *option);

public:
    static void handle_args(int argc, char **argv);
};

#endif //LANGUAGE_OPTIONS_H
