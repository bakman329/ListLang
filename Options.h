/**
 * Defines several static methods to read and respond to program arguments
 */

#ifndef LANGUAGE_OPTIONS_H
#define LANGUAGE_OPTIONS_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "List.h"

// TODO: Replace class with namespace, and change methods to non-static
class Options {
private:
    // Prints a help message with information about running the program
    static void help_message();

    // Runs an interactive read–eval–print loop(REPL)
    static void shell();

    // Reads and runs instructions from a given file
    // If the file cannot be read, print an error
    static void read_file(char *filename);

    // Runs different actions based on the program arguments
    // If no defined operation is specified, show a help message
    static void handle_options(char *option);

public:
    // If there are enough arguments to decide an action, pass the argument to handle_options
    // Else, give a help message
    static void handle_args(int argc, char **argv);
};

#endif //LANGUAGE_OPTIONS_H
