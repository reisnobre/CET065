
unsigned int i;

unsigned short mask (unsigned short num) {
  switch (num) {
    case 0: return 0x3F;
    case 1: return 0x06;
    case 2: return 0x5B;
    case 3: return 0x4F;
    case 4: return 0x66;
    case 5: return 0x6D;
    case 6: return 0x7D;
    case 7: return 0x07;
    case 8: return 0x7F;
    case 9: return 0x6F;
  }
}

void main () {
  int a = 0;
  int b = 0;
  trisd = 0;
  trisa = 0;
  porta = 0;
  portd = 0;
  INTCON = 0;

  while (1) {
    i = 0;
    for(i = 0; i < 14 ; i++){
      if (i < 9) {
        porta.ra4 = 1;
        portd = mask(0);
        delay_ms(100);
        porta.ra4 = 0;
      } else {
        porta.ra4 = 1;
        portd = mask(1);
        delay_ms(100);
        porta.ra4 = 0;
      }

      if (i < 9) {
        porta.ra5 = 1;
        portd = mask(i + 1);
        delay_ms(100);
        porta.ra5 = 0;
      } else {
        porta.ra5 = 1;
        portd = mask(i - 8);
        delay_ms(100);
        porta.ra5 = 0;
      }
      delay_ms(1);
    }
  }
}
