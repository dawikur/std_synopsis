#include <string>
#include <iosfwd>               // for istream, ostream
namespace std {
  template <size_t N> class bitset;

  // bitset.operators bitset operators:
  template <size_t N>
    bitset<N> operator&(const bitset<N>&, const bitset<N>&) noexcept;
  template <size_t N>
    bitset<N> operator|(const bitset<N>&, const bitset<N>&) noexcept;
  template <size_t N>
    bitset<N> operator^(const bitset<N>&, const bitset<N>&) noexcept;
  template <class charT, class traits, size_t N>
    basic_istream<charT, traits>&
    operator>>(basic_istream<charT, traits>& is, bitset<N>& x);
  template <class charT, class traits, size_t N>
    basic_ostream<charT, traits>&
    operator<<(basic_ostream<charT, traits>& os, const bitset<N>& x);
}
