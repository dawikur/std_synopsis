namespace std {
  // execpol.type, execution policy type trait
  template<class T> struct is_execution_policy;
  template<class T> constexpr bool @is_execution_policy_v@ = is_execution_policy<T>::value;
}

namespace std::execution {
  // execpol.seq, sequenced execution policy
  class sequenced_policy;

  // execpol.par, parallel execution policy
  class parallel_policy;

  // execpol.parunseq, parallel and unsequenced execution policy
  class parallel_unsequenced_policy;

  // execpol.unseq, unsequenced execution policy
  class unsequenced_policy;

  // execpol.objects, execution policy objects
  inline constexpr sequenced_policy            seq{ @\unspec@ };
  inline constexpr parallel_policy             par{ @\unspec@ };
  inline constexpr parallel_unsequenced_policy par_unseq{ @\unspec@ };
  inline constexpr unsequenced_policy          unseq{ @\unspec@ };
}
