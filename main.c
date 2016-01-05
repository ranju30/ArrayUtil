#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void check_array_is_creating_with_length_5_and_typesize_4(){
  ArrayUtil firstArr = create(4,5);
  assert(firstArr.length == 5);
  assert(firstArr.typeSize == 4);
};

void return_0_if_two_array_are_not_equal(){
  ArrayUtil a = create(5,6);
  ArrayUtil b = create(6,7);
  assert(areEqual(a,b) == 0);
};

void return_1_if_two_array_are_equal(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = create(4,6);
  assert(areEqual(a,b) == 1);
};

void check_wheather_an_array_is_being_resized(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = resize(a,10);
  assert(b.length == 10);
  assert(b.typeSize == 4);
};

int main(int argc, char const *argv[]) {
  check_array_is_creating_with_length_5_and_typesize_4();
  return_0_if_two_array_are_not_equal();
  return_1_if_two_array_are_equal();
  check_wheather_an_array_is_being_resized();
  printf("All test passed\n");
  return 0;
}
