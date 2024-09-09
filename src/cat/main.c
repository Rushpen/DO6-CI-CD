#define _GNU_SOURCE  // getline
#include <getopt.h>
#include <stdio.h>

#include "output.h"
#include "parser.h"

int main(int argc, char* argv[]) {
  Flags flags = CatReadFlags(argc, argv);
  Cat(argc, argv, flags);

  return 0;
}
