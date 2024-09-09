#include "parser.h"

Flags GrepReadFlags(int argc, char *argv[]) {
  Flags flags = {0, false, false, false, false, false, false, false, false};
  int currentFlag = getopt(argc, argv, "eivclnhsfo");
  for (; currentFlag != -1; currentFlag = getopt(argc, argv, "eivclnhsfo")) {
    switch (currentFlag) {
      case 'e':
        flags.regex_flag |= REG_EXTENDED;
        break;
      case 'i':
        flags.regex_flag |= REG_ICASE;
        break;
      case 'v':
        flags.v = true;
        break;
      case 'c':
        flags.c = true;
        break;
      case 'l':
        flags.l = true;
        break;
      case 'n':
        flags.n = true;
        break;
      case 'h':
        flags.h = true;
        break;
      case 's':
        flags.s = true;
        break;
      case 'f':
        flags.f = true;
        break;
      case 'o':
        flags.o = true;
        break;
    }
  }
  return flags;
}
