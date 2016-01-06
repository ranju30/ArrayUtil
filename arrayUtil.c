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
  char *ptr = (char *)a.base;
  char *ptr2 = (char *)b.base;
  if(a.length != b.length || a.typeSize != b.typeSize)
    return 0;
  for(int i=0;i<(a.length*a.typeSize);i++){
    if(ptr[i] != ptr2[i])
      return 0;
  }
  return 1;
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

void dispose(ArrayUtil arr){
  void *ptr = arr.base;
  free(ptr);
};
