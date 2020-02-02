namespace std {
namespace chrono {

// time.duration, class template duration
template <class Rep, class Period = ratio<1> > class duration;

// time.point, class template time_point
template <class Clock, class Duration = typename Clock::duration> class time_point;

}  // namespace chrono

// time.traits.specializations common_type specializations
template <class Rep1, class Period1, class Rep2, class Period2>
  struct common_type<chrono::duration<Rep1, Period1>, chrono::duration<Rep2, Period2>>;

template <class Clock, class Duration1, class Duration2>
  struct common_type<chrono::time_point<Clock, Duration1>, chrono::time_point<Clock, Duration2>>;

namespace chrono {

// time.traits, customization traits
template <class Rep> struct treat_as_floating_point;
template <class Rep> struct duration_values;

// time.duration.nonmember, duration arithmetic
template <class Rep1, class Period1, class Rep2, class Period2>
  typename common_type<duration<Rep1, Period1>, duration<Rep2, Period2>>::type
  constexpr operator+(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);
template <class Rep1, class Period1, class Rep2, class Period2>
  typename common_type<duration<Rep1, Period1>, duration<Rep2, Period2>>::type
  constexpr operator-(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);
template <class Rep1, class Period, class Rep2>
  duration<typename common_type<Rep1, Rep2>::type, Period>
  constexpr operator*(const duration<Rep1, Period>& d, const Rep2& s);
template <class Rep1, class Rep2, class Period>
  duration<typename common_type<Rep1, Rep2>::type, Period>
  constexpr operator*(const Rep1& s, const duration<Rep2, Period>& d);
template <class Rep1, class Period, class Rep2>
  duration<typename common_type<Rep1, Rep2>::type, Period>
  constexpr operator/(const duration<Rep1, Period>& d, const Rep2& s);
template <class Rep1, class Period1, class Rep2, class Period2>
  typename common_type<Rep1, Rep2>::type
  constexpr operator/(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);
template <class Rep1, class Period, class Rep2>
  duration<typename common_type<Rep1, Rep2>::type, Period>
  constexpr operator%(const duration<Rep1, Period>& d, const Rep2& s);
template <class Rep1, class Period1, class Rep2, class Period2>
  typename common_type<duration<Rep1, Period1>, duration<Rep2, Period2>>::type
  constexpr operator%(const duration<Rep1, Period1>& lhs, const duration<Rep2, Period2>& rhs);

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

// convenience typedefs
typedef duration<@\term{signed integer type of at least 64 bits},@        nano> nanoseconds;
typedef duration<@\term{signed integer type of at least 55 bits},@       micro> microseconds;
typedef duration<@\term{signed integer type of at least 45 bits},@       milli> milliseconds;
typedef duration<@\term{signed integer type of at least 35 bits}@             > seconds;
typedef duration<@\term{signed integer type of at least 29 bits},@ ratio<  60>> minutes;
typedef duration<@\term{signed integer type of at least 23 bits},@ ratio<3600>> hours;

// time.point.nonmember, time_point arithmetic
template <class Clock, class Duration1, class Rep2, class Period2>
  time_point<Clock, typename common_type<Duration1, duration<Rep2, Period2>>::type>
  operator+(const time_point<Clock, Duration1>& lhs, const duration<Rep2, Period2>& rhs);
template <class Rep1, class Period1, class Clock, class Duration2>
  time_point<Clock, typename common_type<duration<Rep1, Period1>, Duration2>::type>
  operator+(const duration<Rep1, Period1>& lhs, const time_point<Clock, Duration2>& rhs);
template <class Clock, class Duration1, class Rep2, class Period2>
  time_point<Clock, typename common_type<Duration1, duration<Rep2, Period2>>::type>
  operator-(const time_point<Clock, Duration1>& lhs, const duration<Rep2, Period2>& rhs);
template <class Clock, class Duration1, class Duration2>
  typename common_type<Duration1, Duration2>::type
  operator-(const time_point<Clock, Duration1>& lhs, const time_point<Clock, Duration2>& rhs);

// time.point.comparisons time_point comparisons
template <class Clock, class Duration1, class Duration2>
   bool operator==(const time_point<Clock, Duration1>& lhs,
                   const time_point<Clock, Duration2>& rhs);
template <class Clock, class Duration1, class Duration2>
   bool operator!=(const time_point<Clock, Duration1>& lhs,
                   const time_point<Clock, Duration2>& rhs);
template <class Clock, class Duration1, class Duration2>
   bool operator< (const time_point<Clock, Duration1>& lhs,
                   const time_point<Clock, Duration2>& rhs);
template <class Clock, class Duration1, class Duration2>
   bool operator<=(const time_point<Clock, Duration1>& lhs,
                   const time_point<Clock, Duration2>& rhs);
template <class Clock, class Duration1, class Duration2>
   bool operator> (const time_point<Clock, Duration1>& lhs,
                   const time_point<Clock, Duration2>& rhs);
template <class Clock, class Duration1, class Duration2>
   bool operator>=(const time_point<Clock, Duration1>& lhs,
                   const time_point<Clock, Duration2>& rhs);

// time.point.cast, time_point_cast

template <class ToDuration, class Clock, class Duration>
  time_point<Clock, ToDuration> time_point_cast(const time_point<Clock, Duration>& t);

// time.clock, clocks
class system_clock;
class steady_clock;
class high_resolution_clock;

}  // namespace chrono
}  // namespace std
