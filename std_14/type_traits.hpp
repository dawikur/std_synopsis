namespace std {
  // meta.help, helper class:
  template <class T, T v> struct integral_constant;
  typedef integral_constant<bool, true>  true_type;
  typedef integral_constant<bool, false> false_type;

  // meta.unary.cat, primary type categories:
  template <class T> struct is_void;
  template <class T> struct is_null_pointer;
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
  template <class T> struct is_final;

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

  template <class T>
    using remove_const_t    = typename remove_const<T>::type;
  template <class T>
    using remove_volatile_t = typename remove_volatile<T>::type;
  template <class T>
    using remove_cv_t       = typename remove_cv<T>::type;
  template <class T>
    using add_const_t       = typename add_const<T>::type;
  template <class T>
    using add_volatile_t    = typename add_volatile<T>::type;
  template <class T>
    using add_cv_t          = typename add_cv<T>::type;

  // meta.trans.ref, reference modifications:
  template <class T> struct remove_reference;
  template <class T> struct add_lvalue_reference;
  template <class T> struct add_rvalue_reference;

  template <class T>
    using remove_reference_t     = typename remove_reference<T>::type;
  template <class T>
    using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
  template <class T>
    using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

  // meta.trans.sign, sign modifications:
  template <class T> struct make_signed;
  template <class T> struct make_unsigned;

  template <class T>
    using make_signed_t   = typename make_signed<T>::type;
  template <class T>
    using make_unsigned_t = typename make_unsigned<T>::type;

  // meta.trans.arr, array modifications:
  template <class T> struct remove_extent;
  template <class T> struct remove_all_extents;

  template <class T>
    using remove_extent_t      = typename remove_extent<T>::type;
  template <class T>
    using remove_all_extents_t = typename remove_all_extents<T>::type;

  // meta.trans.ptr, pointer modifications:
  template <class T> struct remove_pointer;
  template <class T> struct add_pointer;

  template <class T>
    using remove_pointer_t = typename remove_pointer<T>::type;
  template <class T>
    using add_pointer_t    = typename add_pointer<T>::type;

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

  template <std::size_t Len,
            std::size_t Align = default-alignment > // see meta.trans.other
    using aligned_storage_t = typename aligned_storage<Len,Align>::type;
  template <std::size_t Len, class... Types>
    using aligned_union_t   = typename aligned_union<Len,Types...>::type;
  template <class T>
    using decay_t           = typename decay<T>::type;
  template <bool b, class T = void>
    using enable_if_t       = typename enable_if<b,T>::type;
  template <bool b, class T, class F>
    using conditional_t     = typename conditional<b,T,F>::type;
  template <class... T>
    using common_type_t     = typename common_type<T...>::type;
  template <class T>
    using underlying_type_t = typename underlying_type<T>::type;
  template <class T>
    using result_of_t       = typename result_of<T>::type;  
} // namespace std
