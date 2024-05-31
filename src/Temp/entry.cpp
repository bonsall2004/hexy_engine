#include <iostream>
#include "WindowHandler/WindowHandler.hpp"

int main()
{
  hexy::WindowManager window_manager(800, 600, "Hexy Engine", true, true);
  window_manager.Begin();
  return 0;
}
