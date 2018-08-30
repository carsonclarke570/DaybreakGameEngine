cmake_minimum_required (VERSION 2.6)
project (Daybreak)

set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/include)
set(GLEW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/lib/glew32s.lib)

set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include)
set(GLFW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/lib/glfw3.lib)
set(GLFW_DIR 

add_compile_definitions(GLEW_STATIC)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

file(GLOB_RECURSE SRCFILES ThunderSurge-core/*.cpp ThunderSurge-core/*.h)

foreach(src ${SRCFILES})
    message(STATUS "${src}")
endforeach()

add_executable(Daybreak ${SRCFILES})

# FreeImage

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/FreeImage/include)
find_library(libs FreeImage ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/FreeImage)
target_link_libraries(Daybreak ${libs})

# tinyobjloader

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/tinyobjloader)

# OpenGL

find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
	target_link_libraries(Daybreak opengl32)
	message(STATUS "Found OpenGL")
else()
	message(STATUS "Failed to find OpenGL")
endif()

# GLEW

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/include)
find_package(GLEW REQUIRED)
if (GLEW_FOUND) 
	link_libraries(Daybreak ${GLEW_LIBRARIES})
	message(STATUS "Found GLEW")
else()
	message(STATUS "Failed to find GLEW")
endif()

# GLFW

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include)
find_package(GLFW REQUIRED)
if (GLFW_FOUND) 
	link_libraries(Daybreak ${GLFW_LIBRARIES})
	message(STATUS "Found GLEW")
else()
	message(STATUS "Failed to find GLEW")
endif()

