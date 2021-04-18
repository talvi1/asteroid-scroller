cmake_minimum_required(VERSION 3.10)


project (asteroid_game)

include_directories(src)

file (GLOB SOURCES "src/*.cpp")

add_executable(
    asteroid_game
    ${SOURCES}
)