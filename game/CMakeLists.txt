maiden_project(game 1 CXX)
set(target stsm-game)
maiden_library(${target} src)
qt5_use_modules(${target} Core)
target_link_libraries(${target} stsm-util)

target_compile_features(${target} PUBLIC
  cxx_override
  cxx_strong_enums
  cxx_static_assert
  cxx_rvalue_references
  cxx_override
  cxx_range_for
  cxx_nullptr
  cxx_nonstatic_member_init
  cxx_lambdas
  cxx_deleted_functions
  cxx_defaulted_functions
)
