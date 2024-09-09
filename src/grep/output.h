#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include "parser.h"

void Grep(int argc, char *argv[], Flags flags);
void GrepCount(FILE *file, char const *filename, regex_t *preg, int n);
void GrepFlagL(FILE *file, char const *filename, regex_t *preg);
void GrepFlagN(FILE *file, char const *filename, regex_t *preg, int n);
void GrepFlagV(FILE *file, char const *filename, regex_t *preg, int n);
void GrepFlagH(FILE *file, regex_t *preg);
void GrepFileDefault(FILE *file, char const *filename, regex_t *preg, int n);
void GrepFlagO(FILE *file, char const *filename, regex_t *preg, int n);

#endif
