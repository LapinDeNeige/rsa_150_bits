project(pro)
cmake_minimum_required(VERSION 3.8)
add_executable(gen_prm.h  pow_number.cpp rsa_file_crypt.h gen_bits.cpp get_number_bits.cpp  pow_number.h rsa.h gen_bits.h get_number_bits.h rsa.cpp test.cpp gen_prm.cpp rsa_file_crypt.cpp)
include_directories(/usr/include/gmpxx.h)
target_link_libraries(
"/usr/lib/x86_64-linux-gnu/libgmpxx.a"
)
