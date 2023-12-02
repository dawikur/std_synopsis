// all freestanding
namespace std {
  // meta.help, helper class
  template<class T, T v> struct integral_constant;

  template<bool B>
    using bool_constant = integral_constant<bool, B>;
  using true_type  = bool_constant<true>;
  using false_type = bool_constant<false>;

  // meta.unary.cat, primary type categories
  template<class T> struct is_void;
  template<class T> struct is_null_pointer;
  template<class T> struct is_integral;
  template<class T> struct is_floating_point;
  template<class T> struct is_array;
  template<class T> struct is_pointer;
  template<class T> struct is_lvalue_reference;
  template<class T> struct is_rvalue_reference;
  template<class T> struct is_member_object_pointer;
  template<class T> struct is_member_function_pointer;
  template<class T> struct is_enum;
  template<class T> struct is_union;
  template<class T> struct is_class;
  template<class T> struct is_function;

  // meta.unary.comp, composite type categories
  template<class T> struct is_reference;
  template<class T> struct is_arithmetic;
  template<class T> struct is_fundamental;
  template<class T> struct is_object;
  template<class T> struct is_scalar;
  template<class T> struct is_compound;
  template<class T> struct is_member_pointer;

  // meta.unary.prop, type properties
  template<class T> struct is_const;
  template<class T> struct is_volatile;
  template<class T> struct is_trivial;
  template<class T> struct is_trivially_copyable;
  template<class T> struct is_standard_layout;
  template<class T> struct is_empty;
  template<class T> struct is_polymorphic;
  template<class T> struct is_abstract;
  template<class T> struct is_final;
  template<class T> struct is_aggregate;

  template<class T> struct is_signed;
  template<class T> struct is_unsigned;
  template<class T> struct is_bounded_array;
  template<class T> struct is_unbounded_array;
  template<class T> struct is_scoped_enum;

  template<class T, class... Args> struct is_constructible;
  template<class T> struct is_default_constructible;
  template<class T> struct is_copy_constructible;
  template<class T> struct is_move_constructible;

  template<class T, class U> struct is_assignable;
  template<class T> struct is_copy_assignable;
  template<class T> struct is_move_assignable;

  template<class T, class U> struct is_swappable_with;
  template<class T> struct is_swappable;

  template<class T> struct is_destructible;

  template<class T, class... Args> struct is_trivially_constructible;
  template<class T> struct is_trivially_default_constructible;
  template<class T> struct is_trivially_copy_constructible;
  template<class T> struct is_trivially_move_constructible;

  template<class T, class U> struct is_trivially_assignable;
  template<class T> struct is_trivially_copy_assignable;
  template<class T> struct is_trivially_move_assignable;
  template<class T> struct is_trivially_destructible;

  template<class T, class... Args> struct is_nothrow_constructible;
  template<class T> struct is_nothrow_default_constructible;
  template<class T> struct is_nothrow_copy_constructible;
  template<class T> struct is_nothrow_move_constructible;

  template<class T, class U> struct is_nothrow_assignable;
  template<class T> struct is_nothrow_copy_assignable;
  template<class T> struct is_nothrow_move_assignable;

  template<class T, class U> struct is_nothrow_swappable_with;
  template<class T> struct is_nothrow_swappable;

  template<class T> struct is_nothrow_destructible;

  template<class T> struct is_implicit_lifetime;

  template<class T> struct has_virtual_destructor;

  template<class T> struct has_unique_object_representations;

  template<class T, class U> struct reference_constructs_from_temporary;
  template<class T, class U> struct reference_converts_from_temporary;

  // meta.unary.prop.query, type property queries
  template<class T> struct alignment_of;
  template<class T> struct rank;
  template<class T, unsigned I = 0> struct extent;

  // meta.rel, type relations
  template<class T, class U> struct is_same;
  template<class Base, class Derived> struct is_base_of;
  template<class From, class To> struct is_convertible;
  template<class From, class To> struct is_nothrow_convertible;
  template<class T, class U> struct is_layout_compatible;
  template<class Base, class Derived> struct is_pointer_interconvertible_base_of;

  template<class Fn, class... ArgTypes> struct is_invocable;
  template<class R, class Fn, class... ArgTypes> struct is_invocable_r;

  template<class Fn, class... ArgTypes> struct is_nothrow_invocable;
  template<class R, class Fn, class... ArgTypes> struct is_nothrow_invocable_r;

  // meta.trans.cv, const-volatile modifications
  template<class T> struct remove_const;
  template<class T> struct remove_volatile;
  template<class T> struct remove_cv;
  template<class T> struct add_const;
  template<class T> struct add_volatile;
  template<class T> struct add_cv;

