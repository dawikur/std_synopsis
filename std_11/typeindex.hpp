namespace std {
  class type_index;
  template <class T> struct hash;
  template<> struct hash<type_index>;
}
