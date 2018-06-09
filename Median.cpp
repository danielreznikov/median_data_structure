//
// Created by Daniel Reznikov on 6/9/18.
//

#define CATCH_CONFIG_MAIN
#include "Median.h"

Median::Median() {
  //median = NULL;
  //data = new std::list<int>();
}

void Median::add(int value) {

  if (data.empty())
    data.insert(data.begin(), value);

  int idx = 0;
  for (std::list<int>::const_iterator iterator = data.begin(), end = data.end(); iterator != end; ++iterator) {

    int prev, next;
    if (idx == data.size()/2 - 1)
      prev = *iterator;
    else if (idx == data.size()/2 + 1)
      next = *iterator;

    if (value < *iterator) {
      // Inserting into first half with even occupancy.
      if (idx < data.size() / 2 and data.size() % 2 == 0)
        data.insert(iterator, value);

      // Inserting into first half with odd occupancy.
      else if (idx < data.size() / 2 and data.size() % 2 != 0) {
        data.insert(iterator, value);
        median = prev;
      }

      // Inserting into second half with even occupancy.
      else if (idx >= data.size()/2 and data.size() % 2 == 0) {
        data.insert(iterator, value);
        median = next;
      }

      // Inserting into second half with odd occupancy.
      else if (idx >= data.size()/2 and data.size() % 2 != 0)
        data.insert(iterator, value);
    }
  }
}

int Median::getMedian() {
  return median;
}

/*int main() {
  Median median = Median();

  std::cout << "Median Value is " << median.getMedian() << std::endl;

  median.add(1);
  std::cout << "Median Value is " << median.getMedian() << std::endl;;

  median.add(3);
  std::cout << "Median Value is " << median.getMedian() << std::endl;
}
 */

TEST_CASE( "Empty List", "Prove that one equals 2" )
{
  int one = 2;
  REQUIRE( one == 3 );
}