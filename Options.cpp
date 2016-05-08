#include "Options.h"

void Options::help_message() {
    std::cout << "Usage: ./<executable> -[h|i] [file]\n"
              << "-h: Show this help message\n"
              << "-i: Interactive prompt\n"
              << "To read a file, pass the file as a parameter, with no options\n";
}

void Options::shell() {
    List list;

    std::cout << "List Language Interactive Prompt\nPress Control-C to Exit\n";
    while (true) {
        std::string input;
        std::cout << ">> ";
        std::cin >> input;
        list.parse(input, false);
    }
}

void Options::read_file(char *filename) {
    List list;
    std::string line = "";
    std::ifstream file(filename);

    if (file.is_open()) {
        // Read each line of the file into the string 'line', then parse that line
        while (getline(file, line)) {
            list.parse(line, true);
        }
        file.close();
    }
    else {
        std::cerr << "Failed to open file \"" << filename << "\"\n";
    }
}

void Options::handle_options(char *option) {
    if (strcmp(option, "-h") == 0) {
        help_message();
    }
    else if (strcmp(option, "-i") == 0) {
        shell();
    }
    else {
        read_file(option);
    }
}

void Options::handle_args(int argc, char **argv) {
    if (argc < 2){
        help_message();
    }
    else {
        handle_options(argv[1]);
    }
}





