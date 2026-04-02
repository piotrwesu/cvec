set(SRC_FILES test.c
                "${CMAKE_SOURCE_DIR}/source/cvec.c")

set(TESTPROJECT "cvec_test")
add_executable(${TESTPROJECT} ${SRC_FILES})

target_link_libraries(${TESTPROJECT} PRIVATE cvec)

set_property(TARGET ${TESTPROJECT} PROPERTY OUTPUT_NAME "test")
