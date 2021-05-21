namespace std {
  // concepts.lang, language-related concepts
  // concept.same, concept same_as
  template<class T, class U>
    concept same_as = @\seebelow@;

  // concept.derived, concept derived_from
  template<class Derived, class Base>
    concept derived_from = @\seebelow@;

  // concept.convertible, concept convertible_to
  template<class From, class To>
    concept convertible_to = @\seebelow@;

  // concept.commonref, concept common_reference_with
  template<class T, class U>
    concept common_reference_with = @\seebelow@;

  // concept.common, concept common_with
  template<class T, class U>
    concept common_with = @\seebelow@;

  // concepts.arithmetic, arithmetic concepts
  template<class T>
    concept integral = @\seebelow@;
  template<class T>
    concept signed_integral = @\seebelow@;
  template<class T>
    concept unsigned_integral = @\seebelow@;
  template<class T>
    concept floating_point = @\seebelow@;

  // concept.assignable, concept assignable_from
  template<class LHS, class RHS>
    concept assignable_from = @\seebelow@;

  // concept.swappable, concept swappable
  namespace ranges {
    inline namespace @\unspec@ {
      inline constexpr @\unspec@ swap = @\unspec@;
    }
  }
  template<class T>
    concept swappable = @\seebelow@;
  template<class T, class U>
    concept swappable_with = @\seebelow@;

  // concept.destructible, concept destructible
  template<class T>
    concept destructible = @\seebelow@;

  // concept.constructible, concept constructible_from
  template<class T, class... Args>
    concept constructible_from = @\seebelow@;

  // concept.default.init, concept default_initializable
  template<class T>
    concept default_initializable = @\seebelow@;

  // concept.moveconstructible, concept move_constructible
  template<class T>
    concept move_constructible = @\seebelow@;

  // concept.copyconstructible, concept copy_constructible
  template<class T>
    concept copy_constructible = @\seebelow@;

  // concepts.compare, comparison concepts
  // concept.equalitycomparable, concept equality_comparable
  template<class T>
    concept equality_comparable = @\seebelow@;
  template<class T, class U>
    concept equality_comparable_with = @\seebelow@;

  // concept.totallyordered, concept totally_ordered
  template<class T>
    concept totally_ordered = @\seebelow@;
  template<class T, class U>
    concept totally_ordered_with = @\seebelow@;

  // concepts.object, object concepts
  template<class T>
    concept movable = @\seebelow@;
  template<class T>
    concept copyable = @\seebelow@;
  template<class T>
    concept semiregular = @\seebelow@;
  template<class T>
    concept regular = @\seebelow@;

  // concepts.callable, callable concepts
  // concept.invocable, concept invocable
  template<class F, class... Args>
    concept invocable = @\seebelow@;

  // concept.regularinvocable, concept regular_invocable
  template<class F, class... Args>
    concept regular_invocable = @\seebelow@;

  // concept.predicate, concept predicate
  template<class F, class... Args>
    concept predicate = @\seebelow@;

  // concept.relation, concept relation
  template<class R, class T, class U>
    concept relation = @\seebelow@;

  // concept.equiv, concept equivalence_relation
  template<class R, class T, class U>
    concept equivalence_relation = @\seebelow@;

  // concept.strictweakorder, concept strict_weak_order
  template<class R, class T, class U>
    concept strict_weak_order = @\seebelow@;
}
