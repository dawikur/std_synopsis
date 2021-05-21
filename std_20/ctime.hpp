#define NULL @\textit{see support.types.nullptr}@
#define CLOCKS_PER_SEC @\seebelow@
#define TIME_UTC @\seebelow@

namespace std {
  using size_t = @\textit{see support.types.layout}@;
  using clock_t = @\seebelow@;
  using time_t = @\seebelow@;

  struct timespec;
  struct tm;

  clock_t clock();
  double difftime(time_t time1, time_t time0);
  time_t mktime(struct tm* timeptr);
  time_t time(time_t* timer);
  int timespec_get(timespec* ts, int base);
  char* asctime(const struct tm* timeptr);
  char* ctime(const time_t* timer);
  struct tm* gmtime(const time_t* timer);
  struct tm* localtime(const time_t* timer);
  size_t strftime(char* s, size_t maxsize, const char* format, const struct tm* timeptr);
}
