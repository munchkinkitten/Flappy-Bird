set(FLAPPY_BIRD_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB FLAPPY_BIRD_SRC "${FLAPPY_BIRD_SOURCES_DIR}/*.cpp")

add_executable(Flappy_bird ${FLAPPY_BIRD_SRC})

target_link_libraries(Flappy_bird sfml-graphics sfml-window sfml-system)
install(TARGETS Flappy_bird DESTINATION "./")
