#include <cstdint>  // see cstdint.syn

namespace std {
  using imaxdiv_t = @\seebelow@;

  constexpr intmax_t imaxabs(intmax_t j);
  constexpr imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
  intmax_t strtoimax(const char* nptr, char** endptr, int base);
  uintmax_t strtoumax(const char* nptr, char** endptr, int base);
  intmax_t wcstoimax(const wchar_t* nptr, wchar_t** endptr, int base);
  uintmax_t wcstoumax(const wchar_t* nptr, wchar_t** endptr, int base);

  constexpr intmax_t abs(intmax_t);             // optional, see below
  constexpr imaxdiv_t div(intmax_t, intmax_t);  // optional, see below
}

#define PRId@N@ @\seebelow@
#define PRIi@N@ @\seebelow@
#define PRIo@N@ @\seebelow@
#define PRIu@N@ @\seebelow@
#define PRIx@N@ @\seebelow@
#define PRIX@N@ @\seebelow@
#define SCNd@N@ @\seebelow@
#define SCNi@N@ @\seebelow@
#define SCNo@N@ @\seebelow@
#define SCNu@N@ @\seebelow@
#define SCNx@N@ @\seebelow@
#define PRIdLEAST@N@ @\seebelow@
#define PRIiLEAST@N@ @\seebelow@
#define PRIoLEAST@N@ @\seebelow@
#define PRIuLEAST@N@ @\seebelow@
#define PRIxLEAST@N@ @\seebelow@
#define PRIXLEAST@N@ @\seebelow@
#define SCNdLEAST@N@ @\seebelow@
#define SCNiLEAST@N@ @\seebelow@
#define SCNoLEAST@N@ @\seebelow@
#define SCNuLEAST@N@ @\seebelow@
#define SCNxLEAST@N@ @\seebelow@
#define PRIdFAST@N@ @\seebelow@
#define PRIiFAST@N@ @\seebelow@
#define PRIoFAST@N@ @\seebelow@
#define PRIuFAST@N@ @\seebelow@
#define PRIxFAST@N@ @\seebelow@
#define PRIXFAST@N@ @\seebelow@
#define SCNdFAST@N@ @\seebelow@
#define SCNiFAST@N@ @\seebelow@
#define SCNoFAST@N@ @\seebelow@
#define SCNuFAST@N@ @\seebelow@
#define SCNxFAST@N@ @\seebelow@
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
