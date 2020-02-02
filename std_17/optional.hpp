namespace std {
  // optional.optional, class template optional
  template <class T>
    class optional;

  // optional.nullopt, no-value state indicator
  struct nullopt_t{@\seebelow@};
  inline constexpr nullopt_t nullopt(@\unspec@);

  // optional.bad.access, class bad_optional_access
  class bad_optional_access;

  // optional.relops, relational operators
  template <class T, class U>
  constexpr bool operator==(const optional<T>&, const optional<U>&);
  template <class T, class U>
  constexpr bool operator!=(const optional<T>&, const optional<U>&);
  template <class T, class U>
  constexpr bool operator<(const optional<T>&, const optional<U>&);
  template <class T, class U>
  constexpr bool operator>(const optional<T>&, const optional<U>&);
  template <class T, class U>
  constexpr bool operator<=(const optional<T>&, const optional<U>&);
  template <class T, class U>
  constexpr bool operator>=(const optional<T>&, const optional<U>&);

  // optional.nullops, comparison with nullopt
  template <class T> constexpr bool operator==(const optional<T>&, nullopt_t) noexcept;
  template <class T> constexpr bool operator==(nullopt_t, const optional<T>&) noexcept;
  template <class T> constexpr bool operator!=(const optional<T>&, nullopt_t) noexcept;
  template <class T> constexpr bool operator!=(nullopt_t, const optional<T>&) noexcept;
  template <class T> constexpr bool operator<(const optional<T>&, nullopt_t) noexcept;
  template <class T> constexpr bool operator<(nullopt_t, const optional<T>&) noexcept;
  template <class T> constexpr bool operator<=(const optional<T>&, nullopt_t) noexcept;
  template <class T> constexpr bool operator<=(nullopt_t, const optional<T>&) noexcept;
  template <class T> constexpr bool operator>(const optional<T>&, nullopt_t) noexcept;
  template <class T> constexpr bool operator>(nullopt_t, const optional<T>&) noexcept;
  template <class T> constexpr bool operator>=(const optional<T>&, nullopt_t) noexcept;
  template <class T> constexpr bool operator>=(nullopt_t, const optional<T>&) noexcept;

  // optional.comp_with_t, comparison with T
  template <class T, class U> constexpr bool operator==(const optional<T>&, const U&);
  template <class T, class U> constexpr bool operator==(const U&, const optional<T>&);
  template <class T, class U> constexpr bool operator!=(const optional<T>&, const U&);
  template <class T, class U> constexpr bool operator!=(const U&, const optional<T>&);
  template <class T, class U> constexpr bool operator<(const optional<T>&, const U&);
  template <class T, class U> constexpr bool operator<(const U&, const optional<T>&);
  template <class T, class U> constexpr bool operator<=(const optional<T>&, const U&);
  template <class T, class U> constexpr bool operator<=(const U&, const optional<T>&);
  template <class T, class U> constexpr bool operator>(const optional<T>&, const U&);
  template <class T, class U> constexpr bool operator>(const U&, const optional<T>&);
  template <class T, class U> constexpr bool operator>=(const optional<T>&, const U&);
  template <class T, class U> constexpr bool operator>=(const U&, const optional<T>&);

  // optional.specalg, specialized algorithms
  template <class T>
    void swap(optional<T>&, optional<T>&) noexcept(@\seebelow@);

  template <class T>
    constexpr optional<@\seebelow@> make_optional(T&&);
  template <class T, class... Args>
    constexpr optional<T> make_optional(Args&&... args);
  template <class T, class U, class... Args>
    constexpr optional<T> make_optional(initializer_list<U> il, Args&&... args);

  // optional.hash, hash support
  template <class T> struct hash;
  template <class T> struct hash<optional<T>>;
}
