namespace std {
  namespace chrono {
    // time.duration, class template duration
    template <class Rep, class Period = ratio<1>> class duration;

    // time.point, class template time_point
    template <class Clock, class Duration = typename Clock::duration> class time_point;
  }

  // time.traits.specializations, common_type specializations
  template <class Rep1, class Period1, class Rep2, class Period2>
    struct common_type<chrono::duration<Rep1, Period1>,
                       chrono::duration<Rep2, Period2>>;

  template <class Clock, class Duration1, class Duration2>
    struct common_type<chrono::time_point<Clock, Duration1>,
                       chrono::time_point<Clock, Duration2>>;

  namespace chrono {
    // time.traits, customization traits
    template <class Rep> struct treat_as_floating_point;
    template <class Rep> struct duration_values;
    template <class Rep> inline constexpr bool treat_as_floating_point_v
      = treat_as_floating_point<Rep>::value;

    // time.duration.nonmember, duration arithmetic
    template <class Rep1, class Period1, class Rep2, class Period2>
      common_type_t<duration<Rep1, Period1>, duration<Rep2, Period2>>
      constexpr operator+(const duration<Rep1, Period1>& lhs,
                          const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Rep2, class Period2>
      common_type_t<duration<Rep1, Period1>, duration<Rep2, Period2>>
      constexpr operator-(const duration<Rep1, Period1>& lhs,
                          const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period, class Rep2>
      duration<common_type_t<Rep1, Rep2>, Period>
      constexpr operator*(const duration<Rep1, Period>& d, const Rep2& s);
    template <class Rep1, class Rep2, class Period>
      duration<common_type_t<Rep1, Rep2>, Period>
      constexpr operator*(const Rep1& s, const duration<Rep2, Period>& d);
    template <class Rep1, class Period, class Rep2>
      duration<common_type_t<Rep1, Rep2>, Period>
      constexpr operator/(const duration<Rep1, Period>& d, const Rep2& s);
    template <class Rep1, class Period1, class Rep2, class Period2>
      common_type_t<Rep1, Rep2>
      constexpr operator/(const duration<Rep1, Period1>& lhs,
                          const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period, class Rep2>
      duration<common_type_t<Rep1, Rep2>, Period>
      constexpr operator%(const duration<Rep1, Period>& d, const Rep2& s);
    template <class Rep1, class Period1, class Rep2, class Period2>
      common_type_t<duration<Rep1, Period1>, duration<Rep2, Period2>>
      constexpr operator%(const duration<Rep1, Period1>& lhs,
                          const duration<Rep2, Period2>& rhs);

    // time.duration.comparisons, duration comparisons
    template <class Rep1, class Period1, class Rep2, class Period2>
      constexpr bool operator==(const duration<Rep1, Period1>& lhs,
                                const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Rep2, class Period2>
      constexpr bool operator!=(const duration<Rep1, Period1>& lhs,
                                const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Rep2, class Period2>
      constexpr bool operator< (const duration<Rep1, Period1>& lhs,
                                const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Rep2, class Period2>
      constexpr bool operator<=(const duration<Rep1, Period1>& lhs,
                                const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Rep2, class Period2>
      constexpr bool operator> (const duration<Rep1, Period1>& lhs,
                                const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Rep2, class Period2>
      constexpr bool operator>=(const duration<Rep1, Period1>& lhs,
                                const duration<Rep2, Period2>& rhs);

    // time.duration.cast, duration_cast
    template <class ToDuration, class Rep, class Period>
      constexpr ToDuration duration_cast(const duration<Rep, Period>& d);
    template <class ToDuration, class Rep, class Period>
      constexpr ToDuration floor(const duration<Rep, Period>& d);
    template <class ToDuration, class Rep, class Period>
      constexpr ToDuration ceil(const duration<Rep, Period>& d);
    template <class ToDuration, class Rep, class Period>
      constexpr ToDuration round(const duration<Rep, Period>& d);

    // convenience typedefs
    using nanoseconds  = duration<@\term{signed integer type of at least 64 bits}@, nano>;
    using microseconds = duration<@\term{signed integer type of at least 55 bits}@, micro>;
    using milliseconds = duration<@\term{signed integer type of at least 45 bits}@, milli>;
    using seconds      = duration<@\term{signed integer type of at least 35 bits}@>;
    using minutes      = duration<@\term{signed integer type of at least 29 bits}@, ratio<  60>>;
    using hours        = duration<@\term{signed integer type of at least 23 bits}@, ratio<3600>>;

    // time.point.nonmember, time_point arithmetic
    template <class Clock, class Duration1, class Rep2, class Period2>
      constexpr time_point<Clock, common_type_t<Duration1, duration<Rep2, Period2>>>
      operator+(const time_point<Clock, Duration1>& lhs,
                const duration<Rep2, Period2>& rhs);
    template <class Rep1, class Period1, class Clock, class Duration2>
      constexpr time_point<Clock, common_type_t<duration<Rep1, Period1>, Duration2>>
      operator+(const duration<Rep1, Period1>& lhs,
                const time_point<Clock, Duration2>& rhs);
    template <class Clock, class Duration1, class Rep2, class Period2>
      constexpr time_point<Clock, common_type_t<Duration1, duration<Rep2, Period2>>>
      operator-(const time_point<Clock, Duration1>& lhs,
                const duration<Rep2, Period2>& rhs);
    template <class Clock, class Duration1, class Duration2>
      constexpr common_type_t<Duration1, Duration2>
      operator-(const time_point<Clock, Duration1>& lhs,
                const time_point<Clock, Duration2>& rhs);

    // time.point.comparisons, time_point comparisons
    template <class Clock, class Duration1, class Duration2>
       constexpr bool operator==(const time_point<Clock, Duration1>& lhs,
                                 const time_point<Clock, Duration2>& rhs);
    template <class Clock, class Duration1, class Duration2>
       constexpr bool operator!=(const time_point<Clock, Duration1>& lhs,
                                 const time_point<Clock, Duration2>& rhs);
    template <class Clock, class Duration1, class Duration2>
       constexpr bool operator< (const time_point<Clock, Duration1>& lhs,
                                 const time_point<Clock, Duration2>& rhs);
    template <class Clock, class Duration1, class Duration2>
       constexpr bool operator<=(const time_point<Clock, Duration1>& lhs,
                                 const time_point<Clock, Duration2>& rhs);
    template <class Clock, class Duration1, class Duration2>
       constexpr bool operator> (const time_point<Clock, Duration1>& lhs,
                                 const time_point<Clock, Duration2>& rhs);
    template <class Clock, class Duration1, class Duration2>
       constexpr bool operator>=(const time_point<Clock, Duration1>& lhs,
                                 const time_point<Clock, Duration2>& rhs);

    // time.point.cast, time_point_cast
    template <class ToDuration, class Clock, class Duration>
      constexpr time_point<Clock, ToDuration>
      time_point_cast(const time_point<Clock, Duration>& t);
    template <class ToDuration, class Clock, class Duration>
      constexpr time_point<Clock, ToDuration>
      floor(const time_point<Clock, Duration>& tp);
    template <class ToDuration, class Clock, class Duration>
      constexpr time_point<Clock, ToDuration>
      ceil(const time_point<Clock, Duration>& tp);
    template <class ToDuration, class Clock, class Duration>
      constexpr time_point<Clock, ToDuration>
      round(const time_point<Clock, Duration>& tp);

    // time.duration.alg, specialized algorithms
    template <class Rep, class Period>
      constexpr duration<Rep, Period> abs(duration<Rep, Period> d);

    // time.clock, clocks
    class system_clock;
    class steady_clock;
    class high_resolution_clock;
  }

  inline namespace literals {
    inline namespace chrono_literals {
      // time.duration.literals, suffixes for duration literals
      constexpr chrono::hours                                operator""h(unsigned long long);
      constexpr chrono::duration<@\unspec,@ ratio<3600,1>> operator""h(long double);
      constexpr chrono::minutes                              operator""min(unsigned long long);
      constexpr chrono::duration<@\unspec,@ ratio<60,1>>   operator""min(long double);
      constexpr chrono::seconds                              operator""s(unsigned long long);
      constexpr chrono::duration<@\unspec@> @\itcorr[-1]@               operator""s(long double);
      constexpr chrono::milliseconds                         operator""ms(unsigned long long);
      constexpr chrono::duration<@\unspec,@ milli>          operator""ms(long double);
      constexpr chrono::microseconds                         operator""us(unsigned long long);
      constexpr chrono::duration<@\unspec,@ micro>         operator""us(long double);
      constexpr chrono::nanoseconds                          operator""ns(unsigned long long);
      constexpr chrono::duration<@\unspec,@ nano>          operator""ns(long double);
    }
  }

  namespace chrono {
    using namespace literals::chrono_literals;
  }
}
