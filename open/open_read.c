#include <unistd.h>
#include <fcntl.h>
#include "open.h"

extern int open_read(const char *filename) {
  return open(filename,O_RDONLY|O_NDELAY);
}
