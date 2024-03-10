project(obuchaika_v2)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${TEXT_LIB_NAME})

add_subdirectory(src)
add_subdirectory(test)
