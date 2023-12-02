// all freestanding
#include <compare>              // see compare.syn
#include <initializer_list>     // see initializer.list.syn

namespace std {
  // utility.swap, swap
  template<class T>
    constexpr void swap(T& a, T& b) noexcept(@\seebelow@);
  template<class T, size_t N>
    constexpr void swap(T (&a)[N], T (&b)[N]) noexcept(is_nothrow_swappable_v<T>);

  // utility.exchange, exchange
  template<class T, class U = T>
    constexpr T exchange(T& obj, U&& new_val) noexcept(@\seebelow@);

  // forward, forward/move
  template<class T>
    constexpr T&& forward(remove_reference_t<T>& t) noexcept;
  template<class T>
    constexpr T&& forward(remove_reference_t<T>&& t) noexcept;
  template<class T, class U>
    [[nodiscard]] constexpr auto forward_like(U&& x) noexcept -> @\seebelow@;
  template<class T>
    constexpr remove_reference_t<T>&& move(T&&) noexcept;
  template<class T>
    constexpr conditional_t<
        !is_nothrow_move_constructible_v<T> && is_copy_constructible_v<T>, const T&, T&&>
      move_if_noexcept(T& x) noexcept;

  // utility.as.const, as_const
  template<class T>
    constexpr add_const_t<T>& as_const(T& t) noexcept;
  template<class T>
    void as_const(const T&&) = delete;

  // declval, declval
  template<class T>
    add_rvalue_reference_t<T> declval() noexcept;   // as unevaluated operand

  // utility.intcmp, integer comparison functions
  template<class T, class U>
    constexpr bool cmp_equal(T t, U u) noexcept;
  template<class T, class U>
    constexpr bool cmp_not_equal(T t, U u) noexcept;

  template<class T, class U>
    constexpr bool cmp_less(T t, U u) noexcept;
  template<class T, class U>
    constexpr bool cmp_greater(T t, U u) noexcept;
  template<class T, class U>
    constexpr bool cmp_less_equal(T t, U u) noexcept;
  template<class T, class U>
    constexpr bool cmp_greater_equal(T t, U u) noexcept;

  template<class R, class T>
    constexpr bool in_range(T t) noexcept;

  // utility.underlying, to_underlying
  template<class T>
    constexpr underlying_type_t<T> to_underlying(T value) noexcept;

  // utility.unreachable, unreachable
  [[noreturn]] void unreachable();

  // intseq, compile-time integer sequences%
index_sequence%
make_index_sequence%
index_sequence_for
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
  template<class T1, class T2>
    struct pair;

  template<class T1, class T2, class U1, class U2,
           template<class> class TQual, template<class> class UQual>
    requires requires { typename pair<common_reference_t<TQual<T1>, UQual<U1>>,
                                      common_reference_t<TQual<T2>, UQual<U2>>>; }
  struct basic_common_reference<pair<T1, T2>, pair<U1, U2>, TQual, UQual> {
    using type = pair<common_reference_t<TQual<T1>, UQual<U1>>,
                      common_reference_t<TQual<T2>, UQual<U2>>>;
  };

  template<class T1, class T2, class U1, class U2>
    requires requires { typename pair<common_type_t<T1, U1>, common_type_t<T2, U2>>; }
  struct common_type<pair<T1, T2>, pair<U1, U2>> {
    using type = pair<common_type_t<T1, U1>, common_type_t<T2, U2>>;
  };

  // pairs.spec, pair specialized algorithms
  template<class T1, class T2, class U1, class U2>
    constexpr bool operator==(const pair<T1, T2>&, const pair<U1, U2>&);
  template<class T1, class T2, class U1, class U2>
    constexpr common_comparison_category_t<@synth-three-way-result@<T1, U1>,
                                           @synth-three-way-result@<T2, U2>>
      operator<=>(const pair<T1, T2>&, const pair<U1, U2>&);

  template<class T1, class T2>
    constexpr void swap(pair<T1, T2>& x, pair<T1, T2>& y) noexcept(noexcept(x.swap(y)));
  template<class T1, class T2>
    constexpr void swap(const pair<T1, T2>& x, const pair<T1, T2>& y)
      noexcept(noexcept(x.swap(y)));

  template<class T1, class T2>
    constexpr @\seebelow@ make_pair(T1&&, T2&&);

  // pair.astuple, tuple-like access to pair
  template<class T> struct tuple_size;
  template<size_t I, class T> struct tuple_element;

  template<class T1, class T2> struct tuple_size<pair<T1, T2>>;
  template<size_t I, class T1, class T2> struct tuple_element<I, pair<T1, T2>>;

  template<size_t I, class T1, class T2>
    constexpr tuple_element_t<I, pair<T1, T2>>& get(pair<T1, T2>&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr tuple_element_t<I, pair<T1, T2>>&& get(pair<T1, T2>&&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr const tuple_element_t<I, pair<T1, T2>>& get(const pair<T1, T2>&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr const tuple_element_t<I, pair<T1, T2>>&& get(const pair<T1, T2>&&) noexcept;
  template<class T1, class T2>
    constexpr T1& get(pair<T1, T2>& p) noexcept;
  template<class T1, class T2>
    constexpr const T1& get(const pair<T1, T2>& p) noexcept;
  template<class T1, class T2>
    constexpr T1&& get(pair<T1, T2>&& p) noexcept;
  template<class T1, class T2>
    constexpr const T1&& get(const pair<T1, T2>&& p) noexcept;
  template<class T2, class T1>
    constexpr T2& get(pair<T1, T2>& p) noexcept;
  template<class T2, class T1>
    constexpr const T2& get(const pair<T1, T2>& p) noexcept;
  template<class T2, class T1>
    constexpr T2&& get(pair<T1, T2>&& p) noexcept;
  template<class T2, class T1>
    constexpr const T2&& get(const pair<T1, T2>&& p) noexcept;

  // pair.piecewise, pair piecewise construction
  struct piecewise_construct_t {
    explicit piecewise_construct_t() = default;
  };
  inline constexpr piecewise_construct_t piecewise_construct{};
  template<class... Types> class tuple;         // defined in tuple

  // in-place construction%
in_place_t%
in_place%
in_place_type_t%
in_place_type%
in_place_index_t%
in_place_index
  struct in_place_t {
    explicit in_place_t() = default;
  };
  inline constexpr in_place_t in_place{};

  template<class T>
    struct in_place_type_t {
      explicit in_place_type_t() = default;
    };
  template<class T> constexpr in_place_type_t<T> in_place_type{};

  template<size_t I>
    struct in_place_index_t {
      explicit in_place_index_t() = default;
    };
  template<size_t I> constexpr in_place_index_t<I> in_place_index{};
}
