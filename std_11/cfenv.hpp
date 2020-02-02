namespace std {
  // types
  typedef @\textit{object type}@  fenv_t;
  typedef @\textit{integer type}@ fexcept_t;

  // functions
  int feclearexcept(int except);
  int fegetexceptflag(fexcept_t *pflag, int except);
  int feraiseexcept(int except);
  int fesetexceptflag(const fexcept_t *pflag, int except);
  int fetestexcept(int except);

  int fegetround(void);
  int fesetround(int mode);

  int fegetenv(fenv_t *penv);
  int feholdexcept(fenv_t *penv);
  int fesetenv(const fenv_t *penv);
  int feupdateenv(const fenv_t *penv);
}
