set(SRC_FILES test.c
                "${CMAKE_SOURCE_DIR}/source/cvec.c")

add_executable(${PROJECTNAME} ${SRC_FILES})

target_include_directories(${PROJECTNAME} PRIVATE "${CMAKE_SOURCE_DIR}/source")

set_property(TARGET ${PROJECTNAME} PROPERTY OUTPUT_NAME "test")
