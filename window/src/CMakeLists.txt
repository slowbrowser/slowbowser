set(sources
    sb_window.c
    sb_window.h
)

set(libname sb_window)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(lflags
        "-framework Foundation"
        "-framework Cocoa"
        "-framework Metal"
        "-framework CoreAudio"
        "-framework CoreVideo"
        "-framework CoreServices"
        "-framework GameController"
        "-framework ForceFeedback"
        "-framework IOKit"
        "-framework AudioToolbox"
        "-framework AVFoundation"
        "-framework Carbon"
    )
endif()

add_library(${libname}
    STATIC
        ${sources}
)

target_include_directories(${libname}
	PRIVATE
		${CMAKE_SOURCE_DIR}/3rdparties/macos/sdl/include/
)

target_link_libraries(${libname}
    PRIVATE
        iconv
        ${CMAKE_SOURCE_DIR}/3rdparties/macos/sdl/libSDL2.a
        ${lflags}
)

target_include_directories(${libname}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
