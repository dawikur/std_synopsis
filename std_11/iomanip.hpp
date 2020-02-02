namespace std {
  // types T1, T2, ... are unspecified implementation types
  @T1@ resetiosflags(ios_base::fmtflags mask);
  @T2@ setiosflags  (ios_base::fmtflags mask);
  @T3@ setbase(int base);
  template<charT> @T4@ setfill(charT c);
  @T5@ setprecision(int n);
  @T6@ setw(int n);
  template <class moneyT> @T7@ get_money(moneyT& mon, bool intl = false);
  template <class moneyT> @T8@ put_money(const moneyT& mon, bool intl = false);
  template <class charT> @T9@ get_time(struct tm* tmb, const charT* fmt);
  template <class charT> @T10@ put_time(const struct tm* tmb, const charT* fmt);
}
