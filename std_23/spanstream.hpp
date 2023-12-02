namespace std {
  template<class charT, class traits = char_traits<charT>>
    class basic_spanbuf;

  template<class charT, class traits>
    void swap(basic_spanbuf<charT, traits>& x, basic_spanbuf<charT, traits>& y);

  using spanbuf = basic_spanbuf<char>;
  using wspanbuf = basic_spanbuf<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_ispanstream;

  template<class charT, class traits>
    void swap(basic_ispanstream<charT, traits>& x, basic_ispanstream<charT, traits>& y);

  using ispanstream = basic_ispanstream<char>;
  using wispanstream = basic_ispanstream<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_ospanstream;

  template<class charT, class traits>
    void swap(basic_ospanstream<charT, traits>& x, basic_ospanstream<charT, traits>& y);

  using ospanstream = basic_ospanstream<char>;
  using wospanstream = basic_ospanstream<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_spanstream;

  template<class charT, class traits>
    void swap(basic_spanstream<charT, traits>& x, basic_spanstream<charT, traits>& y);

  using spanstream = basic_spanstream<char>;
  using wspanstream = basic_spanstream<wchar_t>;
}
