/***********************************************************************************************************************************
Handle IO Write

Write to a handle using the IoWrite interface.
***********************************************************************************************************************************/
#ifndef COMMON_IO_HANDLEWRITE_H
#define COMMON_IO_HANDLEWRITE_H

#include "common/io/write.h"

/***********************************************************************************************************************************
Constructor
***********************************************************************************************************************************/
IoWrite *ioHandleWriteNew(const String *name, int handle);

/***********************************************************************************************************************************
Helper functions
***********************************************************************************************************************************/
// Write a string to the specified handle
void ioHandleWriteOneStr(int handle, const String *string);

#endif
