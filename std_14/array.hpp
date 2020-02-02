#include <initializer_list>

namespace std {
  template <class T, size_t N> struct array;
  template <class T, size_t N>
    bool operator==(const array<T,N>& x, const array<T,N>& y);
  template <class T, size_t N>
    bool operator!=(const array<T,N>& x, const array<T,N>& y);
  template <class T, size_t N>
    bool operator<(const array<T,N>& x, const array<T,N>& y);
  template <class T, size_t N>
    bool operator>(const array<T,N>& x, const array<T,N>& y);
  template <class T, size_t N>
    bool operator<=(const array<T,N>& x, const array<T,N>& y);
  template <class T, size_t N>
    bool operator>=(const array<T,N>& x, const array<T,N>& y);
  template <class T, size_t N>
    void swap(array<T,N>& x, array<T,N>& y) noexcept(noexcept(x.swap(y)));

  template <class T> class tuple_size;
  template <size_t I, class T> class tuple_element;
  template <class T, size_t N>
    struct tuple_size<array<T, N> >;
  template <size_t I, class T, size_t N>
    struct tuple_element<I, array<T, N> >;
  template <size_t I, class T, size_t N>
    constexpr T& get(array<T, N>&) noexcept;
  template <size_t I, class T, size_t N>
    constexpr T&& get(array<T, N>&&) noexcept;
  template <size_t I, class T, size_t N>
    constexpr const T& get(const array<T, N>&) noexcept;
}
