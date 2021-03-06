#include <initializer_list>

namespace std {
  // operators, operators:
  namespace rel_ops {
    template<class T> bool operator!=(const T&, const T&);
    template<class T> bool operator> (const T&, const T&);
    template<class T> bool operator<=(const T&, const T&);
    template<class T> bool operator>=(const T&, const T&);
  }

  // utility.swap, swap:
  template<class T> void swap(T& a, T& b) noexcept(@\seebelow@);
  template <class T, size_t N> void swap(T (&a)[N], T (&b)[N]) noexcept(noexcept(swap(*a, *b)));

  // utility.exchange, exchange:
  template <class T, class U=T> T exchange(T& obj, U&& new_val);

  // forward, forward/move:
  template <class T> 
    constexpr T&& forward(remove_reference_t<T>& t) noexcept;
  template <class T>
    constexpr T&& forward(remove_reference_t<T>&& t) noexcept;
  template <class T>
    constexpr remove_reference_t<T>&& move(T&&) noexcept;
  template <class T>
    constexpr conditional_t<
    !is_nothrow_move_constructible<T>::value && is_copy_constructible<T>::value,
    const T&, T&&> move_if_noexcept(T& x) noexcept;

  // declval, declval:
  template <class T>
    add_rvalue_reference_t<T> declval() noexcept;  // as unevaluated operand

  // pairs, pairs:
  template <class T1, class T2> struct pair;

  // pairs.spec, pair specialized algorithms:
  template <class T1, class T2>
    constexpr bool operator==(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    constexpr bool operator< (const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    constexpr bool operator!=(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    constexpr bool operator> (const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    constexpr bool operator>=(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    constexpr bool operator<=(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    void swap(pair<T1,T2>& x, pair<T1,T2>& y) noexcept(noexcept(x.swap(y)));
  template <class T1, class T2>
    constexpr @\seebelow@ make_pair(T1&&, T2&&);

  // pair.astuple, tuple-like access to pair:
  template <class T> class tuple_size;
  template <size_t I, class T> class tuple_element;

  template <class T1, class T2> struct tuple_size<pair<T1, T2> >;
  template <class T1, class T2> struct tuple_element<0, pair<T1, T2> >;
  template <class T1, class T2> struct tuple_element<1, pair<T1, T2> >;

  template<size_t I, class T1, class T2>
    constexpr tuple_element_t<I, pair<T1, T2>>&
      get(pair<T1, T2>&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr tuple_element_t<I, pair<T1, T2>>&&
      get(pair<T1, T2>&&) noexcept;
  template<size_t I, class T1, class T2>
    constexpr const tuple_element_t<I, pair<T1, T2>>&
      get(const pair<T1, T2>&) noexcept;
  template <class T, class U>
    constexpr T& get(pair<T, U>& p) noexcept;
  template <class T, class U>
    constexpr const T& get(const pair<T, U>& p) noexcept;
  template <class T, class U>
    constexpr T&& get(pair<T, U>&& p) noexcept;
  template <class T, class U>
    constexpr T& get(pair<U, T>& p) noexcept;
  template <class T, class U>
    constexpr const T& get(const pair<U, T>& p) noexcept;
  template <class T, class U>
    constexpr T&& get(pair<U, T>&& p) noexcept;

  // pair.piecewise, pair piecewise construction
  struct piecewise_construct_t { };
  constexpr piecewise_construct_t piecewise_construct{};
  template <class... Types> class tuple;  // defined in <tuple>
@
\idxcode{index_sequence}%
\idxcode{make_index_sequence}%
\idxcode{index_sequence_for}%
@
  // intseq, Compile-time integer sequences
  template<class T, T...> struct integer_sequence;
  template<size_t... I>
    using index_sequence = integer_sequence<size_t, I...>;

  template<class T, T N>
    using make_integer_sequence = integer_sequence<T, @@>;
  template<size_t N>
    using make_index_sequence = make_integer_sequence<size_t, N>;

  template<class... T>
    using index_sequence_for = make_index_sequence<sizeof...(T)>;
}
