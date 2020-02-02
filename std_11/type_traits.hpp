namespace std {
  // meta.help, helper class:
  template <class T, T v> struct integral_constant;
  typedef integral_constant<bool, true>  true_type;
  typedef integral_constant<bool, false> false_type;

  // meta.unary.cat, primary type categories:
  template <class T> struct is_void;
  template <class T> struct is_integral;
  template <class T> struct is_floating_point;
  template <class T> struct is_array;
  template <class T> struct is_pointer;
  template <class T> struct is_lvalue_reference;
  template <class T> struct is_rvalue_reference;
  template <class T> struct is_member_object_pointer;
  template <class T> struct is_member_function_pointer;
  template <class T> struct is_enum;
  template <class T> struct is_union;
  template <class T> struct is_class;
  template <class T> struct is_function;

  // meta.unary.comp, composite type categories:
  template <class T> struct is_reference;
  template <class T> struct is_arithmetic;
  template <class T> struct is_fundamental;
  template <class T> struct is_object;
  template <class T> struct is_scalar;
  template <class T> struct is_compound;
  template <class T> struct is_member_pointer;

  // meta.unary.prop, type properties:
  template <class T> struct is_const;
  template <class T> struct is_volatile;
  template <class T> struct is_trivial;
  template <class T> struct is_trivially_copyable;
  template <class T> struct is_standard_layout;
  template <class T> struct is_pod;
  template <class T> struct is_literal_type;
  template <class T> struct is_empty;
  template <class T> struct is_polymorphic;
  template <class T> struct is_abstract;

  template <class T> struct is_signed;
  template <class T> struct is_unsigned;

  template <class T, class... Args> struct is_constructible;
  template <class T> struct is_default_constructible;
  template <class T> struct is_copy_constructible;
  template <class T> struct is_move_constructible;

  template <class T, class U> struct is_assignable;
  template <class T> struct is_copy_assignable;
  template <class T> struct is_move_assignable;

  template <class T> struct is_destructible;

  template <class T, class... Args> struct is_trivially_constructible;
  template <class T> struct is_trivially_default_constructible;
  template <class T> struct is_trivially_copy_constructible;
  template <class T> struct is_trivially_move_constructible;

  template <class T, class U> struct is_trivially_assignable;
  template <class T> struct is_trivially_copy_assignable;
  template <class T> struct is_trivially_move_assignable;
  template <class T> struct is_trivially_destructible;

  template <class T, class... Args> struct is_nothrow_constructible;
  template <class T> struct is_nothrow_default_constructible;
  template <class T> struct is_nothrow_copy_constructible;
  template <class T> struct is_nothrow_move_constructible;

  template <class T, class U> struct is_nothrow_assignable;
  template <class T> struct  is_nothrow_copy_assignable;
  template <class T> struct is_nothrow_move_assignable;

  template <class T> struct is_nothrow_destructible;
  template <class T> struct has_virtual_destructor;

  // meta.unary.prop.query, type property queries:
  template <class T> struct alignment_of;
  template <class T> struct rank;
  template <class T, unsigned I = 0> struct extent;

  // meta.rel, type relations:
  template <class T, class U> struct is_same;
  template <class Base, class Derived> struct is_base_of;
  template <class From, class To> struct is_convertible;

  // meta.trans.cv, const-volatile modifications:
  template <class T> struct remove_const;
  template <class T> struct remove_volatile;
  template <class T> struct remove_cv;
  template <class T> struct add_const;
  template <class T> struct add_volatile;
  template <class T> struct add_cv;

  // meta.trans.ref, reference modifications:
  template <class T> struct remove_reference;
  template <class T> struct add_lvalue_reference;
  template <class T> struct add_rvalue_reference;

  // meta.trans.sign, sign modifications:
  template <class T> struct make_signed;
  template <class T> struct make_unsigned;

  // meta.trans.arr, array modifications:
  template <class T> struct remove_extent;
  template <class T> struct remove_all_extents;

  // meta.trans.ptr, pointer modifications:
  template <class T> struct remove_pointer;
  template <class T> struct add_pointer;

  // meta.trans.other, other transformations:
  template <std::size_t Len,
            std::size_t Align = default-alignment>   // see meta.trans.other
    struct aligned_storage;      
  template <std::size_t Len, class... Types> struct aligned_union;
  template <class T> struct decay;
  template <bool, class T = void> struct enable_if;
  template <bool, class T, class F> struct conditional;
  template <class... T> struct common_type;
  template <class T> struct underlying_type;
  template <class> class result_of;   // not defined
  template <class F, class... ArgTypes> class result_of<F(ArgTypes...)>;
} // namespace std
