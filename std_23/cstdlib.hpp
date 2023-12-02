namespace std {
  using size_t = @\seebelow@;                                             // freestanding
  using div_t = @\seebelow@;
  using ldiv_t = @\seebelow@;
  using lldiv_t = @\seebelow@;
}

#define NULL @\seebelow@                                                  // freestanding
#define EXIT_FAILURE @\seebelow@
#define EXIT_SUCCESS @\seebelow@
#define RAND_MAX @\seebelow@
#define MB_CUR_MAX @\seebelow@

namespace std {
  // Exposition-only function type aliases
  extern "C" using @c-atexit-handler@ = void();                           // \expos
  extern "C++" using @atexit-handler@ = void();                           // \expos
  extern "C" using @c-compare-pred@ = int(const void*, const void*);      // \expos
  extern "C++" using @compare-pred@ = int(const void*, const void*);      // \expos

  // support.start.term, start and termination
  [[noreturn]] void abort() noexcept;                                   // freestanding
  int atexit(@c-atexit-handler@* func) noexcept;                          // freestanding
  int atexit(@atexit-handler@* func) noexcept;                            // freestanding
  int at_quick_exit(@c-atexit-handler@* func) noexcept;                   // freestanding
  int at_quick_exit(@atexit-handler@* func) noexcept;                     // freestanding
  [[noreturn]] void exit(int status);                                   // freestanding
  [[noreturn]] void _Exit(int status) noexcept;                         // freestanding
  [[noreturn]] void quick_exit(int status) noexcept;                    // freestanding

  char* getenv(const char* name);
  int system(const char* string);

  // c.malloc, C library memory allocation
  void* aligned_alloc(size_t alignment, size_t size);
  void* calloc(size_t nmemb, size_t size);
  void free(void* ptr);
  void* malloc(size_t size);
  void* realloc(void* ptr, size_t size);

  double atof(const char* nptr);
  int atoi(const char* nptr);
  long int atol(const char* nptr);
  long long int atoll(const char* nptr);
  double strtod(const char* nptr, char** endptr);
  float strtof(const char* nptr, char** endptr);
  long double strtold(const char* nptr, char** endptr);
  long int strtol(const char* nptr, char** endptr, int base);
  long long int strtoll(const char* nptr, char** endptr, int base);
  unsigned long int strtoul(const char* nptr, char** endptr, int base);
  unsigned long long int strtoull(const char* nptr, char** endptr, int base);

  // c.mb.wcs, multibyte / wide string and character conversion functions
  int mblen(const char* s, size_t n);
  int mbtowc(wchar_t* pwc, const char* s, size_t n);
  int wctomb(char* s, wchar_t wchar);
  size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n);
  size_t wcstombs(char* s, const wchar_t* pwcs, size_t n);

  // alg.c.library, C standard library algorithms
  void* bsearch(const void* key, const void* base, size_t nmemb, size_t size,
                @c-compare-pred@*@\itcorr[-1]@ compar);
  void* bsearch(const void* key, const void* base, size_t nmemb, size_t size,
                @compare-pred@*@\itcorr[-1]@ compar);
  void qsort(void* base, size_t nmemb, size_t size, @c-compare-pred@*@\itcorr[-1]@ compar);
  void qsort(void* base, size_t nmemb, size_t size, @compare-pred@*@\itcorr[-1]@ compar);

  // c.math.rand, low-quality random number generation
  int rand();
  void srand(unsigned int seed);

  // c.math.abs, absolute values
  constexpr int abs(int j);
  constexpr long int abs(long int j);
  constexpr long long int abs(long long int j);
  constexpr @floating-point-type@ abs(@floating-point-type@ j);

  constexpr long int labs(long int j);
  constexpr long long int llabs(long long int j);

  constexpr div_t div(int numer, int denom);
  constexpr ldiv_t div(long int numer, long int denom);                 // see library.c
  constexpr lldiv_t div(long long int numer, long long int denom);      // see library.c
  constexpr ldiv_t ldiv(long int numer, long int denom);
  constexpr lldiv_t lldiv(long long int numer, long long int denom);
}
