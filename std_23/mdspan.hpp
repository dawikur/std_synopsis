namespace std {
  // mdspan.extents, class template extents
  template<class IndexType, size_t... Extents>
    class extents;

  // mdspan.extents.dextents, alias template dextents
  template<class IndexType, size_t Rank>
    using dextents = @\seebelow@;

  // mdspan.layout, layout mapping
  struct layout_left;
  struct layout_right;
  struct layout_stride;

  // mdspan.accessor.default, class template default_accessor
  template<class ElementType>
    class default_accessor;

  // mdspan.mdspan, class template mdspan
  template<class ElementType, class Extents, class LayoutPolicy = layout_right,
           class AccessorPolicy = default_accessor<ElementType>>
    class mdspan;
}
