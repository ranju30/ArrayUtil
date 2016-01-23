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

void* findFirst(ArrayUtil arr,MatchFunc* match,void* hint){
  void *ptr = arr.base;
  void *notFound = NULL;
  for(int i=0;i<arr.length;i++){
    if(match(hint,ptr) == 1){
      return ptr;
    }
    ptr = ptr + arr.typeSize;
  };
  return notFound;
};

void* findLast(ArrayUtil arr,MatchFunc* match,void* hint){
  void *ptr = arr.base;
  void *value;
  int condition = 0;
  void *notFound = NULL;
  for(int i=0;i<arr.length;i++){
    if(match(hint,ptr) == 1){
      condition = 1;
      value = ptr;
    }
      ptr = ptr + arr.typeSize;
  };
  if(condition == 1){
    return value;
  }
  return notFound;
};

int count(ArrayUtil arr, MatchFunc* match, void* hint){
  void *ptr = arr.base;
  int counter = 0;
  void *notFound = NULL;
  for(int i=0;i<arr.length;i++){
    if(match(hint,ptr) == 1){
      counter++;
    }
      ptr = ptr + arr.typeSize;
  };
  return counter;
};

int filter(ArrayUtil arr, MatchFunc* match, void* hint, void** dest, int size){
  void *ptr = arr.base;
  int counter = 0;
  void *notFound = NULL;
  for(int i=0;i<arr.length;i++){
    if(match(hint,ptr) == 1){
      dest = ptr;
      counter++;
    }
      ptr = ptr + arr.typeSize;
  };
  return counter;
};

void map(ArrayUtil arr, ArrayUtil dest, ConvertFunc* convert, void* hint){
  void *ptr = arr.base;
  void *destAdd = dest.base;
  for(int i=0;i<arr.length;i++){
    convert(hint,ptr,destAdd);
    ptr = ptr + arr.typeSize;
    destAdd = destAdd + dest.typeSize;
  };
};

void forEach(ArrayUtil arr, OperationFunc* op, void* hint){
  void *ptr = arr.base;
  for(int i=0;i<arr.length;i++){
    op(hint,ptr);
  };
};