  template<class T>
    using @remove_const_t@    = typename remove_const<T>::type;
  template<class T>
    using @remove_volatile_t@ = typename remove_volatile<T>::type;
  template<class T>
    using @remove_cv_t@       = typename remove_cv<T>::type;
  template<class T>
    using @add_const_t@       = typename add_const<T>::type;
  template<class T>
    using @add_volatile_t@    = typename add_volatile<T>::type;
  template<class T>
    using @add_cv_t@          = typename add_cv<T>::type;

  // meta.trans.ref, reference modifications
  template<class T> struct remove_reference;
  template<class T> struct add_lvalue_reference;
  template<class T> struct add_rvalue_reference;

  template<class T>
    using @remove_reference_t@     = typename remove_reference<T>::type;
  template<class T>
    using @add_lvalue_reference_t@ = typename add_lvalue_reference<T>::type;
  template<class T>
    using @add_rvalue_reference_t@ = typename add_rvalue_reference<T>::type;

  // meta.trans.sign, sign modifications
  template<class T> struct make_signed;
  template<class T> struct make_unsigned;

  template<class T>
    using @make_signed_t@   = typename make_signed<T>::type;
  template<class T>
    using @make_unsigned_t@ = typename make_unsigned<T>::type;

  // meta.trans.arr, array modifications
  template<class T> struct remove_extent;
  template<class T> struct remove_all_extents;

  template<class T>
    using @remove_extent_t@      = typename remove_extent<T>::type;
  template<class T>
    using @remove_all_extents_t@ = typename remove_all_extents<T>::type;

  // meta.trans.ptr, pointer modifications
  template<class T> struct remove_pointer;
  template<class T> struct add_pointer;

  template<class T>
    using @remove_pointer_t@ = typename remove_pointer<T>::type;
  template<class T>
    using @add_pointer_t@    = typename add_pointer<T>::type;

  // meta.trans.other, other transformations
  template<class T> struct type_identity;
  template<class T> struct remove_cvref;
  template<class T> struct decay;
  template<bool, class T = void> struct enable_if;
  template<bool, class T, class F> struct conditional;
  template<class... T> struct common_type;
  template<class T, class U, template<class> class TQual, template<class> class UQual>
    struct basic_common_reference { };
  template<class... T> struct common_reference;
  template<class T> struct underlying_type;
  template<class Fn, class... ArgTypes> struct invoke_result;
  template<class T> struct unwrap_reference;
  template<class T> struct unwrap_ref_decay;

  template<class T>
    using @type_identity_t@    = typename type_identity<T>::type;
  template<class T>
    using @remove_cvref_t@     = typename remove_cvref<T>::type;
  template<class T>
    using @decay_t@            = typename decay<T>::type;
  template<bool B, class T = void>
    using @enable_if_t@        = typename enable_if<B, T>::type;
  template<bool B, class T, class F>
    using @conditional_t@      = typename conditional<B, T, F>::type;
  template<class... T>
    using @common_type_t@      = typename common_type<T...>::type;
  template<class... T>
    using @common_reference_t@ = typename common_reference<T...>::type;
  template<class T>
    using @underlying_type_t@  = typename underlying_type<T>::type;
  template<class Fn, class... ArgTypes>
    using @invoke_result_t@    = typename invoke_result<Fn, ArgTypes...>::type;
  template<class T>
    using unwrap_reference_t = typename unwrap_reference<T>::type;
  template<class T>
    using unwrap_ref_decay_t = typename unwrap_ref_decay<T>::type;
  template<class...>
    using @void_t@             = void;

  // meta.logical, logical operator traits
  template<class... B> struct conjunction;
  template<class... B> struct disjunction;
  template<class B> struct negation;

  // meta.unary.cat, primary type categories
  template<class T>
    constexpr bool @is_void_v@ = is_void<T>::value;
  template<class T>
    constexpr bool @is_null_pointer_v@ = is_null_pointer<T>::value;
  template<class T>
    constexpr bool @is_integral_v@ = is_integral<T>::value;
  template<class T>
    constexpr bool @is_floating_point_v@ = is_floating_point<T>::value;
  template<class T>
    constexpr bool @is_array_v@ = is_array<T>::value;
  template<class T>
    constexpr bool @is_pointer_v@ = is_pointer<T>::value;
  template<class T>
    constexpr bool @is_lvalue_reference_v@ = is_lvalue_reference<T>::value;
  template<class T>
    constexpr bool @is_rvalue_reference_v@ = is_rvalue_reference<T>::value;
  template<class T>
    constexpr bool @is_member_object_pointer_v@ = is_member_object_pointer<T>::value;
  template<class T>
    constexpr bool @is_member_function_pointer_v@ = is_member_function_pointer<T>::value;
  template<class T>
    constexpr bool @is_enum_v@ = is_enum<T>::value;
  template<class T>
    constexpr bool @is_union_v@ = is_union<T>::value;
  template<class T>
    constexpr bool @is_class_v@ = is_class<T>::value;
  template<class T>
    constexpr bool @is_function_v@ = is_function<T>::value;

