#include <ostream>  // see ostream.syn

namespace std {
  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
    class basic_syncbuf;

  // syncstream.syncbuf.special, specialized algorithms
  template<class charT, class traits, class Allocator>
    void swap(basic_syncbuf<charT, traits, Allocator>&,
              basic_syncbuf<charT, traits, Allocator>&);

  using syncbuf = basic_syncbuf<char>;
  using wsyncbuf = basic_syncbuf<wchar_t>;

  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
    class basic_osyncstream;

  using osyncstream = basic_osyncstream<char>;
  using wosyncstream = basic_osyncstream<wchar_t>;
}
