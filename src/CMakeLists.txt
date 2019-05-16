add_library(klondike "")

file(GLOB_RECURSE SOURCES "*.cc")

target_sources(
    klondike
    PRIVATE
        ${SOURCES}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/Number.h
    )

target_include_directories(
    klondike
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
