add_library(bitseti bitseti.h bitseti.cpp)

add_executable(bitseti_test bitseti_test.cpp)
target_link_libraries(bitseti_test bitseti)