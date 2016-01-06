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

void return_0_if_two_array_size_are_equal_but_value_diff(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = create(4,6);
  int *a1 = a.base;
  int *a2 = b.base;
  a1[0]= 3;
  a1[1]= 13;
  a2[0]= 17;
  a2[1]= 7;
  assert(areEqual(a,b) == 0);
};

void return_0_if_two_array_are_equal_for_diff_typrSize_but_value_same(){
  ArrayUtil a = create(17,6);
  ArrayUtil b = create(19,6);
  assert(areEqual(a,b) == 0);
};

void return_1_if_two_array_are_equal_and_value_same(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = create(4,6);
  assert(areEqual(a,b) == 1);
};

void return_1_if_two_array_are_equal_and_value_same_and_element_also(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = create(4,6);
  int *a1 = a.base;
  int *a2 = b.base;
  a1[0]= 3;
  a1[1]= 13;
  a2[0]= 3;
  a2[1]= 13;
  assert(areEqual(a,b) == 1);
};

void check_wheather_an_array_is_being_resized(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = resize(a,10);
  assert(b.length == 10);
  assert(b.typeSize == 4);
};

void return_negative_1_if_the_element_is_not_present(){
  ArrayUtil a = create(4,6);
  int *ptr = (int *)a.base;
  ptr[0]= 5;
  ptr[1]= 6;
  ptr[2]= 7;
  ptr[3]= 8;
  ptr[4]= 9;
  int x = 11;
  assert(findIndex(a,&x) == -1);
};

void return_index_if_the_element_is_present(){
  ArrayUtil a = create(4,6);
  int *ptr = (int *)a.base;
  ptr[0]= 5;
  ptr[1]= 6;
  ptr[2]= 7;
  ptr[3]= 8;
  ptr[4]= 9;
  int x = 7;
  assert(findIndex(a,&x) == 2);
};

int main(int argc, char const *argv[]) {
  check_array_is_creating_with_length_5_and_typesize_4();
  return_0_if_two_array_are_not_equal();
  return_0_if_two_array_size_are_equal_but_value_diff();
  return_0_if_two_array_are_equal_for_diff_typrSize_but_value_same();
  return_1_if_two_array_are_equal_and_value_same();
  return_1_if_two_array_are_equal_and_value_same_and_element_also();
  check_wheather_an_array_is_being_resized();
  return_negative_1_if_the_element_is_not_present();
  return_index_if_the_element_is_present();
  printf("All test passed\n");
  return 0;
}
