/** author: Merlin Schindlbeck */
#ifndef UTIL_ENUM_H_INCLUDED
#define UTIL_ENUM_H_INCLUDED

/**
*** variadic versions:
        DEF_ENUM_IN_CLASS( name, ... )
        DEF_ENUM_IN_NS( name, ... )
        DEF_N4428( name, ... )

*** sequence version
        DEF_ENUM_SEQUENCE(...)
        DEF_ENUM_IN_NS_CLASS_S( name, seq_define )
        DEF_ENUM_IN_NS_S( name, seq_define )
        DEF_N4428_S( name, seq_define )
**/

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/punctuation/comma.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/pop_back.hpp>
#include <boost/preprocessor/seq/reverse.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#include <array>
#include <map>

#ifndef ENUM_N4428_NS
#define ENUM_N4428_NS std
#endif
namespace ENUM_N4428_NS {
template <class Enum> struct enum_traits {
  struct enumerators { /*
     static constexpr size_t const size;
     template <size_t I> struct get {
       static constexpr char const * const  identifier;
       static constexpr Enum const value; };*/
  };
};
}

#define Us_scoped_elem(r, data, elem) data::elem
#define Us_scoped_elem_c(r, data, elem) data::elem,
#define Us_enum_pair(r, data, elem)                                            \
  { data::elem, BOOST_PP_STRINGIZE(elem) }
#define Us_enum_pair_c(r, data, elem) Us_enum_pair(r, data, elem),
#define Us_traits_enumerator_get(r, data, elem)                                \
  template <>                                                                  \
  template <>                                                                  \
  struct enum_traits<data>::enumerators::get<BOOST_PP_SUB(r, 2)> {             \
    static constexpr char const *const identifier = BOOST_PP_STRINGIZE(elem);  \
    static constexpr const data value = data::elem;                            \
  };

#define Us_back(seq) BOOST_PP_SEQ_HEAD(BOOST_PP_SEQ_REVERSE(seq))

#define Us_foreach_lastspecial(seq, data, macro, macro_last)                   \
  BOOST_PP_SEQ_FOR_EACH(macro, data, BOOST_PP_SEQ_POP_BACK(seq))               \
  macro_last(0, data, Us_back(seq))

#define U_enum_from_seq_internal(name, seq, count, static)                     \
  enum class name { BOOST_PP_SEQ_ENUM(seq) };                                  \
  const constexpr static std::array<name, count> name##_array = {              \
      Us_foreach_lastspecial(seq, name, Us_scoped_elem_c, Us_scoped_elem)};

#define U_enum_map_from_seq_internal(name, seq, count, static)                 \
  const static std::map<name, const char *> name##_map = {                     \
      Us_foreach_lastspecial(seq, name, Us_enum_pair_c, Us_enum_pair)};

#define DEF_ENUM_IN_NS_S(name, seq)                                            \
  U_enum_from_seq_internal(name, seq, BOOST_PP_SEQ_SIZE(seq),                  \
                           BOOST_PP_EMPTY())                                   \
      U_enum_map_from_seq_internal(name, seq, BOOST_PP_SEQ_SIZE(seq),          \
                                   BOOST_PP_EMPTY())
#define DEF_ENUM_IN_CLASS_S(name, seq)                                         \
  U_enum_from_seq_internal(name, seq, BOOST_PP_SEQ_SIZE(seq), static)

#define DEF_N4428_S(name, seq)                                                 \
  namespace ENUM_N4428_NS {                                                    \
  template <> struct enum_traits<name>::enumerators {                          \
    static const constexpr size_t size = BOOST_PP_SEQ_SIZE(seq);               \
    template <size_t I> struct get {};                                         \
  };                                                                           \
  BOOST_PP_SEQ_FOR_EACH(Us_traits_enumerator_get, name, seq)                   \
  }

#define DEF_ENUM_SEQUENCE BOOST_PP_VARIADIC_TO_SEQ

#define DEF_N4428(name, ...) DEF_N4428_S(name, DEF_ENUM_SEQUENCE(__VA_ARGS__))

#define DEF_ENUM_IN_NS(name, ...)                                              \
  DEF_ENUM_IN_NS_S(name, DEF_ENUM_SEQUENCE(__VA_ARGS__))

#define DEF_ENUM_IN_CLASS(name, ...)                                           \
  DEF_ENUM_IN_CLASS_S(name, DEF_ENUM_SEQUENCE(__VA_ARGS__))

#endif /* end of include guard: UTIL_ENUM_H_INCLUDED */
