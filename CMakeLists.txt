cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Playground)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)

# loading glfw
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        latest
        GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(glfw)

# loading ImGUI
include_directories(imgui)
include_directories(imgui/backends)


add_executable(Playground main.cpp
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp

        )


# linking dx9 and windows
# using FreeConsole() to hide console, so we need to link windows library
target_link_libraries(Playground glfw opengl32)

set_target_properties(Playground PROPERTIES
        LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
