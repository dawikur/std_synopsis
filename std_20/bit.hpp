namespace std {
  // bit.cast, bit_cast
  template<class To, class From>
    constexpr To bit_cast(const From& from) noexcept;

  // bit.pow.two, integral powers of 2
  template<class T>
    constexpr bool has_single_bit(T x) noexcept;
  template<class T>
    constexpr T bit_ceil(T x);
  template<class T>
    constexpr T bit_floor(T x) noexcept;
  template<class T>
    constexpr T bit_width(T x) noexcept;

  // bit.rotate, rotating
  template<class T>
    [[nodiscard]] constexpr T rotl(T x, int s) noexcept;
  template<class T>
    [[nodiscard]] constexpr T rotr(T x, int s) noexcept;

  // bit.count, counting
  template<class T>
    constexpr int countl_zero(T x) noexcept;
  template<class T>
    constexpr int countl_one(T x) noexcept;
  template<class T>
    constexpr int countr_zero(T x) noexcept;
  template<class T>
    constexpr int countr_one(T x) noexcept;
  template<class T>
    constexpr int popcount(T x) noexcept;

  // bit.endian, endian
  enum class endian {
    little = @\seebelow@,
    big    = @\seebelow@,
    native = @\seebelow@
  };
}
