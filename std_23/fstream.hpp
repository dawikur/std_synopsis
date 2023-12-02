namespace std {
  template<class charT, class traits = char_traits<charT>>
    class basic_filebuf;

  template<class charT, class traits>
    void swap(basic_filebuf<charT, traits>& x, basic_filebuf<charT, traits>& y);

  using filebuf  = basic_filebuf<char>;
  using wfilebuf = basic_filebuf<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_ifstream;

  template<class charT, class traits>
    void swap(basic_ifstream<charT, traits>& x, basic_ifstream<charT, traits>& y);

  using ifstream  = basic_ifstream<char>;
  using wifstream = basic_ifstream<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_ofstream;

  template<class charT, class traits>
    void swap(basic_ofstream<charT, traits>& x, basic_ofstream<charT, traits>& y);

  using ofstream  = basic_ofstream<char>;
  using wofstream = basic_ofstream<wchar_t>;

  template<class charT, class traits = char_traits<charT>>
    class basic_fstream;

  template<class charT, class traits>
    void swap(basic_fstream<charT, traits>& x, basic_fstream<charT, traits>& y);

  using fstream  = basic_fstream<char>;
  using wfstream = basic_fstream<wchar_t>;
}
