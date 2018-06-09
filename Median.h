//
// Created by Daniel Reznikov on 6/9/18.
//

#ifndef MEDIAN_DATA_STRUCTURE_MEDIAN_H
#define MEDIAN_DATA_STRUCTURE_MEDIAN_H

#include <iostream>
#include <list>
#include "catch.hpp"

class Median
{
  private:
    std::list<int> data;
    int median;


  public:
    Median();

    int getMedian();

    void add(int value);
};

#endif //MEDIAN_DATA_STRUCTURE_MEDIAN_H


