#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_to_create_array(){
  ArrayUtil firstArr = create(4,5);
  assert(firstArr.length == 5);
  assert(firstArr.typeSize == 4);
};

void test_areEqual_and_return_0_if_not(){
  ArrayUtil a = create(5,6);
  ArrayUtil b = create(6,7);
  assert(areEqual(a,b) == 0);
};

void test_areEqual_and_return_0_if_equal_but_value_not(){
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

void test_areEqual_and_return_0_if_not_but_value_same(){
  ArrayUtil a = create(17,6);
  ArrayUtil b = create(19,6);
  int *a1 = a.base;
  int *a2 = b.base;
  a1[0]= 3;
  a1[1]= 13;
  a2[0]= 3;
  a2[1]= 13;
  assert(areEqual(a,b) == 0);
};

void test_areEqual_and_return_1_if_same(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = create(4,6);
  assert(areEqual(a,b) == 1);
};

void test_areEqual_and_return_1_if_value_same_and_element_also(){
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

void test_to_resize_a_created_array(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = resize(a,10);
  assert(b.length == 10);
  assert(b.typeSize == 4);
};

void test_findIndex_returns_neg_1_if_element_is_not_present(){
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

void test_findIndex_returns_index_if_element_is_present(){
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

int isEven(void* hint, void* item){
  if(*((int *)item) % *((int *)hint) == 0){
    return 1;
  };
  return 0;
};

void test_findFirst_return_element_if_match_found(){
  ArrayUtil a = create(4,6);
  int *ptr = (int *)(a.base);
  ptr[0] = 5;
  ptr[1] = 6;
  ptr[2] = 7;
  ptr[3] = 8;
  ptr[4] = 9;
  int hint = 2;
  int * res = (int *)findFirst(a,&isEven,&hint);
  assert(*res == 6);
};

void test_findLast_return_element_if_match_found(){
  ArrayUtil a = create(4,6);
  int *ptr = (int *)(a.base);
  ptr[0] = 5;
  ptr[1] = 6;
  ptr[2] = 7;
  ptr[3] = 8;
  ptr[4] = 9;
  ptr[5] = 11;
  int hint = 2;
  int * res = (int *)findLast(a,&isEven,&hint);
  assert(*res == 8);
};

void test_count_countes_no_of_values_match_with_hint(){
  ArrayUtil a = create(4,6);
  int *ptr = (int *)(a.base);
  ptr[0] = 5;
  ptr[1] = 6;
  ptr[2] = 7;
  ptr[3] = 8;
  ptr[4] = 9;
  ptr[5] = 12;
  int hint = 2;
  int res = count(a,&isEven,&hint);
  assert(res == 3);
};

void test_filter_insert_address_of_the_value_which_match_condition(){
  ArrayUtil a = create(4,6);
  int *ptr = (int *)(a.base);
  ptr[0] = 5;
  ptr[1] = 6;
  ptr[2] = 7;
  ptr[3] = 8;
  ptr[4] = 9;
  ptr[5] = 12;
  int hint = 2;
  ArrayUtil dest = create(4,6);
  int maxLength = 6;
  int res = filter(a,&isEven,&hint,dest.base,maxLength);
  assert(res == 3);
};

int main(int argc, char const *argv[]) {
  test_filter_insert_address_of_the_value_which_match_condition();
  printf("Passing\n");
  return 0;
}
