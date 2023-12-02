namespace std {
  struct lconv;

  char* setlocale(int category, const char* locale);
  lconv* localeconv();
}

#define NULL @\textit{see support.types.nullptr}@
#define LC_ALL @\seebelow@
#define LC_COLLATE @\seebelow@
#define LC_CTYPE @\seebelow@
#define LC_MONETARY @\seebelow@
#define LC_NUMERIC @\seebelow@
#define LC_TIME @\seebelow@
