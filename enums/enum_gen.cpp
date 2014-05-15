#include <iostream>

int main() {
  while(true) {
    std::string name, enum_name;
    std::cin >> name >> enum_name;
    enum_name.pop_back();
    std::cout << "#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_" + enum_name + ")\n";
    std::cout << "  " + name + " = GL_" + enum_name + "," << std::endl;
    std::cout << "#endif" << std::endl;
  }
}
