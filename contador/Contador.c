#define MULTI 31
void main() {
  int a = 0;
  t0con = 0b11000110;
  tmr0l = 0b00000000;
  trisd = 0;
  portd = 0xff;
  while (1) {
    if (tmr0l == 0b11111111) {
      a += 1;
      tmr0l = 0b00000000;
      if (a == MULTI * 10 ) {
        portd = ~portd;
        a = 0;
      }
    }
  }
}
