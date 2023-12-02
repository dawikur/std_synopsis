namespace std {
  // coro.generator.class, class template generator
  template<class Ref, class V = void, class Allocator = void>
    class generator;

  namespace pmr {
    template<class R, class V = void>
      using generator = std::generator<R, V, polymorphic_allocator<>>;
  }
}
