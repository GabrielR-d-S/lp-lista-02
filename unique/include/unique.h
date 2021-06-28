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
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
  auto reverse_last = first - 1;
  auto new_last = last;

  while (first < last)
  {
    auto aux_iterator = first - 1;
    while (aux_iterator > reverse_last)
    {
      if (eq(*first, *aux_iterator))
      {
        aux_iterator = first;
        new_last = last - 1;
        while (aux_iterator < new_last)
        {
          *aux_iterator = *(aux_iterator + 1);
          aux_iterator++;
        }
        last = new_last;
        break;
      }
      aux_iterator--;
    }
    first++;
  }
  return new_last;
}

}
#endif
