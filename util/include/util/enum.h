#ifndef UTIL_ENUM_H_INCLUDED
#define UTIL_ENUM_H_INCLUDED

/**
*** variadic versions:
        UTIL_ENUM( name, ... )
*** sequence version
        UTIL_ENUM_FROM_SEQ( name, seq_define )
**/

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#include <array>
#include <map>

#define my_enum_s (val1)(val2)(val3)

#define UTIL_seq_gen_ec(r, data, elem) elem,
#define UTIL_seq_gen_scoped_elem(r, data, elem) data::elem,
#define UTIL_seq_gen_enum_pair(r, data, elem)                                  \
  { data::elem, BOOST_PP_STRINGIZE(elem) }
#define UTIL_seq_gen_enum_pair_c(r, data, elem)                                \
  UTIL_seq_gen_enum_pair(r, data, elem),
#define UTIL_eval_call(func, ...) func(__VA_ARGS__)

#define UTIL_REPEAT_NSPECIAL_internal(count_minus1, macro, macro_last, data)   \
  BOOST_PP_REPEAT(count_minus1, macro, data)                                   \
  UTIL_eval_call(macro_last, count_minus1, count_minus1, data)
#define UTIL_REPEAT_NSPECIAL(count, macro, macro_last, data)                   \
  UTIL_REPEAT_NSPECIAL_internal(BOOST_PP_SUB(count, 1), macro, macro_last, data)

#define UTIL_ENUM_FROM_SEQ(name, seq)                                          \
  enum class name { BOOST_PP_SEQ_FOR_EACH(UTIL_seq_gen_ec, _, seq) };          \
  const std::map<name, const char *> name##_map = {                            \
      BOOST_PP_SEQ_FOR_EACH(UTIL_seq_gen_enum_pair_c, name, seq)};             \
  const std::array<name, BOOST_PP_SEQ_SIZE(seq)> name##_array = {              \
      BOOST_PP_SEQ_FOR_EACH(UTIL_seq_gen_scoped_elem, name, seq)};

#define UTIL_ENUM(name, ...)                                                   \
  UTIL_ENUM_FROM_SEQ(name, BOOST_PP_TUPLE_TO_SEQ((__VA_ARGS__)))

#endif /* end of include guard: UTIL_ENUM_H_INCLUDED */
