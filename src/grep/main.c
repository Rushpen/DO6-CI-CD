#define _GNU_SOURCE  // getline
#include <stdio.h>

#include "output.h"
#include "parser.h"

int main(int argc, char* argv[]) {
  Flags flags = GrepReadFlags(argc, argv);
  Grep(argc, argv, flags);
  return 0;
}