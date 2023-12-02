namespace std {
  using float_t = @\seebelow@;
  using double_t = @\seebelow@;
}

#define HUGE_VAL @\seebelow@
#define HUGE_VALF @\seebelow@
#define HUGE_VALL @\seebelow@
#define INFINITY @\seebelow@
#define NAN @\seebelow@
#define FP_INFINITE @\seebelow@
#define FP_NAN @\seebelow@
#define FP_NORMAL @\seebelow@
#define FP_SUBNORMAL @\seebelow@
#define FP_ZERO @\seebelow@
#define FP_FAST_FMA @\seebelow@
#define FP_FAST_FMAF @\seebelow@
#define FP_FAST_FMAL @\seebelow@
#define FP_ILOGB0 @\seebelow@
#define FP_ILOGBNAN @\seebelow@
#define MATH_ERRNO @\seebelow@
#define MATH_ERREXCEPT @\seebelow@

#define math_errhandling @\seebelow@

namespace std {
  @floating-point-type@ acos(@floating-point-type@ x);
  float acosf(float x);
  long double acosl(long double x);

  @floating-point-type@ asin(@floating-point-type@ x);
  float asinf(float x);
  long double asinl(long double x);

  @floating-point-type@ atan(@floating-point-type@ x);
  float atanf(float x);
  long double atanl(long double x);

  @floating-point-type@ atan2(@floating-point-type@ y, @floating-point-type@ x);
  float atan2f(float y, float x);
  long double atan2l(long double y, long double x);

  @floating-point-type@ cos(@floating-point-type@ x);
  float cosf(float x);
  long double cosl(long double x);

  @floating-point-type@ sin(@floating-point-type@ x);
  float sinf(float x);
  long double sinl(long double x);

  @floating-point-type@ tan(@floating-point-type@ x);
  float tanf(float x);
  long double tanl(long double x);

  @floating-point-type@ acosh(@floating-point-type@ x);
  float acoshf(float x);
  long double acoshl(long double x);

  @floating-point-type@ asinh(@floating-point-type@ x);
  float asinhf(float x);
  long double asinhl(long double x);

  @floating-point-type@ atanh(@floating-point-type@ x);
  float atanhf(float x);
  long double atanhl(long double x);

  @floating-point-type@ cosh(@floating-point-type@ x);
  float coshf(float x);
  long double coshl(long double x);

  @floating-point-type@ sinh(@floating-point-type@ x);
  float sinhf(float x);
  long double sinhl(long double x);

  @floating-point-type@ tanh(@floating-point-type@ x);
  float tanhf(float x);
  long double tanhl(long double x);

  @floating-point-type@ exp(@floating-point-type@ x);
  float expf(float x);
  long double expl(long double x);

  @floating-point-type@ exp2(@floating-point-type@ x);
  float exp2f(float x);
  long double exp2l(long double x);

  @floating-point-type@ expm1(@floating-point-type@ x);
  float expm1f(float x);
  long double expm1l(long double x);

  constexpr @floating-point-type@ frexp(@floating-point-type@ value, int* exp);
  constexpr float frexpf(float value, int* exp);
  constexpr long double frexpl(long double value, int* exp);

  constexpr int ilogb(@floating-point-type@ x);
  constexpr int ilogbf(float x);
  constexpr int ilogbl(long double x);

  constexpr @floating-point-type@ ldexp(@floating-point-type@ x, int exp);
  constexpr float ldexpf(float x, int exp);
  constexpr long double ldexpl(long double x, int exp);

  @floating-point-type@ log(@floating-point-type@ x);
  float logf(float x);
  long double logl(long double x);

  @floating-point-type@ log10(@floating-point-type@ x);
  float log10f(float x);
  long double log10l(long double x);

  @floating-point-type@ log1p(@floating-point-type@ x);
  float log1pf(float x);
  long double log1pl(long double x);

  @floating-point-type@ log2(@floating-point-type@ x);
  float log2f(float x);
  long double log2l(long double x);

  constexpr @floating-point-type@ logb(@floating-point-type@ x);
  constexpr float logbf(float x);
  constexpr long double logbl(long double x);

