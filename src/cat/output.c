#include "output.h"

void Cat(int argc, char *argv[], Flags flags) {
  char **pattern = &argv[1];
  char **end = &argv[argc];

  for (char **filename = pattern; filename != end; ++filename) {
    if (**filename == '-') continue;

    FILE *file = fopen(*filename, "rb");
    if (errno) {
      fprintf(stderr, "%s", argv[0]);
      perror(*filename);
      continue;
    }
    if (file == NULL) {
      fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
      continue;
    }
    char *line = NULL;
    size_t len = 0;

    int line_number = 1;
    int is_new_line = 1;
    char prev_str[1024] = "";
    int isFirstLine = 1;
    while (getline(&line, &len, file) > 0) {
      if (flags.v) {
        processFlagV(line);
      } else if (flags.b) {
        processFlagB(line, &line_number, &is_new_line);
      } else if (flags.n) {
        processFlagN(line, &line_number, &is_new_line);
      } else if (flags.s) {
        processFlagS(line, &line_number, &is_new_line, prev_str, &isFirstLine,
                     1024);
      } else if (flags.e) {
        processFlag_e(line);
      } else if (flags.E) {
        processFlagE(line);
      } else if (flags.t) {
        processFlag_t(line);
      } else if (flags.T) {
        processFlagT(line);
      }
    }
    free(line);
    fclose(file);
  }
}

void processFlagV(const char *line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    int ch = (unsigned char)line[i];

    if (ch <= 31 || ch == 127) {
      if (ch == '\t' || ch == '\n') {
        printf("%c", ch);
      } else {
        printf("^%c", ch + 64);
      }
    } else if (ch >= 128 && ch <= 255) {
      printf("M-%c", ch - 128);
    } else {
      printf("%c", ch);
    }
  }
}

void processFlag_t(const char *line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    int ch = line[i];
    if (ch == '\t') {
      putchar('^');
      putchar('I');
    } else if (ch <= 31 || ch == 127) {
      if (ch == '\n') {
        putchar(ch);
      } else {
        printf("^%c", ch + 64);
      }
    } else if (ch >= 128 && ch <= 255) {
      printf("M-%c", ch - 128);
    } else {
      putchar(ch);
    }
  }
}

void processFlagT(const char *line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    int ch = line[i];

    if (ch == '\t') {
      putchar('^');
      putchar('I');
    } else {
      putchar(ch);
    }
  }
}

void processFlag_e(const char *line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    int ch = line[i];
    if ((ch <= 31 || ch == 127)) {
      if (ch == '\n') {
        putchar('$');
        putchar('\n');
      } else if (ch == '\t') {
        putchar(ch);
      } else {
        printf("^%c", ch + 64);
      }
    } else if (ch >= 128 && ch <= 255) {
      printf("M-%c", ch - 128);
    } else {
      putchar(ch);
    }
  }
}

void processFlagE(const char *line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    int ch = line[i];

    if (ch == '\n') {
      putchar('$');
      putchar('\n');
    } else {
      putchar(ch);
    }
  }
}

void processFlagB(const char *line, int *line_number, int *is_new_line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    char ch = line[i];

    if (*is_new_line && ch != '\n') {
      printf("%6d\t", *line_number);
      *is_new_line = 0;
      (*line_number)++;
    }

    putchar(ch);

    if (ch == '\n') {
      *is_new_line = 1;
    }
  }
}

void processFlagN(const char *line, int *line_number, int *is_new_line) {
  for (int i = 0; line[i] != '\0'; ++i) {
    char ch = line[i];

    if (*is_new_line) {
      printf("%6d\t", *line_number);
      *is_new_line = 0;
      (*line_number)++;
    }

    putchar(ch);

    if (ch == '\n') {
      *is_new_line = 1;
    }
  }
}

void processFlagS(const char *line, int *line_number, int *is_new_line,
                  char *prev_str, int *isFirstLine, size_t max_buffer_size) {
  if (line[0] != '\n') {
    *is_new_line = 0;
    (*line_number)++;
  }

  if (*is_new_line || (strncmp(line, prev_str, max_buffer_size) != 0)) {
    printf("%s", line);
  }

  strncpy(prev_str, line, max_buffer_size);
  prev_str[max_buffer_size - 1] = '\0';
  *isFirstLine = 0;
}
