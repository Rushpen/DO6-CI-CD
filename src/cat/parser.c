#include "parser.h"

Flags CatReadFlags(int argc, char *argv[]) {
  struct option long_opts[] = {{"number-nonblank", no_argument, NULL, 'b'},
                               {"number", no_argument, NULL, 'n'},
                               {"squeeze-blank", no_argument, NULL, 's'}};

  int currentFlag = getopt_long(argc, argv, "beEnstTv", long_opts, NULL);
  Flags flags = {0, 0, 0, 0, 0, 0, 0, 0};
  for (; currentFlag != -1;
       currentFlag = getopt_long(argc, argv, "beEnstTv", long_opts, NULL)) {
    switch (currentFlag) {
      case 'e':
        flags.e = 1;
        break;
      case 'E':
        flags.E = 1;
        break;
      case 'b':
        flags.b = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 't':
        flags.t = 1;
        break;
      case 'T':
        flags.T = 1;
        break;
      case 'v':
        flags.v = 1;
        break;
      case '?':
        printf("Unknown option: -%c\n", optopt);
        break;
    }
  }
  return flags;
}
