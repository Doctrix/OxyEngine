# Settings
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/Game/Header)

# Files
FILE(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
FILE(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h *.inl)

ADD_EXECUTABLE(Game ${ENGINE_SOURCES} ${ENGINE_HEADERS} "Rendering/Renderer/I_Window.cpp" "Rendering/Renderer/OpenGL33/C_OpenGL33Window.cpp")
TARGET_LINK_LIBRARIES(Game glfw3 glew32)