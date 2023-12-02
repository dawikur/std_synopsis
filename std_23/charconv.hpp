@%
chars_format%
scientific}{chars_format%
fixed}{chars_format%
hex}{chars_format%
general}{chars_format%
@namespace std {
  // floating-point format for primitive numerical conversion
  enum class chars_format {
    scientific = @\unspec@,
    fixed = @\unspec@,
    hex = @\unspec@,
    general = fixed | scientific
  };
@%
to_chars_result%
ptr}{to_chars_result%
ec}{to_chars_result
@
  // charconv.to.chars, primitive numerical output conversion
  struct to_chars_result {
    char* ptr;
    errc ec;
    friend bool operator==(const to_chars_result&, const to_chars_result&) = default;
  };

  constexpr to_chars_result to_chars(char* first, char* last, @integer-type@ value, int base = 10);
  to_chars_result to_chars(char* first, char* last, bool value, int base = 10) = delete;

  to_chars_result to_chars(char* first, char* last, @floating-point-type@ value);
  to_chars_result to_chars(char* first, char* last, @floating-point-type@ value, chars_format fmt);
  to_chars_result to_chars(char* first, char* last, @floating-point-type@ value,
                           chars_format fmt, int precision);
@%
from_chars_result%
ptr}{from_chars_result%
ec}{from_chars_result
@
  // charconv.from.chars, primitive numerical input conversion
  struct from_chars_result {
    const char* ptr;
    errc ec;
    friend bool operator==(const from_chars_result&, const from_chars_result&) = default;
  };

  constexpr from_chars_result from_chars(const char* first, const char* last,
                                         @integer-type@& value, int base = 10);

  from_chars_result from_chars(const char* first, const char* last, @floating-point-type@& value,
                               chars_format fmt = chars_format::general);
}
