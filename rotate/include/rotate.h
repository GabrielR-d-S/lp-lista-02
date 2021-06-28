#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/*!
 * TODO: documentação no estilo doxygen
 */
template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
  auto original_first = first;
  auto counter = 0;
  while (counter < (last - n_first))
  {
    first = last - 1;
    auto roll_over = *first;
    while (first > original_first)
    {
      *first = *(first - 1);
      first--;
    }
    *first = roll_over;
    counter++;
  }
  return original_first;
}

}
#endif
