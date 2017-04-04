cmake_minimum_required(VERSION 3.6)
project(Perceptron)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp src/sensor.cpp src/sensor.h src/perceptron.cpp src/perceptron.h)
add_executable(Perceptron ${SOURCE_FILES})