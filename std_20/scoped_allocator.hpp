namespace std {
  // class template \tcode{scoped allocator adaptor}
  template<class OuterAlloc, class... InnerAlloc>
    class scoped_allocator_adaptor;

  // scoped.adaptor.operators, scoped allocator operators
  template<class OuterA1, class OuterA2, class... InnerAllocs>
    bool operator==(const scoped_allocator_adaptor<OuterA1, InnerAllocs...>& a,
                    const scoped_allocator_adaptor<OuterA2, InnerAllocs...>& b) noexcept;
}
