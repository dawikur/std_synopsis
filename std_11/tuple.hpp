namespace std {
  // tuple.tuple, class template tuple:
  template <class... Types> class tuple;

  // tuple.creation, tuple creation functions:
  const @\unspec@ ignore;

  template <class... Types>
    tuple<@VTypes@...> make_tuple(Types&&...);
  template <class... Types>
    tuple<@Types@...> forward_as_tuple(Types&&...) noexcept;

  template<class... Types>
    tuple<Types&...> tie(Types&...) noexcept;

  template <class... Tuples>
    tuple<@Ctypes@...> tuple_cat(Tuples&&...);

  // tuple.helper, tuple helper classes:
  template <class T> class tuple_size;  // undefined
  template <class T> class tuple_size<const T>;
  template <class T> class tuple_size<volatile T>;
  template <class T> class tuple_size<const volatile T>;

  template <class... Types> class tuple_size<tuple<Types...> >;

  template <size_t I, class T> class tuple_element;    // undefined
  template <size_t I, class T> class tuple_element<I, const T>;
  template <size_t I, class T> class tuple_element<I, volatile T>;
  template <size_t I, class T> class tuple_element<I, const volatile T>;

  template <size_t I, class... Types> class tuple_element<I, tuple<Types...> >;

  // tuple.elem, element access:
  template <size_t I, class... Types>
    typename tuple_element<I, tuple<Types...> >::type& get(tuple<Types...>&) noexcept;
  template <size_t I, class... types>
    typename tuple_element<I, tuple<Types...> >::type&& get(tuple<Types...>&&) noexcept;
  template <size_t I, class... types>
    typename tuple_element<I, tuple<Types...> >::type const& get(const tuple<Types...>&) noexcept;

  // tuple.rel, relational operators:
  template<class... TTypes, class... UTypes>
    bool operator==(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, class... UTypes>
    bool operator<(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, class... UTypes>
    bool operator!=(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, class... UTypes>
    bool operator>(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, class... UTypes>
    bool operator<=(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, class... UTypes>
    bool operator>=(const tuple<TTypes...>&, const tuple<UTypes...>&);

  // tuple.traits, allocator-related traits
  template <class... Types, class Alloc>
    struct uses_allocator<tuple<Types...>, Alloc>;

  // tuple.special, specialized algorithms:
  template <class... Types>
    void swap(tuple<Types...>& x, tuple<Types...>& y) noexcept(@\seebelow@);
}
