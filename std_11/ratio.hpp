namespace std {
  // ratio.ratio, class template ratio
  template <intmax_t N, intmax_t D = 1> class ratio;

  // ratio.arithmetic, ratio arithmetic
  template <class R1, class R2> using ratio_add = @\seebelow@;
  template <class R1, class R2> using ratio_subtract = @\seebelow@;
  template <class R1, class R2> using ratio_multiply = @\seebelow@;
  template <class R1, class R2> using ratio_divide = @\seebelow@;

  // ratio.comparison, ratio comparison
  template <class R1, class R2> struct ratio_equal;
  template <class R1, class R2> struct ratio_not_equal;
  template <class R1, class R2> struct ratio_less;
  template <class R1, class R2> struct ratio_less_equal;
  template <class R1, class R2> struct ratio_greater;
  template <class R1, class R2> struct ratio_greater_equal;

  // ratio.si, convenience SI typedefs
  typedef ratio<1, 1000000000000000000000000> yocto;  // \seebelow
  typedef ratio<1,    1000000000000000000000> zepto;  // \seebelow
  typedef ratio<1,       1000000000000000000> atto;
  typedef ratio<1,          1000000000000000> femto;
  typedef ratio<1,             1000000000000> pico;
  typedef ratio<1,                1000000000> nano;
  typedef ratio<1,                   1000000> micro;
  typedef ratio<1,                      1000> milli;
  typedef ratio<1,                       100> centi;
  typedef ratio<1,                        10> deci;
  typedef ratio<                       10, 1> deca;
  typedef ratio<                      100, 1> hecto;
  typedef ratio<                     1000, 1> kilo;
  typedef ratio<                  1000000, 1> mega;
  typedef ratio<               1000000000, 1> giga;
  typedef ratio<            1000000000000, 1> tera;
  typedef ratio<         1000000000000000, 1> peta;
  typedef ratio<      1000000000000000000, 1> exa;
  typedef ratio<   1000000000000000000000, 1> zetta;  // \seebelow
  typedef ratio<1000000000000000000000000, 1> yotta;  // \seebelow
}
