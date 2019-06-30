#ifndef Exception_H
#define Exception_H

typedef struct Exception Exception;
typedef Exception* ExceptionPtr;
struct Exception {
  char *msg;
  int  errorCode;
  void *data;
};

Exception *createException(char *msg, int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);

void throwException(int errorCode, void *data, char *message, ...);

int add(int numOfItems, ...);

#endif // Exception_H