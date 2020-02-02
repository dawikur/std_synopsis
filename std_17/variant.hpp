namespace std {
  // variant.variant, class template variant
  template <class... Types>
    class variant;

  // variant.helper, variant helper classes
  template <class T> struct variant_size;                   // not defined
  template <class T> struct variant_size<const T>;
  template <class T> struct variant_size<volatile T>;
  template <class T> struct variant_size<const volatile T>;
  template <class T>
    inline constexpr size_t variant_size_v = variant_size<T>::value;

  template <class... Types>
    struct variant_size<variant<Types...>>;

  template <size_t I, class T> struct variant_alternative;  // not defined
  template <size_t I, class T> struct variant_alternative<I, const T>;
  template <size_t I, class T> struct variant_alternative<I, volatile T>;
  template <size_t I, class T> struct variant_alternative<I, const volatile T>;
  template <size_t I, class T>
    using variant_alternative_t = typename variant_alternative<I, T>::type;

  template <size_t I, class... Types>
    struct variant_alternative<I, variant<Types...>>;

  inline constexpr size_t variant_npos = -1;

  // variant.get, value access
  template <class T, class... Types>
    constexpr bool holds_alternative(const variant<Types...>&) noexcept;

  template <size_t I, class... Types>
    constexpr variant_alternative_t<I, variant<Types...>>& get(variant<Types...>&);
  template <size_t I, class... Types>
    constexpr variant_alternative_t<I, variant<Types...>>&& get(variant<Types...>&&);
  template <size_t I, class... Types>
    constexpr const variant_alternative_t<I, variant<Types...>>& get(const variant<Types...>&);
  template <size_t I, class... Types>
    constexpr const variant_alternative_t<I, variant<Types...>>&& get(const variant<Types...>&&);

  template <class T, class... Types>
    constexpr T& get(variant<Types...>&);
  template <class T, class... Types>
    constexpr T&& get(variant<Types...>&&);
  template <class T, class... Types>
    constexpr const T& get(const variant<Types...>&);
  template <class T, class... Types>
    constexpr const T&& get(const variant<Types...>&&);

  template <size_t I, class... Types>
    constexpr add_pointer_t<variant_alternative_t<I, variant<Types...>>>
      get_if(variant<Types...>*) noexcept;
  template <size_t I, class... Types>
    constexpr add_pointer_t<const variant_alternative_t<I, variant<Types...>>>
      get_if(const variant<Types...>*) noexcept;

  template <class T, class... Types>
    constexpr add_pointer_t<T>
      get_if(variant<Types...>*) noexcept;
  template <class T, class... Types>
    constexpr add_pointer_t<const T>
      get_if(const variant<Types...>*) noexcept;

  // variant.relops, relational operators
  template <class... Types>
    constexpr bool operator==(const variant<Types...>&, const variant<Types...>&);
  template <class... Types>
    constexpr bool operator!=(const variant<Types...>&, const variant<Types...>&);
  template <class... Types>
    constexpr bool operator<(const variant<Types...>&, const variant<Types...>&);
  template <class... Types>
    constexpr bool operator>(const variant<Types...>&, const variant<Types...>&);
  template <class... Types>
    constexpr bool operator<=(const variant<Types...>&, const variant<Types...>&);
  template <class... Types>
    constexpr bool operator>=(const variant<Types...>&, const variant<Types...>&);

  // variant.visit, visitation
  template <class Visitor, class... Variants>
    constexpr @\seebelow@ visit(Visitor&&, Variants&&...);

  // variant.monostate, class monostate
  struct monostate;

  // variant.monostate.relops, monostate relational operators
  constexpr bool operator<(monostate, monostate) noexcept;
  constexpr bool operator>(monostate, monostate) noexcept;
  constexpr bool operator<=(monostate, monostate) noexcept;
  constexpr bool operator>=(monostate, monostate) noexcept;
  constexpr bool operator==(monostate, monostate) noexcept;
  constexpr bool operator!=(monostate, monostate) noexcept;

  // variant.specalg, specialized algorithms
  template <class... Types>
    void swap(variant<Types...>&, variant<Types...>&) noexcept(@\seebelow@);

  // variant.bad.access, class bad_variant_access
  class bad_variant_access;

  // variant.hash, hash support
  template <class T> struct hash;
  template <class... Types> struct hash<variant<Types...>>;
  template <> struct hash<monostate>;

  // variant.traits, allocator-related traits
  template <class T, class Alloc> struct uses_allocator;
  template <class... Types, class Alloc> struct uses_allocator<variant<Types...>, Alloc>;
}
