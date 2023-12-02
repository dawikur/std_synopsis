namespace std {
  template<class charT, class traits = char_traits<charT>>
    class basic_ostream;

  using ostream  = basic_ostream<char>;
  using wostream = basic_ostream<wchar_t>;

  template<class charT, class traits>
    basic_ostream<charT, traits>& endl(basic_ostream<charT, traits>& os);
  template<class charT, class traits>
    basic_ostream<charT, traits>& ends(basic_ostream<charT, traits>& os);
  template<class charT, class traits>
    basic_ostream<charT, traits>& flush(basic_ostream<charT, traits>& os);

  template<class charT, class traits>
    basic_ostream<charT, traits>& emit_on_flush(basic_ostream<charT, traits>& os);
  template<class charT, class traits>
    basic_ostream<charT, traits>& noemit_on_flush(basic_ostream<charT, traits>& os);
  template<class charT, class traits>
    basic_ostream<charT, traits>& flush_emit(basic_ostream<charT, traits>& os);

  template<class Ostream, class T>
    Ostream&& operator<<(Ostream&& os, const T& x);

  // ostream.formatted.print, print functions
  template<class... Args>
    void print(ostream& os, format_string<Args...> fmt, Args&&... args);
  template<class... Args>
    void println(ostream& os, format_string<Args...> fmt, Args&&... args);

  void vprint_unicode(ostream& os, string_view fmt, format_args args);
  void vprint_nonunicode(ostream& os, string_view fmt, format_args args);
}
