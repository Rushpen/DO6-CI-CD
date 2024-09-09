#include "output.h"

void Grep(int argc, char *argv[], Flags flags) {
  char **pattern = &argv[1];
  char **end = &argv[argc];
  regex_t preg_storage;
  regex_t *preg = &preg_storage;
  int numberFiles = argc - 2;

  for (; pattern != end && pattern[0][0] == '-'; ++pattern) --numberFiles;
  if (pattern == end) {
    printf("Не найден шаблон!\n");
    exit(1);
  }

  if (regcomp(preg, *pattern, flags.regex_flag)) {
    fprintf(stderr, "Ошибка компиляции регулярного выражения.\n");
    exit(1);
  }

  for (char **filename = pattern + 1; filename != end; ++filename) {
    if (**filename == '-') {
      --numberFiles;
      continue;
    }

    FILE *file = fopen(*filename, "rb");
    if (!file) {
      if (flags.s) {
        continue;
      } else {
        fprintf(stderr, "%s: ", argv[0]);
        perror(*filename);
        continue;
      }
    }
    if (flags.c) {
      GrepCount(file, *filename, preg, numberFiles);
    } else if (flags.l) {
      GrepFlagL(file, *filename, preg);
    } else if (flags.n) {
      GrepFlagN(file, *filename, preg, numberFiles);
    } else if (flags.v) {
      GrepFlagV(file, *filename, preg, numberFiles);
    } else if (flags.h) {
      GrepFlagH(file, preg);
    } else if (flags.o) {
      GrepFlagO(file, *filename, preg, numberFiles);
    } else {
      GrepFileDefault(file, *filename, preg, numberFiles);
    }
    fclose(file);
  }

  regfree(preg);
}

void GrepCount(FILE *file, char const *filename, regex_t *preg, int n) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  size_t count = 0;
  while (getline(&line, &len, file) > 0) {
    if (!regexec(preg, line, 1, &match, 0)) {
      ++count;
    }
  }
  if (n > 1)
    printf("%s:%ld\n", filename, count);
  else
    printf("%ld\n", count);
  free(line);
}

void GrepFlagL(FILE *file, char const *filename, regex_t *preg) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  int fileOutputted = 0;
  while (getline(&line, &len, file) > 0) {
    if (!regexec(preg, line, 1, &match, 0)) {
      if (!fileOutputted) {
        printf("%s\n", filename);
        fileOutputted = 1;
      }
    }
  }
  free(line);
}

void GrepFlagN(FILE *file, char const *filename, regex_t *preg, int n) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  int line_number = 1;
  while (getline(&line, &len, file) > 0) {
    if (!regexec(preg, line, 1, &match, 0)) {
      if (n > 1)
        printf("%s:%i:%s", filename, line_number, line);
      else
        printf("%i:%s", line_number, line);
    }
    line_number++;
  }
  free(line);
}

void GrepFlagV(FILE *file, char const *filename, regex_t *preg, int n) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  while (getline(&line, &len, file) > 0) {
    if (regexec(preg, line, 1, &match, 0)) {
      if (n > 1)
        printf("%s:%s", filename, line);
      else
        printf("%s", line);
    }
  }
  free(line);
}

void GrepFlagH(FILE *file, regex_t *preg) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  while (getline(&line, &len, file) > 0) {
    if (!regexec(preg, line, 1, &match, 0)) {
      printf("%s", line);
    }
  }
  free(line);
}

void GrepFileDefault(FILE *file, char const *filename, regex_t *preg, int n) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  while (getline(&line, &len, file) > 0) {
    if (!regexec(preg, line, 1, &match, 0)) {
      if (n > 1)
        printf("%s:%s", filename, line);
      else
        printf("%s", line);
    }
  }
  free(line);
}

void GrepFlagO(FILE *file, char const *filename, regex_t *preg, int n) {
  char *line = 0;
  size_t len = 0;
  regmatch_t match;
  while (getline(&line, &len, file) > 0) {
    if (!regexec(preg, line, 1, &match, 0)) {
      if (n > 1)
        printf("%s:%.*s\n", filename, (int)(match.rm_eo - match.rm_so),
               line + match.rm_so);
      else
        printf("%.*s\n", (int)(match.rm_eo - match.rm_so), line + match.rm_so);
    }
  }
  free(line);
}
