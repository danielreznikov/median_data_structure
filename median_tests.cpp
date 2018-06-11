/*
 * Created by Daniel Reznikov on 6/9/18.
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Median.h"

TEST_CASE("Empty List")
{
  Median median = Median();
  CHECK_THROWS(median.getMedian());
}

TEST_CASE("Forward Insertion Test")
{
  Median median = Median();

  median.add(5);
  REQUIRE( median.getMedian() == 5 );

  median.add(7);
  REQUIRE( median.getMedian() == 5 );

  median.add(9);
  REQUIRE( median.getMedian() == 7 );

  median.add(11);
  REQUIRE( median.getMedian() == 7 );

  median.add(12);
  REQUIRE( median.getMedian() == 9 );
}

TEST_CASE("Backward Insertion Test")
{
  Median median = Median();

  median.add(12);
  REQUIRE( median.getMedian() == 12 );

  median.add(11);
  REQUIRE( median.getMedian() == 11 );

  median.add(9);
  REQUIRE( median.getMedian() == 11 );

  median.add(7);
  REQUIRE( median.getMedian() == 9 );

  median.add(5);
  REQUIRE( median.getMedian() == 9 );
}

TEST_CASE("Middle Key Insertion Test")
{
  Median median = Median();

  median.add(1);
  median.add(7);
  median.add(5);

  REQUIRE( median.getMedian() == 5 );
}

TEST_CASE("Negative Numbers Test")
{
  Median median = Median();

  for (int i=-5; i<6; ++i)
    median.add(i);

  REQUIRE( median.getMedian() == 0 );
}

TEST_CASE("Random Insertion Test")
{
  Median median = Median();

// Generate random permutation of ints in range [1,100].
  vector<int> vec;
  for (int i=1; i<101; ++i) vec.push_back(i);
  random_shuffle ( vec.begin(), vec.end() );

// Insert random value into median structure.
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    median.add(*it);

  REQUIRE( median.getMedian() == 50 );
}