  constexpr @floating-point-type@ modf(@floating-point-type@ value, @floating-point-type@* iptr);
  constexpr float modff(float value, float* iptr);
  constexpr long double modfl(long double value, long double* iptr);

  constexpr @floating-point-type@ scalbn(@floating-point-type@ x, int n);
  constexpr float scalbnf(float x, int n);
  constexpr long double scalbnl(long double x, int n);

  constexpr @floating-point-type@ scalbln(@floating-point-type@ x, long int n);
  constexpr float scalblnf(float x, long int n);
  constexpr long double scalblnl(long double x, long int n);

  @floating-point-type@ cbrt(@floating-point-type@ x);
  float cbrtf(float x);
  long double cbrtl(long double x);

  // c.math.abs, absolute values
  constexpr int abs(int j);
  constexpr long int abs(long int j);
  constexpr long long int abs(long long int j);
  constexpr @floating-point-type@ abs(@floating-point-type@ j);

  constexpr @floating-point-type@ fabs(@floating-point-type@ x);
  constexpr float fabsf(float x);
  constexpr long double fabsl(long double x);

  @floating-point-type@ hypot(@floating-point-type@ x, @floating-point-type@ y);
  float hypotf(float x, float y);
  long double hypotl(long double x, long double y);

  // c.math.hypot3, three-dimensional hypotenuse
  @floating-point-type@ hypot(@floating-point-type@ x, @floating-point-type@ y,
                            @floating-point-type@ z);

  @floating-point-type@ pow(@floating-point-type@ x, @floating-point-type@ y);
  float powf(float x, float y);
  long double powl(long double x, long double y);

  @floating-point-type@ sqrt(@floating-point-type@ x);
  float sqrtf(float x);
  long double sqrtl(long double x);

  @floating-point-type@ erf(@floating-point-type@ x);
  float erff(float x);
  long double erfl(long double x);

  @floating-point-type@ erfc(@floating-point-type@ x);
  float erfcf(float x);
  long double erfcl(long double x);

  @floating-point-type@ lgamma(@floating-point-type@ x);
  float lgammaf(float x);
  long double lgammal(long double x);

  @floating-point-type@ tgamma(@floating-point-type@ x);
  float tgammaf(float x);
  long double tgammal(long double x);

  constexpr @floating-point-type@ ceil(@floating-point-type@ x);
  constexpr float ceilf(float x);
  constexpr long double ceill(long double x);

  constexpr @floating-point-type@ floor(@floating-point-type@ x);
  constexpr float floorf(float x);
  constexpr long double floorl(long double x);

  @floating-point-type@ nearbyint(@floating-point-type@ x);
  float nearbyintf(float x);
  long double nearbyintl(long double x);

  @floating-point-type@ rint(@floating-point-type@ x);
  float rintf(float x);
  long double rintl(long double x);

  long int lrint(@floating-point-type@ x);
  long int lrintf(float x);
  long int lrintl(long double x);

  long long int llrint(@floating-point-type@ x);
  long long int llrintf(float x);
  long long int llrintl(long double x);

  constexpr @floating-point-type@ round(@floating-point-type@ x);
  constexpr float roundf(float x);
  constexpr long double roundl(long double x);

  constexpr long int lround(@floating-point-type@ x);
  constexpr long int lroundf(float x);
  constexpr long int lroundl(long double x);

  constexpr long long int llround(@floating-point-type@ x);
  constexpr long long int llroundf(float x);
  constexpr long long int llroundl(long double x);

  constexpr @floating-point-type@ trunc(@floating-point-type@ x);
  constexpr float truncf(float x);
  constexpr long double truncl(long double x);

