#include "Options.h"

int main(int argc, char **argv) {
    // Depending on program arguments, do one of the following:
    // -h: Show help message
    // -i: Begin interactive prompt
    // [filename]: Run instructions from file
    Options::handle_args(argc, argv);
}