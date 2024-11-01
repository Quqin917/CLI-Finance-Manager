#include "user.h"
#include "option.h"

void printHelp(char *arg, bool programExit = false) {
  printf("Usage: %s [OPTIONS]\n", arg);
  printf("Options:\n");
  printf("  -n, --new [username password]  Create a new user with optional username and password\n");
  printf("  -h, --help                     Display this help menu\n");

  if (programExit) {
    exit(EXIT_FAILURE);
  }
}

void commandOption(int argc, char **argv) {
  int c;
  const char *username = nullptr;
  const char *password = nullptr;

  if (argc > 5) {
    printHelp(argv[ 0 ], true);
  }

  while (true) {
    static struct  option long_options[] = {
      {"new",   no_argument,        0, 'n'},
      {"help",  no_argument,        0, 'h'},
      {0,       0,                  0, 0}
    };
    int option_index = 0;

    c = getopt_long(argc, argv, "hn::", long_options, &option_index);
    if (c == -1) {
      break;
    }

    switch (c) {
      case 'h':
        printHelp(argv[ 0 ]);
        break;

      case 'n':
        newUserFlag = true;

        if (optind >= argc) {
          const userDatabase database{ getUserInput("Hosts"), getUserInput("Username: "), getUserInput("Password: ")};

        } else if ( (argc - optind) == 3 ) {
          const userDatabase database{ argv[optind++], argv[optind++], argv[optind++] };

        } else {
          printHelp(argv[ 0 ], true);
        }
        break;

      case '?':
        fprintf(stderr, "Unknown Option '-%c'.\n", optopt);
        exit(EXIT_FAILURE);

      default:
        abort();
    }
  }

  exit(EXIT_SUCCESS);
}