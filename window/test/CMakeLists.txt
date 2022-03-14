set(sources
    main.c
)

set(exename sb_window_test)

add_executable(${exename}
        ${sources}
)

target_link_libraries(${exename}
    PRIVATE
        sb_window
)