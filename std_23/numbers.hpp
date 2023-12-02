namespace std::numbers {
  template<class T> constexpr T e_v          = @\unspec@;
  template<class T> constexpr T log2e_v      = @\unspec@;
  template<class T> constexpr T log10e_v     = @\unspec@;
  template<class T> constexpr T pi_v         = @\unspec@;
  template<class T> constexpr T inv_pi_v     = @\unspec@;
  template<class T> constexpr T inv_sqrtpi_v = @\unspec@;
  template<class T> constexpr T ln2_v        = @\unspec@;
  template<class T> constexpr T ln10_v       = @\unspec@;
  template<class T> constexpr T sqrt2_v      = @\unspec@;
  template<class T> constexpr T sqrt3_v      = @\unspec@;
  template<class T> constexpr T inv_sqrt3_v  = @\unspec@;
  template<class T> constexpr T egamma_v     = @\unspec@;
  template<class T> constexpr T phi_v        = @\unspec@;

  template<@floating_point@ T> constexpr T e_v<T>          = @\seebelow@;
  template<@floating_point@ T> constexpr T log2e_v<T>      = @\seebelow@;
  template<@floating_point@ T> constexpr T log10e_v<T>     = @\seebelow@;
  template<@floating_point@ T> constexpr T pi_v<T>         = @\seebelow@;
  template<@floating_point@ T> constexpr T inv_pi_v<T>     = @\seebelow@;
  template<@floating_point@ T> constexpr T inv_sqrtpi_v<T> = @\seebelow@;
  template<@floating_point@ T> constexpr T ln2_v<T>        = @\seebelow@;
  template<@floating_point@ T> constexpr T ln10_v<T>       = @\seebelow@;
  template<@floating_point@ T> constexpr T sqrt2_v<T>      = @\seebelow@;
  template<@floating_point@ T> constexpr T sqrt3_v<T>      = @\seebelow@;
  template<@floating_point@ T> constexpr T inv_sqrt3_v<T>  = @\seebelow@;
  template<@floating_point@ T> constexpr T egamma_v<T>     = @\seebelow@;
  template<@floating_point@ T> constexpr T phi_v<T>        = @\seebelow@;

  inline constexpr double e          = e_v<double>;
  inline constexpr double log2e      = log2e_v<double>;
  inline constexpr double log10e     = log10e_v<double>;
  inline constexpr double pi         = pi_v<double>;
  inline constexpr double inv_pi     = inv_pi_v<double>;
  inline constexpr double inv_sqrtpi = inv_sqrtpi_v<double>;
  inline constexpr double ln2        = ln2_v<double>;
  inline constexpr double ln10       = ln10_v<double>;
  inline constexpr double sqrt2      = sqrt2_v<double>;
  inline constexpr double sqrt3      = sqrt3_v<double>;
  inline constexpr double inv_sqrt3  = inv_sqrt3_v<double>;
  inline constexpr double egamma     = egamma_v<double>;
  inline constexpr double phi        = phi_v<double>;
}
