namespace std {
  // print.fun, print functions
  template<class... Args>
    void print(format_string<Args...> fmt, Args&&... args);
  template<class... Args>
    void print(FILE* stream, format_string<Args...> fmt, Args&&... args);

  template<class... Args>
    void println(format_string<Args...> fmt, Args&&... args);
  template<class... Args>
    void println(FILE* stream, format_string<Args...> fmt, Args&&... args);

  void vprint_unicode(string_view fmt, format_args args);
  void vprint_unicode(FILE* stream, string_view fmt, format_args args);

  void vprint_nonunicode(string_view fmt, format_args args);
  void vprint_nonunicode(FILE* stream, string_view fmt, format_args args);
}
