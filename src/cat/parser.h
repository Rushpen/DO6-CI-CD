#ifndef PARSER_H
#define PARSER_H
#include <getopt.h>
#include <stdio.h>

typedef struct {
  int b;
  int e;
  int E;
  int n;
  int s;
  int t;
  int T;
  int v;
} Flags;

Flags CatReadFlags(int argc, char *argv[]);

#endif
