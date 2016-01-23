typedef struct {
  void *base;
  int typeSize;
  int length;
} ArrayUtil;

typedef int (MatchFunc) (void* ,void*);
typedef void (ConvertFunc) (void*, void*, void*);
typedef void (OperationFunc) (void* , void* );

ArrayUtil create(int,int);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil,int);
int findIndex(ArrayUtil,void *);
void dispose(ArrayUtil);
void* findFirst(ArrayUtil,MatchFunc* , void*);
void* findLast(ArrayUtil,MatchFunc* , void*);
int count(ArrayUtil, MatchFunc*, void*);
int filter(ArrayUtil, MatchFunc*, void*, void**, int);
void map(ArrayUtil, ArrayUtil, ConvertFunc*, void*);
void forEach(ArrayUtil, OperationFunc*, void*);