  // meta.unary.comp, composite type categories
  template<class T>
    constexpr bool @is_reference_v@ = is_reference<T>::value;
  template<class T>
    constexpr bool @is_arithmetic_v@ = is_arithmetic<T>::value;
  template<class T>
    constexpr bool @is_fundamental_v@ = is_fundamental<T>::value;
  template<class T>
    constexpr bool @is_object_v@ = is_object<T>::value;
  template<class T>
    constexpr bool @is_scalar_v@ = is_scalar<T>::value;
  template<class T>
    constexpr bool @is_compound_v@ = is_compound<T>::value;
  template<class T>
    constexpr bool @is_member_pointer_v@ = is_member_pointer<T>::value;

  // meta.unary.prop, type properties
  template<class T>
    constexpr bool @is_const_v@ = is_const<T>::value;
  template<class T>
    constexpr bool @is_volatile_v@ = is_volatile<T>::value;
  template<class T>
    constexpr bool @is_trivial_v@ = is_trivial<T>::value;
  template<class T>
    constexpr bool @is_trivially_copyable_v@ = is_trivially_copyable<T>::value;
  template<class T>
    constexpr bool @is_standard_layout_v@ = is_standard_layout<T>::value;
  template<class T>
    constexpr bool @is_empty_v@ = is_empty<T>::value;
  template<class T>
    constexpr bool @is_polymorphic_v@ = is_polymorphic<T>::value;
  template<class T>
    constexpr bool @is_abstract_v@ = is_abstract<T>::value;
  template<class T>
    constexpr bool @is_final_v@ = is_final<T>::value;
  template<class T>
    constexpr bool @is_aggregate_v@ = is_aggregate<T>::value;
  template<class T>
    constexpr bool @is_signed_v@ = is_signed<T>::value;
  template<class T>
    constexpr bool @is_unsigned_v@ = is_unsigned<T>::value;
  template<class T>
    constexpr bool @is_bounded_array_v@ = is_bounded_array<T>::value;
  template<class T>
    constexpr bool @is_unbounded_array_v@ = is_unbounded_array<T>::value;
  template<class T>
    constexpr bool @is_scoped_enum_v@ = is_scoped_enum<T>::value;
  template<class T, class... Args>
    constexpr bool @is_constructible_v@ = is_constructible<T, Args...>::value;
  template<class T>
    constexpr bool @is_default_constructible_v@ = is_default_constructible<T>::value;
  template<class T>
    constexpr bool @is_copy_constructible_v@ = is_copy_constructible<T>::value;
  template<class T>
    constexpr bool @is_move_constructible_v@ = is_move_constructible<T>::value;
  template<class T, class U>
    constexpr bool @is_assignable_v@ = is_assignable<T, U>::value;
  template<class T>
    constexpr bool @is_copy_assignable_v@ = is_copy_assignable<T>::value;
  template<class T>
    constexpr bool @is_move_assignable_v@ = is_move_assignable<T>::value;
  template<class T, class U>
    constexpr bool @is_swappable_with_v@ = is_swappable_with<T, U>::value;
  template<class T>
    constexpr bool @is_swappable_v@ = is_swappable<T>::value;
  template<class T>
    constexpr bool @is_destructible_v@ = is_destructible<T>::value;
  template<class T, class... Args>
    constexpr bool is_trivially_constructible_v
      = is_trivially_constructible<T, Args...>::value;
  template<class T>
    constexpr bool is_trivially_default_constructible_v
      = is_trivially_default_constructible<T>::value;
  template<class T>
    constexpr bool is_trivially_copy_constructible_v
      = is_trivially_copy_constructible<T>::value;
  template<class T>
    constexpr bool is_trivially_move_constructible_v
      = is_trivially_move_constructible<T>::value;
  template<class T, class U>
    constexpr bool @is_trivially_assignable_v@ = is_trivially_assignable<T, U>::value;
  template<class T>
    constexpr bool is_trivially_copy_assignable_v
      = is_trivially_copy_assignable<T>::value;
  template<class T>
    constexpr bool is_trivially_move_assignable_v
      = is_trivially_move_assignable<T>::value;
  template<class T>
    constexpr bool @is_trivially_destructible_v@ = is_trivially_destructible<T>::value;
  template<class T, class... Args>
    constexpr bool is_nothrow_constructible_v
      = is_nothrow_constructible<T, Args...>::value;
  template<class T>
    constexpr bool is_nothrow_default_constructible_v
      = is_nothrow_default_constructible<T>::value;
  template<class T>
    constexpr bool is_nothrow_copy_constructible_v
      = is_nothrow_copy_constructible<T>::value;
  template<class T>
    constexpr bool is_nothrow_move_constructible_v
      = is_nothrow_move_constructible<T>::value;
  template<class T, class U>
    constexpr bool @is_nothrow_assignable_v@ = is_nothrow_assignable<T, U>::value;
  template<class T>
    constexpr bool @is_nothrow_copy_assignable_v@ = is_nothrow_copy_assignable<T>::value;
  template<class T>
    constexpr bool @is_nothrow_move_assignable_v@ = is_nothrow_move_assignable<T>::value;
  template<class T, class U>
    constexpr bool @is_nothrow_swappable_with_v@ = is_nothrow_swappable_with<T, U>::value;
  template<class T>
    constexpr bool @is_nothrow_swappable_v@ = is_nothrow_swappable<T>::value;
  template<class T>
    constexpr bool @is_nothrow_destructible_v@ = is_nothrow_destructible<T>::value;
  template<class T>
    constexpr bool @is_implicit_lifetime_v@ = is_implicit_lifetime<T>::value;
  template<class T>
    constexpr bool @has_virtual_destructor_v@ = has_virtual_destructor<T>::value;
  template<class T>
    constexpr bool has_unique_object_representations_v
      = has_unique_object_representations<T>::value;
  template<class T, class U>
    constexpr bool @reference_constructs_from_temporary_v@
      = reference_constructs_from_temporary<T, U>::value;
  template<class T, class U>
    constexpr bool @reference_converts_from_temporary_v@
      = reference_converts_from_temporary<T, U>::value;

