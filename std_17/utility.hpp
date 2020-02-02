#include <initializer_list>     // see initializer_list.syn

namespace std {
  // operators, operators
  namespace rel_ops {
    template<class T> bool operator!=(const T&, const T&);
    template<class T> bool operator> (const T&, const T&);
    template<class T> bool operator<=(const T&, const T&);
    template<class T> bool operator>=(const T&, const T&);
  }

  // utility.swap, swap
  template <class T>
    void swap(T& a, T& b) noexcept(@\seebelow@);
  template <class T, size_t N>
    void swap(T (&a)[N], T (&b)[N]) noexcept(is_nothrow_swappable_v<T>);

  // utility.exchange, exchange
  template <class T, class U = T>
    T exchange(T& obj, U&& new_val);

  // forward, forward/move
  template <class T>
    constexpr T&& forward(remove_reference_t<T>& t) noexcept;
  template <class T>
    constexpr T&& forward(remove_reference_t<T>&& t) noexcept;
  template <class T>
    constexpr remove_reference_t<T>&& move(T&&) noexcept;
  template <class T>
    constexpr conditional_t<
        !is_nothrow_move_constructible_v<T> && is_copy_constructible_v<T>, const T&, T&&>
      move_if_noexcept(T& x) noexcept;

  // utility.as_const, as_const
  template <class T>
    constexpr add_const_t<T>& as_const(T& t) noexcept;
  template <class T>
    void as_const(const T&&) = delete;

  // declval, declval
  template <class T>
    add_rvalue_reference_t<T> declval() noexcept;  // as unevaluated operand
@%
\idxcode{index_sequence}%
\idxcode{make_index_sequence}%
\idxcode{index_sequence_for}%
@
  // intseq, Compile-time integer sequences
  template<class T, T...>
    struct integer_sequence;
  template<size_t... I>
    using index_sequence = integer_sequence<size_t, I...>;

  template<class T, T N>
    using make_integer_sequence = integer_sequence<T, @@>;
  template<size_t N>
    using make_index_sequence = make_integer_sequence<size_t, N>;

  template<class... T>
    using index_sequence_for = make_index_sequence<sizeof...(T)>;

  // pairs, class template pair
  template <class T1, class T2>
    struct pair;

  // pairs.spec, pair specialized algorithms
  template <class T1, class T2>
    constexpr bool operator==(const pair<T1, T2>&, const pair<T1, T2>&);
  template <class T1, class T2>
    constexpr bool operator< (const pair<T1, T2>&, const pair<T1, T2>&);
  template <class T1, class T2>
    constexpr bool operator!=(const pair<T1, T2>&, const pair<T1, T2>&);
  template <class T1, class T2>
    constexpr bool operator> (const pair<T1, T2>&, const pair<T1, T2>&);
  template <class T1, class T2>
    constexpr bool operator>=(const pair<T1, T2>&, const pair<T1, T2>&);
  template <class T1, class T2>
    constexpr bool operator<=(const pair<T1, T2>&, const pair<T1, T2>&);

  template <class T1, class T2>
    void swap(pair<T1, T2>& x, pair<T1, T2>& y) noexcept(noexcept(x.swap(y)));

  template <class T1, class T2>
    constexpr @\seebelow@ make_pair(T1&&, T2&&);

  // pair.astuple, tuple-like access to pair
  template <class T> class tuple_size;
  template <size_t I, class T> class tuple_element;

  template <class T1, class T2> struct tuple_size<pair<T1, T2>>;
  template <class T1, class T2> struct tuple_element<0, pair<T1, T2>>;
  template <class T1, class T2> struct tuple_element<1, pair<T1, T2>>;

