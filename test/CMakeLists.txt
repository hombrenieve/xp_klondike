
file(GLOB_RECURSE SOURCES_TEST "*.cc")


add_executable(
    unit_tests
    ${SOURCES_TEST}
    )

target_link_libraries(
    unit_tests
    gtest_main
    klondike
    ${GTEST_LIBRARIES}
    ${GMOCK_LIBRARIES}
    pthread
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
