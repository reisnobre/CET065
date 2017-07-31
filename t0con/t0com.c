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
  char valor;
  int i;
  t0con = 0b11000111;
  tmr0l = 0b00000000;
  trisd = 0;
  trisb = 0;
  trisa = 0;
  portd = 0x00;
  portb = 0x00;
  porta = 0x00;
  valor = 0;
  INTCON = 0;
  porta.ra2 = 1;
  // porta.ra5 = 1;
  while (1) {
    if (tmr0l == valor) {
      portb = tmr0l;
      portd = mask(valor);
      for(i = 0 ; i < (256 * 255); i++);
      valor = valor + 1;
      if (valor > 7) valor = 0;
    }
  }
}
