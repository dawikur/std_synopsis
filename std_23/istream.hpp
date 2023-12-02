namespace std {
  template<class charT, class traits = char_traits<charT>>
    class basic_istream;

  using istream  = basic_istream<char>;
  using wistream = basic_istream<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_iostream;

  using iostream  = basic_iostream<char>;
  using wiostream = basic_iostream<wchar_t>;

  template<class charT, class traits>
    basic_istream<charT, traits>& ws(basic_istream<charT, traits>& is);

  template<class Istream, class T>
    Istream&& operator>>(Istream&& is, T&& x);
}
