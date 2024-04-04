#include "kernel/param.h"
#include "kernel/fcntl.h"
#include "kernel/types.h"
#include "kernel/riscv.h"
#include "kernel/resource.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  struct rusage ru;
  getrusage(&ru);
  printf("%d\n", ru.resident_set_size);
  exit(0);
}

