#include <stdio.h>

#define Begin() static int yield_state=0; switch(yield_state) { case 0:
#define Yield(x) do { yield_state=__LINE__; return x; case __LINE__:; } while (0)
#define End() }
int yield(void) {
  static int yield_index;
  Begin();
  for (yield_index = 0; yield_index < 10; yield_index++)
    Yield(yield_index);
  End();
}

int function(void) {
  static int i, state = 0;
  switch (state) {
    case 0:
    for (i = 0; i < 10; i++) {
      state = __LINE__ + 2;
      return i;
      case __LINE__:;
    }
  }
}

int main()
{
  int i;
  for (i = 0; i < 5; i++) {
    printf("%d\n", yield());
  }
  return 0;
}
