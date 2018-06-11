/*
 * Created by Daniel Reznikov on 6/9/18.
 */

#include "Median.h"

void Median::add(int value) {
  int prev, next, idx = 0;

  // Special case when inserting into an empty structure.
  if (data.empty()) {
    data.insert(data.begin(), value);
    median = value;
    return;
  }

  // Insert value into backing set structure.
  for (set<int>::const_iterator iterator = data.begin(), end = data.end(); iterator != end; iterator++) {

    // Prev/Next used to identify the candidate median values in place.
    if (idx == max(int((data.size() / 2) - 1), 0))
      prev = *iterator;
    else if (idx == data.size() / 2)
      next = *iterator;

    idx++;

    if (value < *iterator) {
      data.insert(iterator, value);

      if (*iterator == median) {
        // handles small list where prev == median -> insert 3 into [5, 7]
        prev = value;
      } else if (*iterator == next) {
        // handles insertion of middle key -> insert 5 into [1, 7]
        next = value;
      }

      break;
    }

    // Insertion at the end of the list.
    else if (idx == data.size()) {
      data.insert(end, value);
      break;
    }
  }

  // Update the median value in place.
  if (idx <= data.size() / 2 and data.size() % 2 == 0) {
    // Inserting into first half with even occupancy.
    median = prev;
  } else if (idx > data.size() / 2 and data.size() % 2 != 0) {
    // Inserting into second half with odd occupancy.
    median = next;
  }
}

int Median::getMedian() {
  if (data.empty())
    throw "Empty structure has no median value!";

  return median;
}


