#include <stdio.h>
#include <GLFW/glfw3.h>
#include <format>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui.h"

void mainLoop(GLFWwindow *window);

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_DECORATED, false);


    GLFWwindow *window = glfwCreateWindow(720, 480, "Hello World", NULL, NULL); // Create a window
    if (window == NULL) {
        fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // Make the window's context current


    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    while (!glfwWindowShouldClose(window)) { // Loop until the user closes the window
        glfwPollEvents(); // Poll for and process events
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
//        ImGui::ShowDemoWindow();

        mainLoop(window);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();


    return 0;
}

void mainLoop(GLFWwindow *window) {
    using namespace ImGui;
    SetNextWindowSize(ImVec2(200, 200), ImGuiCond_FirstUseEver);

    PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.5f, 0.2f));
    Begin("Window", nullptr, ImGuiWindowFlags_NoTitleBar);
    PopStyleColor();


    PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.0f, 1.0f));
    for (int i = 0; i < 100; i++) {
        PushID(i);
        Button(std::format("Click: {}", i).c_str());
        PopID();
    }
    PopStyleColor();
    End();

    Begin("Window2", nullptr);
    if (TreeNode("TreeNode")) {
        if (Button("Button"))
            printf("Button pressed\n");

        if (Button("Button2"))
            printf("Button2 pressed\n");

        TreePop();
    }

    End();

}