#include "kernel/param.h"
#include "kernel/fcntl.h"
#include "kernel/types.h"
#include "kernel/riscv.h"
#include "kernel/resource.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  struct rusage* rusage = getrusage();
  printf("Bytes: %d\n", rusage->resident_set_size);
  // Bytes: 12288

  uint64 top = (uint64) sbrk(8192);
  printf("Bytes: %d\n", rusage->resident_set_size);
  printf("Top: %d\n", top);
  // sbrk(8192)
  // Bytes: 20480
  // Top: 12288

  // Writing to this location will force a page fault.
  rusage->resident_set_size = 42;

  exit(0);
}

