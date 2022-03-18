set(target slow_browser)

add_library(${target}
##### common #####
    common/types.h
)

target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${target} m)