namespace std {
  template<ptrdiff_t least_max_value = @\impdef@>
    class counting_semaphore;

  using binary_semaphore = counting_semaphore<1>;
}
