cmake_minimum_required(VERSION 3.10)
project(turbo-lamp CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(add_solution strategy lang feature)
  set(name ${strategy}_${lang})
  add_executable(${name} main.cc)
  target_include_directories(${name} PUBLIC ${lang}/${strategy})
  target_compile_features(${name} PUBLIC ${feature})
endfunction()

function(add_concepts_solution strategy)
  set(name ${strategy}_concepts)
  if(${CMAKE_CXX_COMPILER_ID} STREQUAL AppleClang)
    message(WARNING "AppleClang detected. Skipping target \"${name}\" because "
                    "it requires concepts support")
    return()
  endif()
  add_solution(${strategy} concepts cxx_std_20)
  if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    target_compile_options(${name} PUBLIC -fconcepts)
  endif()
endfunction()

add_concepts_solution(derived_from)
add_concepts_solution(has_memfn)

function(add_if_constexpr_solution strategy)
  add_solution(${strategy} if_constexpr cxx_std_17)
endfunction()

add_if_constexpr_solution(derived_from)
add_if_constexpr_solution(has_memfn)

function(add_decltype_void_solution strategy)
  add_solution(${strategy} decltype_void cxx_variable_templates)
endfunction()

add_decltype_void_solution(derived_from)
add_decltype_void_solution(has_memfn)
