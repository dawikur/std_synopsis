#include <cstdint>  // see cstdint.syn

namespace std {
  using imaxdiv_t = @\seebelow@;

  intmax_t imaxabs(intmax_t j);
  imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
  intmax_t strtoimax(const char* nptr, char** endptr, int base);
  uintmax_t strtoumax(const char* nptr, char** endptr, int base);
  intmax_t wcstoimax(const wchar_t* nptr, wchar_t** endptr, int base);
  uintmax_t wcstoumax(const wchar_t* nptr, wchar_t** endptr, int base);

  intmax_t abs(intmax_t);  // optional, see below
  imaxdiv_t div(intmax_t, intmax_t);  // optional, see below
}

#define PRIdN @\seebelow@
#define PRIiN @\seebelow@
#define PRIoN @\seebelow@
#define PRIuN @\seebelow@
#define PRIxN @\seebelow@
#define PRIXN @\seebelow@
#define SCNdN @\seebelow@
#define SCNiN @\seebelow@
#define SCNoN @\seebelow@
#define SCNuN @\seebelow@
#define SCNxN @\seebelow@
#define PRIdLEASTN @\seebelow@
#define PRIiLEASTN @\seebelow@
#define PRIoLEASTN @\seebelow@
#define PRIuLEASTN @\seebelow@
#define PRIxLEASTN @\seebelow@
#define PRIXLEASTN @\seebelow@
#define SCNdLEASTN @\seebelow@
#define SCNiLEASTN @\seebelow@
#define SCNoLEASTN @\seebelow@
#define SCNuLEASTN @\seebelow@
#define SCNxLEASTN @\seebelow@
#define PRIdFASTN @\seebelow@
#define PRIiFASTN @\seebelow@
#define PRIoFASTN @\seebelow@
#define PRIuFASTN @\seebelow@
#define PRIxFASTN @\seebelow@
#define PRIXFASTN @\seebelow@
#define SCNdFASTN @\seebelow@
#define SCNiFASTN @\seebelow@
#define SCNoFASTN @\seebelow@
#define SCNuFASTN @\seebelow@
#define SCNxFASTN @\seebelow@
#define PRIdMAX @\seebelow@
#define PRIiMAX @\seebelow@
#define PRIoMAX @\seebelow@
#define PRIuMAX @\seebelow@
#define PRIxMAX @\seebelow@
#define PRIXMAX @\seebelow@
#define SCNdMAX @\seebelow@
#define SCNiMAX @\seebelow@
#define SCNoMAX @\seebelow@
#define SCNuMAX @\seebelow@
#define SCNxMAX @\seebelow@
#define PRIdPTR @\seebelow@
#define PRIiPTR @\seebelow@
#define PRIoPTR @\seebelow@
#define PRIuPTR @\seebelow@
#define PRIxPTR @\seebelow@
#define PRIXPTR @\seebelow@
#define SCNdPTR @\seebelow@
#define SCNiPTR @\seebelow@
#define SCNoPTR @\seebelow@
#define SCNuPTR @\seebelow@
#define SCNxPTR @\seebelow@
