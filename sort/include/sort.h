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
template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
  while (first < last)
  {
    auto aux_iterator = first + 1;
    while (aux_iterator < last)
    {
      if (cmp(*aux_iterator, *first))
      {
        auto temp = *first;
        *first = *aux_iterator;
        *aux_iterator = temp;
      }
      aux_iterator++;
    }
    first++;
  }
}

}
#endif
