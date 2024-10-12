#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int err = 0;
  char *array = s21_NULL;
  if (src && str && start_index <= (s21_strlen(src))) {
    array = (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    if (array == s21_NULL) {
      err = 1;
    }
    s21_size_t i = 0;
    for (; i < start_index; i++) {
      array[i] = src[i];
    }
    s21_size_t end = i;
    for (s21_size_t j = 0; j < s21_strlen(str); j++, i++) {
      array[i] = str[j];
    }
    for (; end < s21_strlen(src); end++, i++) {
      array[i] = src[end];
    }
    array[s21_strlen(array)] = '\0';
  } else {
    err = 1;
  }
  return err ? s21_NULL : (void *)array;
}
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *ans = NULL;
  char *p = (char *)str;
  for (int i = 0; i < (int)n; ++i) {
    if (*p == c) {
      ans = p;
      break;
    }
    p++;
  }

  return (void *)ans;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  int flag = 0;
  for (int i = 0; i < (int)n; ++i) {
    char *a = (char *)str1;
    char *b = (char *)str2;
    if (flag == 0 && a[i] != b[i]) {
      res = a[i] - b[i];
      flag = 1;
    }
  }
  if (flag == 0) {
    res = 0;
  }

  return res;
}
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  size_t i = 0;
  while (i < n) {
    *(char *)(dest + i) = *(char *)(src + i);
    i++;
  }
  return dest;
}


void *s21_memset(void *str, int c, s21_size_t n) {
  char *from = (char *)str;
  for (int i = 0; i < (int)n; ++i) {
    from[i] = (char)c;
  }
  return str;
}
char *s21_strcat(char *dest, const char *src) {
  int dest_len = s21_strlen(dest);
  int i = 0;

  for (; src[i]; i++) {
    dest[dest_len + i] = src[i];
  }

  dest[dest_len + i] = '\0';

  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0, flag = 1;
  while (i < n && flag) {
    if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
      result = (int)str1[i] - (int)str2[i];
      flag = 0;
    }
    i++;
  }
  return result;
}
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  int flag = 0;
  while (i < n) {
    if (src[i] == '\0') {
      flag = 1;
    }
    if (flag) {
      dest[i] = '\0';
    } else {
      dest[i] = src[i];
    }
    i++;
  }
  return dest;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t size = 0;
  int flag = 1;
  for (s21_size_t i = 0; i < s21_strlen(str1) && flag == 1; i++) {
    flag = 0;
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
    if (flag == 1) {
      size++;
    }
  }
  return size;
}

void *s21_to_lower(const char *str) {
  char *array2 = s21_NULL;
  if (str) {
    array2 = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  }
  if (array2) {
    s21_strncpy(array2, str, s21_strlen(str) + 1);
    for (s21_size_t i = 0; i < s21_strlen(array2); i++) {
      if (array2[i] >= 65 && array2[i] <= 90) {
        array2[i] += 32;
      }
    }
  }
  return (void *)array2;
}
void *s21_to_upper(const char *str) {
  char *array = s21_NULL;
  if (str) {
    array = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  }
  if (array) {
    s21_strncpy(array, str, s21_strlen(str) + 1);
    for (s21_size_t i = 0; i < s21_strlen(array); i++) {
      if (array[i] >= 97 && array[i] <= 122) {
        array[i] -= 32;
      }
    }
  }
  return (void *)array;
}

int left_side(const char *src, const char *trim_chars, int last) {
  int res = 0;
  int size = s21_strlen(trim_chars);
  for (int i = 0; i < size; i++) {
    if (src[last] == trim_chars[i]) res = 1;
  }
  return res;
}

int right_side(const char *src, const char *trim_chars, int last) {
  int res = 0;
  last--;
  int size = s21_strlen(trim_chars);
  for (int i = 0; i < size; i++) {
    if (src[last] == trim_chars[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *arr = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      arr = calloc(s21_strlen(src) + 1, sizeof(char));
      s21_size_t begin = 0, last = s21_strlen(src);
      while (left_side(src, trim_chars, begin)) {
        begin++;
      }
      if (begin != last) {
        while (right_side(src, trim_chars, last)) last--;
      } else {
        arr[0] = '\0';
      }
      for (int i = 0; begin < last; i++) {
        arr[i] = src[begin];
        begin++;
      }
    } else {
      arr = s21_trim(src, "\t\n ");
    }
  }
  return arr;
}