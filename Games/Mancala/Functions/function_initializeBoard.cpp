#include "../function.h"

void initializeBoard(Cell cell_list[]) {
  for (int i = 0; i < 12; i++) {
    cell_list[i].stones = 4;
    cell_list[i].id = i + 1;
  }
}
