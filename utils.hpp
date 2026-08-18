#include <ostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& lhs, const std::vector<T>& rhs)
{
  typename std::vector<T>::const_iterator it;
  lhs << '[';
  for (it = rhs.begin(); it != rhs.end(); ++it){
    if (it != rhs.begin())
      lhs << ", ";
    lhs << *it;
  }
  lhs << ']';
  return lhs;
}

namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
}