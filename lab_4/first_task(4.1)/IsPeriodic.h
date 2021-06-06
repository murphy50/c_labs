#ifndef ISPERIODIC_H
#define ISPERIODIC_H
int IsPeriodic(const char a[]) {

  int size = strlen(a);
  int flag = 1;
  for (int j = size / 2; j>0; j--) {// цикл меняющий размер периода 
    flag = 1;
    for (int i = 0; i+j<size ; i++) {
      if (a[j + i] != a[i]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  return flag;
}
#endif
