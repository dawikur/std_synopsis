#include <compare>              // see compare.syn

namespace std {
  // stacktrace.entry, class stacktrace_entry
  class stacktrace_entry;

  // stacktrace.basic, class template basic_stacktrace
  template<class Allocator>
    class basic_stacktrace;

  // basic_stacktrace typedef-names
  using stacktrace = basic_stacktrace<allocator<stacktrace_entry>>;

  // stacktrace.basic.nonmem, non-member functions
  template<class Allocator>
    void swap(basic_stacktrace<Allocator>& a, basic_stacktrace<Allocator>& b)
      noexcept(noexcept(a.swap(b)));

  string to_string(const stacktrace_entry& f);

  template<class Allocator>
    string to_string(const basic_stacktrace<Allocator>& st);

  ostream& operator<<(ostream& os, const stacktrace_entry& f);
  template<class Allocator>
    ostream& operator<<(ostream& os, const basic_stacktrace<Allocator>& st);

  // stacktrace.format, formatting support
  template<> struct formatter<stacktrace_entry>;
  template<class Allocator> struct formatter<basic_stacktrace<Allocator>>;

  namespace pmr {
    using stacktrace = basic_stacktrace<polymorphic_allocator<stacktrace_entry>>;
  }

  // stacktrace.basic.hash, hash support
  template<class T> struct hash;
  template<> struct hash<stacktrace_entry>;
  template<class Allocator> struct hash<basic_stacktrace<Allocator>>;
}
