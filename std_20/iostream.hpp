#include <ios>          // see ios.syn
#include <streambuf>    // see streambuf.syn
#include <istream>      // see istream.syn
#include <ostream>      // see ostream.syn

namespace std {
  extern istream cin;
  extern ostream cout;
  extern ostream cerr;
  extern ostream clog;

  extern wistream wcin;
  extern wostream wcout;
  extern wostream wcerr;
  extern wostream wclog;
}
