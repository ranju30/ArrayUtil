#include <stdio.h>
#include <stdlib.h>
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
