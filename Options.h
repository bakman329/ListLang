/**
 * Defines several static methods to read and respond to program arguments
 */

#ifndef LANGUAGE_OPTIONS_H
#define LANGUAGE_OPTIONS_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "List.h"

namespace Options {
    // Prints a help message with information about running the program
    void help_message();

    // Runs an interactive read–eval–print loop(REPL)
    void shell();

    // Reads and runs instructions from a given file
    // If the file cannot be read, print an error
    void read_file(char *filename);

    // Runs different actions based on the program arguments
    // If no defined operation is specified, show a help message
    void handle_options(char *option);

    // If there are enough arguments to decide an action, pass the argument to handle_options
    // Else, give a help message
    void handle_args(int argc, char **argv);
};

#endif //LANGUAGE_OPTIONS_H
