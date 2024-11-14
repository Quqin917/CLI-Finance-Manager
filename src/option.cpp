#include "option.h"

// Function to display the help screen
void printHelp( bool programExit = false) {
  // Print usage information and available options
  printf("Usage: ./finman [OPTIONS]\n");
  printf("Options:\n");
  printf("  -n, --new [username password]  Create a new user with optional username and password\n");
  printf("  -h, --help                     Display this help menu\n");

  // Check if the programExit is true, exit the program with failure status
  if (programExit) {
    exit(EXIT_FAILURE);
  }
}

// Function to handle command-line options and arguments
void commandOption(int argc, char **argv) {
  int c;  // Variable to store the option character

  // Check if there are too many arguments and check if the first character is a dash
  if (argc > 5 || argv[1][0] != '-') {
    // Display help and exit the program
    printHelp( true );
  }

  // Loop to parse command-line options
  while (true) {
    // Define the list of long options
    static struct  option long_options[] = {
      {"new",   no_argument,        0, 'n'},
      {"help",  no_argument,        0, 'h'},
      {0,       0,                  0, 0}
    };
    int option_index = 0;

    // Parse options using getopt_long
    c = getopt_long(argc, argv, "hn::", long_options, &option_index);
    
    // Break loop if there are no more options
    if (c == -1) {
      break;
    }

    // Handle each option
    switch (c) {
      case 'h':
        // If help is selected, display help
        printHelp();
        break;

      case 'n':
        std::cout << "Hello New User\n";
        
        // If no additional arguments, prompt user for input
        if (optind >= argc) {
          // ask username and password
          userDatabase database{ getUserInput<std::string>("Username: "), getPassword("Password: ") };

          newUserQuestion( database );

        // If two arguments are provided, use them for username and password
        } else if ( (argc - optind) == 2 ) {
          // insert the provided username and password
          userDatabase database{ argv[optind++], argv[optind++] };

          newUserQuestion( database );

        // If arguments are missing or have an extra argument, display help and exit
        } else {
          printHelp( true );
        }
        break;

      // Handle unknown options
      case '?':
        break;

      default:
        abort();
    }
  }

  // Exit successfully if all options were processed
  exit(EXIT_SUCCESS);
}