  constexpr @floating-point-type@ fmod(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float fmodf(float x, float y);
  constexpr long double fmodl(long double x, long double y);

  constexpr @floating-point-type@ remainder(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float remainderf(float x, float y);
  constexpr long double remainderl(long double x, long double y);

  constexpr @floating-point-type@ remquo(@floating-point-type@ x, @floating-point-type@ y, int* quo);
  constexpr float remquof(float x, float y, int* quo);
  constexpr long double remquol(long double x, long double y, int* quo);

  constexpr @floating-point-type@ copysign(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float copysignf(float x, float y);
  constexpr long double copysignl(long double x, long double y);

  double nan(const char* tagp);
  float nanf(const char* tagp);
  long double nanl(const char* tagp);

  constexpr @floating-point-type@ nextafter(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float nextafterf(float x, float y);
  constexpr long double nextafterl(long double x, long double y);

  constexpr @floating-point-type@ nexttoward(@floating-point-type@ x, long double y);
  constexpr float nexttowardf(float x, long double y);
  constexpr long double nexttowardl(long double x, long double y);

  constexpr @floating-point-type@ fdim(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float fdimf(float x, float y);
  constexpr long double fdiml(long double x, long double y);

  constexpr @floating-point-type@ fmax(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float fmaxf(float x, float y);
  constexpr long double fmaxl(long double x, long double y);

  constexpr @floating-point-type@ fmin(@floating-point-type@ x, @floating-point-type@ y);
  constexpr float fminf(float x, float y);
  constexpr long double fminl(long double x, long double y);

  constexpr @floating-point-type@ fma(@floating-point-type@ x, @floating-point-type@ y,
                                  @floating-point-type@ z);
  constexpr float fmaf(float x, float y, float z);
  constexpr long double fmal(long double x, long double y, long double z);

  // c.math.lerp, linear interpolation
  constexpr @floating-point-type@ lerp(@floating-point-type@ a, @floating-point-type@ b,
                                    @floating-point-type@ t) noexcept;

  // c.math.fpclass, classification / comparison functions
  constexpr int fpclassify(@floating-point-type@ x);
  constexpr bool isfinite(@floating-point-type@ x);
  constexpr bool isinf(@floating-point-type@ x);
  constexpr bool isnan(@floating-point-type@ x);
  constexpr bool isnormal(@floating-point-type@ x);
  constexpr bool signbit(@floating-point-type@ x);
  constexpr bool isgreater(@floating-point-type@ x, @floating-point-type@ y);
  constexpr bool isgreaterequal(@floating-point-type@ x, @floating-point-type@ y);
  constexpr bool isless(@floating-point-type@ x, @floating-point-type@ y);
  constexpr bool islessequal(@floating-point-type@ x, @floating-point-type@ y);
  constexpr bool islessgreater(@floating-point-type@ x, @floating-point-type@ y);
  constexpr bool isunordered(@floating-point-type@ x, @floating-point-type@ y);

  // sf.cmath, mathematical special functions

  // sf.cmath.assoc.laguerre, associated Laguerre polynomials
  @floating-point-type@ assoc_laguerre(unsigned n, unsigned m, @floating-point-type@ x);
  float        assoc_laguerref(unsigned n, unsigned m, float x);
  long double  assoc_laguerrel(unsigned n, unsigned m, long double x);

  // sf.cmath.assoc.legendre, associated Legendre functions
  @floating-point-type@ assoc_legendre(unsigned l, unsigned m, @floating-point-type@ x);
  float        assoc_legendref(unsigned l, unsigned m, float x);
  long double  assoc_legendrel(unsigned l, unsigned m, long double x);

  // sf.cmath.beta, beta function
  @floating-point-type@ beta(@floating-point-type@ x, @floating-point-type@ y);
  float        betaf(float x, float y);
  long double  betal(long double x, long double y);

  // sf.cmath.comp.ellint.1, complete elliptic integral of the first kind
  @floating-point-type@ comp_ellint_1(@floating-point-type@ k);
  float        comp_ellint_1f(float k);
  long double  comp_ellint_1l(long double k);

  // sf.cmath.comp.ellint.2, complete elliptic integral of the second kind
  @floating-point-type@ comp_ellint_2(@floating-point-type@ k);
  float        comp_ellint_2f(float k);
  long double  comp_ellint_2l(long double k);

  // sf.cmath.comp.ellint.3, complete elliptic integral of the third kind
  @floating-point-type@ comp_ellint_3(@floating-point-type@ k, @floating-point-type@ nu);
  float        comp_ellint_3f(float k, float nu);
  long double  comp_ellint_3l(long double k, long double nu);

  // sf.cmath.cyl.bessel.i, regular modified cylindrical Bessel functions
  @floating-point-type@ cyl_bessel_i(@floating-point-type@ nu, @floating-point-type@ x);
  float        cyl_bessel_if(float nu, float x);
  long double  cyl_bessel_il(long double nu, long double x);

  // sf.cmath.cyl.bessel.j, cylindrical Bessel functions of the first kind
  @floating-point-type@ cyl_bessel_j(@floating-point-type@ nu, @floating-point-type@ x);
  float        cyl_bessel_jf(float nu, float x);
  long double  cyl_bessel_jl(long double nu, long double x);

  // sf.cmath.cyl.bessel.k, irregular modified cylindrical Bessel functions
  @floating-point-type@ cyl_bessel_k(@floating-point-type@ nu, @floating-point-type@ x);
  float        cyl_bessel_kf(float nu, float x);
  long double  cyl_bessel_kl(long double nu, long double x);

  // sf.cmath.cyl.neumann, cylindrical Neumann functions
  // cylindrical Bessel functions of the second kind
  @floating-point-type@       cyl_neumann(@floating-point-type@ nu, @floating-point-type@ x);
  float        cyl_neumannf(float nu, float x);
  long double  cyl_neumannl(long double nu, long double x);

  // sf.cmath.ellint.1, incomplete elliptic integral of the first kind
  @floating-point-type@ ellint_1(@floating-point-type@ k, @floating-point-type@ phi);
  float        ellint_1f(float k, float phi);
  long double  ellint_1l(long double k, long double phi);

  // sf.cmath.ellint.2, incomplete elliptic integral of the second kind
  @floating-point-type@ ellint_2(@floating-point-type@ k, @floating-point-type@ phi);
  float        ellint_2f(float k, float phi);
  long double  ellint_2l(long double k, long double phi);

  // sf.cmath.ellint.3, incomplete elliptic integral of the third kind
  @floating-point-type@ ellint_3(@floating-point-type@ k, @floating-point-type@ nu,
                                 @floating-point-type@ phi);
  float        ellint_3f(float k, float nu, float phi);
  long double  ellint_3l(long double k, long double nu, long double phi);

  // sf.cmath.expint, exponential integral
  @floating-point-type@ expint(@floating-point-type@ x);
  float        expintf(float x);
  long double  expintl(long double x);

  // sf.cmath.hermite, Hermite polynomials
  @floating-point-type@ hermite(unsigned n, @floating-point-type@ x);
  float        hermitef(unsigned n, float x);
  long double  hermitel(unsigned n, long double x);

  // sf.cmath.laguerre, Laguerre polynomials
  @floating-point-type@ laguerre(unsigned n, @floating-point-type@ x);
  float        laguerref(unsigned n, float x);
  long double  laguerrel(unsigned n, long double x);

  // sf.cmath.legendre, Legendre polynomials
  @floating-point-type@ legendre(unsigned l, @floating-point-type@ x);
  float        legendref(unsigned l, float x);
  long double  legendrel(unsigned l, long double x);

  // sf.cmath.riemann.zeta, Riemann zeta function
  @floating-point-type@ riemann_zeta(@floating-point-type@ x);
  float        riemann_zetaf(float x);
  long double  riemann_zetal(long double x);

  // sf.cmath.sph.bessel, spherical Bessel functions of the first kind
  @floating-point-type@ sph_bessel(unsigned n, @floating-point-type@ x);
  float        sph_besself(unsigned n, float x);
  long double  sph_bessell(unsigned n, long double x);

  // sf.cmath.sph.legendre, spherical associated Legendre functions
  @floating-point-type@ sph_legendre(unsigned l, unsigned m, @floating-point-type@ theta);
  float        sph_legendref(unsigned l, unsigned m, float theta);
  long double  sph_legendrel(unsigned l, unsigned m, long double theta);

  // sf.cmath.sph.neumann, spherical Neumann functions;
  // spherical Bessel functions of the second kind
  @floating-point-type@ sph_neumann(unsigned n, @floating-point-type@ x);
  float        sph_neumannf(unsigned n, float x);
  long double  sph_neumannl(unsigned n, long double x);
}
