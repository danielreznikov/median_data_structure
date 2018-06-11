/*
 * Created by Daniel Reznikov on 6/9/18.
 */

#ifndef MEDIAN_DATA_STRUCTURE_MEDIAN_H
#define MEDIAN_DATA_STRUCTURE_MEDIAN_H

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <set>

using namespace std;

/* A data structure for quickly computing the median of a set of ints. */
class Median
{
  private:
    set<int> data;        /* Backing data store is a std::set */

    int median;           /* Instance variable for fast retrieval of median value */

  public:
    Median() { };         /* A constructor */

    ~Median() { };        /* A destructor */

    int getMedian();      /* Retrieves median value */

    void add(int value);  /* Adds an integer value to the data structure */
};

#endif //MEDIAN_DATA_STRUCTURE_MEDIAN_H


