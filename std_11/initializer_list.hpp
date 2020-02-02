namespace std {
  template<class E> class initializer_list {
  public:
    typedef E value_type;
    typedef const E& reference;
    typedef const E& const_reference;
    typedef size_t size_type;

    typedef const E* iterator;
    typedef const E* const_iterator;

    initializer_list() noexcept;

    size_t size() const noexcept;      // number of elements
    const E* begin() const noexcept;   // first element
    const E* end() const noexcept;     // one past the last element
  };

  // support.initlist.range initializer list range access
  template<class E> const E* begin(initializer_list<E> il) noexcept;
  template<class E> const E* end(initializer_list<E> il) noexcept;
}
