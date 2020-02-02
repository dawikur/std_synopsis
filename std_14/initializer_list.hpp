namespace std {
  template<class E> class initializer_list {
  public:
    typedef E value_type;
    typedef const E& reference;
    typedef const E& const_reference;
    typedef size_t size_type;

    typedef const E* iterator;
    typedef const E* const_iterator;

    constexpr initializer_list() noexcept;

    constexpr size_t size() const noexcept;      // number of elements
    constexpr const E* begin() const noexcept;   // first element
    constexpr const E* end() const noexcept;     // one past the last element
  };

  // support.initlist.range initializer list range access
  template<class E> constexpr const E* begin(initializer_list<E> il) noexcept;
  template<class E> constexpr const E* end(initializer_list<E> il) noexcept;
}
