namespace std {
  // expected.unexpected, class template unexpected
  template<class E> class unexpected;

  // expected.bad, class template bad_expected_access
  template<class E> class bad_expected_access;

  // expected.bad.void, specialization for void
  template<> class bad_expected_access<void>;

  // in-place construction of unexpected values
  struct unexpect_t {
    explicit unexpect_t() = default;
  };
  inline constexpr unexpect_t unexpect{};

  // expected.expected, class template expected
  template<class T, class E> class expected;

  // expected.void, partial specialization of expected for void types
  template<class T, class E> requires is_void_v<T> class expected<T, E>;
}
