namespace std {
  #if defined(__STDCPP_FLOAT16_T__)
    using float16_t  = @\UNSP{\impldef{type of std::float16_t}}@;  // see basic.extended.fp
  #endif
  #if defined(__STDCPP_FLOAT32_T__)
    using float32_t  = @\UNSP{\impldef{type of std::float32_t}}@;  // see basic.extended.fp
  #endif
  #if defined(__STDCPP_FLOAT64_T__)
    using float64_t  = @\UNSP{\impldef{type of std::float64_t}}@;  // see basic.extended.fp
  #endif
  #if defined(__STDCPP_FLOAT128_T__)
    using float128_t = @\UNSP{\impldef{type of std::float128_t}}@; // see basic.extended.fp
  #endif
  #if defined(__STDCPP_BFLOAT16_T__)
    using bfloat16_t = @\UNSP{\impldef{type of std::bfloat16_t}}@; // see basic.extended.fp
  #endif
}
