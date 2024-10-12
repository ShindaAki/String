#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t n = 0;
  while (str[n] != '\0') {
    n++;
  }
  return n;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;

  for (const char *a = str1; *a; a++) {
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        res = (char *)a;
        break;
      }
    }

    if (res) {
      break;
    }
  }

  return res;
}
char *s21_strrchr(const char *str, int n) {
  char *res = s21_NULL;
  s21_size_t len = s21_strlen(str);

  for (int i = len; i >= 0; i--) {
    if (str[i] == n) {
      res = ((char *)str) + i;
      break;
    }
  }

  return res;
}
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      int found = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          found = 0;
          break;
        }
      }
      if (found) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}
// чисто для некст функции это сделал
char *s21_strchr(const char *str, int c) {
  char *result = (char *)str;
  s21_size_t i = 0;
  while (str[i] != c && i < s21_strlen(str) && c != '\0') {
    i++;
    result = (char *)str + i;
  }
  if (c == '\0') {
    result = (char *)str + s21_strlen(str);
  } else if (s21_strlen(result) == 0) {
    result = s21_NULL;
  }
  return result;
}
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0, len = 0;
  while (!s21_strchr(str2, str1[i]) && s21_strlen(str2) > 0) {
    i++;
    len++;
  }
  if (!s21_strlen(str2)) {
    len = s21_strlen(str1);
  }
  return len;
}

char *s21_strtok(char *str, const char *delim) {
  static char *final;
  register int ch;

  if (str == 0) {
    str = final;
  }
  do {
    if ((ch = *str++) == '\0') {
      return 0;
    }
  } while (s21_strchr(delim, ch));
  --str;
  final = str + s21_strcspn(str, delim);
  if (*final != 0) {
    *final++ = 0;
  }
  return str;
}
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *result = dest;

  if (n > 0) {
    while (*dest != '\0') {
      dest++;
    }
    while ((*(dest++) = *(src++)) != 0) {
      n--;
      if (n == 0) {
        *dest = '\0';
        break;
      }
    }
  }
  return result;
}
