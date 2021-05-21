#define FE_ALL_EXCEPT @\seebelow@
#define FE_DIVBYZERO @\seebelow@    // optional
#define FE_INEXACT @\seebelow@      // optional
#define FE_INVALID @\seebelow@      // optional
#define FE_OVERFLOW @\seebelow@     // optional
#define FE_UNDERFLOW @\seebelow@    // optional

#define FE_DOWNWARD @\seebelow@     // optional
#define FE_TONEAREST @\seebelow@    // optional
#define FE_TOWARDZERO @\seebelow@   // optional
#define FE_UPWARD @\seebelow@       // optional

#define FE_DFL_ENV @\seebelow@

namespace std {
  // types
  using fenv_t    = @\textit{object type}@;
  using fexcept_t = @\textit{integer type}@;

  // functions
  int feclearexcept(int except);
  int fegetexceptflag(fexcept_t* pflag, int except);
  int feraiseexcept(int except);
  int fesetexceptflag(const fexcept_t* pflag, int except);
  int fetestexcept(int except);

  int fegetround();
  int fesetround(int mode);

  int fegetenv(fenv_t* penv);
  int feholdexcept(fenv_t* penv);
  int fesetenv(const fenv_t* penv);
  int feupdateenv(const fenv_t* penv);
}
