#include <ostream>  // see ostream.syn

namespace std {
  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
    class basic_syncbuf;

  using syncbuf = basic_syncbuf<char>;
  using wsyncbuf = basic_syncbuf<wchar_t>;

  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
    class basic_osyncstream;

  using osyncstream = basic_osyncstream<char>;
  using wosyncstream = basic_osyncstream<wchar_t>;
}
