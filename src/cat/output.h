#include <errno.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

void Cat(int argc, char *argv[], Flags flags);
void processFlagV(const char *line);
void processFlag_t(const char *line);
void processFlagB(const char *line, int *line_number, int *is_new_line);
void processFlagN(const char *line, int *line_number, int *is_new_line);
void processFlag_e(const char *line);
void processFlagE(const char *line);
void processFlagT(const char *line);
void processFlagS(const char *line, int *line_number, int *is_new_line,
                  char *prev_str, int *isFirstLine, size_t max_buffer_size);
