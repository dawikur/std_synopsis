namespace std {
  @\unspec@ resetiosflags(ios_base::fmtflags mask);
  @\unspec@ setiosflags  (ios_base::fmtflags mask);
  @\unspec@ setbase(int base);
  template<class charT> @\unspec@ setfill(charT c);
  @\unspec@ setprecision(int n);
  @\unspec@ setw(int n);
  template<class moneyT> @\unspec@ get_money(moneyT& mon, bool intl = false);
  template<class moneyT> @\unspec@ put_money(const moneyT& mon, bool intl = false);
  template<class charT> @\unspec@ get_time(tm* tmb, const charT* fmt);
  template<class charT> @\unspec@ put_time(const tm* tmb, const charT* fmt);

  template<class charT>
    @\unspec@ quoted(const charT* s, charT delim = charT('"'), charT escape = charT('\\'));

  template<class charT, class traits, class Allocator>
    @\unspec@ quoted(const basic_string<charT, traits, Allocator>& s,
    @\itcorr@                   charT delim = charT('"'), charT escape = charT('\\'));

  template<class charT, class traits, class Allocator>
    @\unspec@ quoted(basic_string<charT, traits, Allocator>& s,
    @\itcorr@                   charT delim = charT('"'), charT escape = charT('\\'));

  template<class charT, class traits>
    @\unspec@ quoted(basic_string_view<charT, traits> s,
    @\itcorr@                   charT delim = charT('"'), charT escape = charT('\\'));
}
