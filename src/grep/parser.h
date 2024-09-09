#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <getopt.h>
#include <regex.h>
typedef struct {
    int regex_flag;
    bool v;
    bool c;
    bool l;
    bool n;
    bool h;
    bool s;
    bool f;
    bool o;
} Flags;

Flags GrepReadFlags(int agrc, char *argv[]);

#endif

