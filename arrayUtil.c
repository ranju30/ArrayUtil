#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

ArrayUtil create(int typeSize,int length){
  ArrayUtil array;
  array.base = calloc(length,typeSize);
  array.typeSize = typeSize;
  array.length = length;
  return array;
};

int areEqual(ArrayUtil a, ArrayUtil b){
  if(a.length == b.length && a.typeSize == b.typeSize)
    return 1;
  return 0;
};

ArrayUtil resize(ArrayUtil arr,int length){
  ArrayUtil newArray = arr;
  newArray.base = (ArrayUtil *)realloc(arr.base,length);
  newArray.length = length;
  return newArray;
};

int findIndex(ArrayUtil arr, void *element){
  char *ptr = (char *)arr.base;
  int res,typeSize = arr.typeSize;
  for (int i = 0; i < arr.length; i++) {
      res = memcmp(ptr ,element , typeSize);
      if(res == 0)
          return i;
      ptr += typeSize;
  }
  return -1;
};
