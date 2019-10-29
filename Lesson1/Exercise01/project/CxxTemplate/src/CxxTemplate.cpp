
#include "CxxTemplate.h"

#include <string>
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;

namespace cxxt {

CxxApplication::CxxApplication( int argc, char *argv[] ) {
  std::cout << "Hello CMake." << std::endl;
}

CxxApplication::~CxxApplication() {
  // TODO cleanup
}

} // namespace cxxt


int main( int argc, char *argv[] ) {
  cxxt::CxxApplication app( argc, argv );

  return 0;
}
