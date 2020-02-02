namespace std {
  using size_t = @\textit{see support.types.layout}@;

  void* memcpy(void* s1, const void* s2, size_t n);
  void* memmove(void* s1, const void* s2, size_t n);
  char* strcpy(char* s1, const char* s2);
  char* strncpy(char* s1, const char* s2, size_t n);
  char* strcat(char* s1, const char* s2);
  char* strncat(char* s1, const char* s2, size_t n);
  int memcmp(const void* s1, const void* s2, size_t n);
  int strcmp(const char* s1, const char* s2);
  int strcoll(const char* s1, const char* s2);
  int strncmp(const char* s1, const char* s2, size_t n);
  size_t strxfrm(char* s1, const char* s2, size_t n);
  const void* memchr(const void* s, int c, size_t n);  // see library.c
  void* memchr(void* s, int c, size_t n)  // see library.c
  const char* strchr(const char* s, int c)  // see library.c
  char* strchr(char* s, int c)  // see library.c
  size_t strcspn(const char* s1, const char* s2);
  const char* strpbrk(const char* s1, const char* s2)  // see library.c
  char* strpbrk(char* s1, const char* s2)  // see library.c
  const char* strrchr(const char* s, int c)  // see library.c
  char* strrchr(char* s, int c)  // see library.c
  size_t strspn(const char* s1, const char* s2);
  const char* strstr(const char* s1, const char* s2)  // see library.c
  char* strstr(char* s1, const char* s2)  // see library.c
  char* strtok(char* s1, const char* s2);
  void* memset(void* s, int c, size_t n);
  char* strerror(int errnum);
  size_t strlen(const char* s);
}

#define NULL @\textit{see support.types.nullptr}@