  template<size_t I, class T1, class T2>
    constexpr tuple_element_t<I, pair<T1, T2>>& get(pair<T1, T2>&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr tuple_element_t<I, pair<T1, T2>>&& get(pair<T1, T2>&&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr const tuple_element_t<I, pair<T1, T2>>& get(const pair<T1, T2>&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr const tuple_element_t<I, pair<T1, T2>>&& get(const pair<T1, T2>&&) noexcept;
  template <class T1, class T2>
    constexpr T1& get(pair<T1, T2>& p) noexcept;
  template <class T1, class T2>
    constexpr const T1& get(const pair<T1, T2>& p) noexcept;
  template <class T1, class T2>
    constexpr T1&& get(pair<T1, T2>&& p) noexcept;
  template <class T1, class T2>
    constexpr const T1&& get(const pair<T1, T2>&& p) noexcept;
  template <class T2, class T1>
    constexpr T2& get(pair<T1, T2>& p) noexcept;
  template <class T2, class T1>
    constexpr const T2& get(const pair<T1, T2>& p) noexcept;
  template <class T2, class T1>
    constexpr T2&& get(pair<T1, T2>&& p) noexcept;
  template <class T2, class T1>
    constexpr const T2&& get(const pair<T1, T2>&& p) noexcept;

  // pair.piecewise, pair piecewise construction
  struct piecewise_construct_t {
    explicit piecewise_construct_t() = default;
  };
  inline constexpr piecewise_construct_t piecewise_construct{};
  template <class... Types> class tuple;        // defined in <tuple> (tuple.syn)

  // in-place construction
  struct in_place_t {
    explicit in_place_t() = default;
  };
  inline constexpr in_place_t in_place{};
  template <class T>
    struct in_place_type_t {
      explicit in_place_type_t() = default;
    };
  template <class T> inline constexpr in_place_type_t<T> in_place_type{};
  template <size_t I>
    struct in_place_index_t {
      explicit in_place_index_t() = default;
    };
  template <size_t I> inline constexpr in_place_index_t<I> in_place_index{};
@
\idxcode{chars_format}%
scientific}{chars_format%
fixed}{chars_format%
hex}{chars_format%
general}{chars_format%
@
  // floating-point format for primitive numerical conversion
  enum class chars_format {
    scientific = @\unspec@,
    fixed = @\unspec@,
    hex = @\unspec@,
    general = fixed | scientific
  };
@
\idxcode{to_chars_result}%
ptr}{to_chars_result%
ec}{to_chars_result
@
  // utility.to.chars, primitive numerical output conversion
  struct to_chars_result {
    char* ptr;
    error_code ec;
  };

  to_chars_result to_chars(char* first, char* last, @\seebelow@ value, int base = 10);

  to_chars_result to_chars(char* first, char* last, float value);
  to_chars_result to_chars(char* first, char* last, double value);
  to_chars_result to_chars(char* first, char* last, long double value);

  to_chars_result to_chars(char* first, char* last, float value,
                           chars_format fmt);
  to_chars_result to_chars(char* first, char* last, double value,
                           chars_format fmt);
  to_chars_result to_chars(char* first, char* last, long double value,
                           chars_format fmt);

  to_chars_result to_chars(char* first, char* last, float value,
                           chars_format fmt, int precision);
  to_chars_result to_chars(char* first, char* last, double value,
                           chars_format fmt, int precision);
  to_chars_result to_chars(char* first, char* last, long double value,
                           chars_format fmt, int precision);
@
\idxcode{from_chars_result}%
ptr}{from_chars_result%
ec}{from_chars_result
@
  // utility.from.chars, primitive numerical input conversion
  struct from_chars_result {
    const char* ptr;
    error_code ec;
  };

  from_chars_result from_chars(const char* first, const char* last,
                               @\seebelow@& value, int base = 10);

  from_chars_result from_chars(const char* first, const char* last, float& value,
                               chars_format fmt = chars_format::general);
  from_chars_result from_chars(const char* first, const char* last, double& value,
                               chars_format fmt = chars_format::general);
  from_chars_result from_chars(const char* first, const char* last, long double& value,
                               chars_format fmt = chars_format::general);
}
