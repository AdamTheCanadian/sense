#include <iostream>
#include "vis/display.h"

int main() {
  vis::Display display("My Window", 800, 600);
  while (!display.Shutdown()) {
    
    ImGui::ShowDemoWindow(nullptr);
    ImPlot::ShowDemoWindow(nullptr);
    display.Update();
  }
}