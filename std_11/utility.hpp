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

  // forward, forward/move:
  template <class T> T&& forward(typename remove_reference<T>::type& t) noexcept;
  template <class T> T&& forward(typename remove_reference<T>::type&& t) noexcept;
  template <class T> typename remove_reference<T>::type&& move(T&&) noexcept;
  template <class T> typename conditional<
    !is_nothrow_move_constructible<T>::value && is_copy_constructible<T>::value,
    const T&, T&&>::type move_if_noexcept(T& x) noexcept;

  // declval, declval:
  template <class T>
    typename add_rvalue_reference<T>::type declval() noexcept;  // as unevaluated operand

  // pairs, pairs:
  template <class T1, class T2> struct pair;

  // pairs.spec, pair specialized algorithms:
  template <class T1, class T2>
    bool operator==(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    bool operator< (const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    bool operator!=(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    bool operator> (const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    bool operator>=(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    bool operator<=(const pair<T1,T2>&, const pair<T1,T2>&);
  template <class T1, class T2>
    void swap(pair<T1,T2>& x, pair<T1,T2>& y) noexcept(noexcept(x.swap(y)));
  template <class T1, class T2>
    @\seebelow@ make_pair(T1&&, T2&&);

  // pair.astuple, tuple-like access to pair:
  template <class T> class tuple_size;
  template <size_t I, class T> class tuple_element;

  template <class T1, class T2> struct tuple_size<std::pair<T1, T2> >;
  template <class T1, class T2> struct tuple_element<0, std::pair<T1, T2> >;
  template <class T1, class T2> struct tuple_element<1, std::pair<T1, T2> >;

  template<size_t I, class T1, class T2>
    typename tuple_element<I, std::pair<T1, T2> >::type& get(std::pair<T1, T2>&) noexcept;
  template<size_t I, class T1, class T2>
    typename tuple_element<I, std::pair<T1, T2> >::type&& get(std::pair<T1, T2>&&) noexcept;
  template<size_t I, class T1, class T2>
    const typename tuple_element<I, std::pair<T1, T2> >::type&
      get(const std::pair<T1, T2>&) noexcept;

  // pair.piecewise, pair piecewise construction
  struct piecewise_construct_t { };
  constexpr piecewise_construct_t piecewise_construct = piecewise_construct_t();
  template <class... Types> class tuple;  // defined in <tuple>
}