  // meta.unary.prop.query, type property queries
  template<class T>
    constexpr size_t @alignment_of_v@ = alignment_of<T>::value;
  template<class T>
    constexpr size_t @rank_v@ = rank<T>::value;
  template<class T, unsigned I = 0>
    constexpr size_t @extent_v@ = extent<T, I>::value;

  // meta.rel, type relations
  template<class T, class U>
    constexpr bool @is_same_v@ = is_same<T, U>::value;
  template<class Base, class Derived>
    constexpr bool @is_base_of_v@ = is_base_of<Base, Derived>::value;
  template<class From, class To>
    constexpr bool @is_convertible_v@ = is_convertible<From, To>::value;
  template<class From, class To>
    constexpr bool @is_nothrow_convertible_v@ = is_nothrow_convertible<From, To>::value;
  template<class T, class U>
    constexpr bool @is_layout_compatible_v@ = is_layout_compatible<T, U>::value;
  template<class Base, class Derived>
    constexpr bool is_pointer_interconvertible_base_of_v
      = is_pointer_interconvertible_base_of<Base, Derived>::value;
  template<class Fn, class... ArgTypes>
    constexpr bool @is_invocable_v@ = is_invocable<Fn, ArgTypes...>::value;
  template<class R, class Fn, class... ArgTypes>
    constexpr bool @is_invocable_r_v@ = is_invocable_r<R, Fn, ArgTypes...>::value;
  template<class Fn, class... ArgTypes>
    constexpr bool @is_nothrow_invocable_v@ = is_nothrow_invocable<Fn, ArgTypes...>::value;
  template<class R, class Fn, class... ArgTypes>
    constexpr bool is_nothrow_invocable_r_v
      = is_nothrow_invocable_r<R, Fn, ArgTypes...>::value;

  // meta.logical, logical operator traits
  template<class... B>
    constexpr bool @conjunction_v@ = conjunction<B...>::value;
  template<class... B>
    constexpr bool @disjunction_v@ = disjunction<B...>::value;
  template<class B>
    constexpr bool @negation_v@ = negation<B>::value;

  // meta.member, member relationships
  template<class S, class M>
    constexpr bool is_pointer_interconvertible_with_class(M S::*m) noexcept;
  template<class S1, class S2, class M1, class M2>
    constexpr bool is_corresponding_member(M1 S1::*m1, M2 S2::*m2) noexcept;

  // meta.const.eval, constant evaluation context
  constexpr bool is_constant_evaluated() noexcept;
}
