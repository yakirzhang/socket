#include <circleBuf.h>
#include <iostream>
#include <glog/logging.h>
using  namespace std;
int main(int ) {
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InstallFailureSignalHandler();
  std::cout << "Hello, World!" << std::endl;
  return 0;
}