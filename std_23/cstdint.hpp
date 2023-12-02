// all freestanding
namespace std {
  using int8_t         = @\textit{signed integer type}@;   // optional
  using int16_t        = @\textit{signed integer type}@;   // optional
  using int32_t        = @\textit{signed integer type}@;   // optional
  using int64_t        = @\textit{signed integer type}@;   // optional
  using int@N@_t         = @\seebelow@;             // optional

  using int_fast8_t    = @\textit{signed integer type}@;
  using int_fast16_t   = @\textit{signed integer type}@;
  using int_fast32_t   = @\textit{signed integer type}@;
  using int_fast64_t   = @\textit{signed integer type}@;
  using int_fast@N@_t    = @\seebelow@;             // optional

  using int_least8_t   = @\textit{signed integer type}@;
  using int_least16_t  = @\textit{signed integer type}@;
  using int_least32_t  = @\textit{signed integer type}@;
  using int_least64_t  = @\textit{signed integer type}@;
  using int_least@N@_t   = @\seebelow@;             // optional

  using intmax_t       = @\textit{signed integer type}@;
  using intptr_t       = @\textit{signed integer type}@;   // optional

  using uint8_t        = @\textit{unsigned integer type}@; // optional
  using uint16_t       = @\textit{unsigned integer type}@; // optional
  using uint32_t       = @\textit{unsigned integer type}@; // optional
  using uint64_t       = @\textit{unsigned integer type}@; // optional
  using uint@N@_t        = @\seebelow@;             // optional

  using uint_fast8_t   = @\textit{unsigned integer type}@;
  using uint_fast16_t  = @\textit{unsigned integer type}@;
  using uint_fast32_t  = @\textit{unsigned integer type}@;
  using uint_fast64_t  = @\textit{unsigned integer type}@;
  using uint_fast@N@_t   = @\seebelow@;             // optional

  using uint_least8_t  = @\textit{unsigned integer type}@;
  using uint_least16_t = @\textit{unsigned integer type}@;
  using uint_least32_t = @\textit{unsigned integer type}@;
  using uint_least64_t = @\textit{unsigned integer type}@;
  using uint_least@N@_t  = @\seebelow@;             // optional

  using uintmax_t      = @\textit{unsigned integer type}@;
  using uintptr_t      = @\textit{unsigned integer type}@; // optional
}

#define INT@N@_MIN         @\seebelow@
#define INT@N@_MAX         @\seebelow@
#define UINT@N@_MAX        @\seebelow@

#define INT_FAST@N@_MIN    @\seebelow@
#define INT_FAST@N@_MAX    @\seebelow@
#define UINT_FAST@N@_MAX   @\seebelow@

#define INT_LEAST@N@_MIN   @\seebelow@
#define INT_LEAST@N@_MAX   @\seebelow@
#define UINT_LEAST@N@_MAX  @\seebelow@

#define INTMAX_MIN       @\seebelow@
#define INTMAX_MAX       @\seebelow@
#define UINTMAX_MAX      @\seebelow@

#define INTPTR_MIN       @\seebelow@              // optional
#define INTPTR_MAX       @\seebelow@              // optional
#define UINTPTR_MAX      @\seebelow@              // optional

#define PTRDIFF_MIN      @\seebelow@
#define PTRDIFF_MAX      @\seebelow@
#define SIZE_MAX         @\seebelow@

#define SIG_ATOMIC_MIN   @\seebelow@
#define SIG_ATOMIC_MAX   @\seebelow@

#define WCHAR_MIN        @\seebelow@
#define WCHAR_MAX        @\seebelow@

#define WINT_MIN         @\seebelow@
#define WINT_MAX         @\seebelow@

#define INT@N@_C(value)    @\seebelow@
#define UINT@N@_C(value)   @\seebelow@
#define INTMAX_C(value)  @\seebelow@
#define UINTMAX_C(value) @\seebelow@
