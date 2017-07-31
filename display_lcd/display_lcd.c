void main () {
  char contadorV = 0;
  char contadorF = 0;
  char vasco[10];
  char flamengo[10];
  trisd = 0;
  trise = 0;
  ADCON1 = 0x06;
  trisb.rb0 = 1;
  trisb.rb1 = 1;
  lcd8_config(&porte,&portd,2,1,0,7,6,5,4,3,2,1,0);
  lcd8_cmd(lcd_clear);
  lcd8_cmd(lcd_cursor_off);
  lcd8_out(1, 1, "VascoXFlamengo");
  lcd8_out(2, 3, "0");
  lcd8_out(2, 11, "0");
  while (1) {
    if (portb.rb0 == 0) {
      contadorV++;
      wordToStr(contadorV, vasco);
      delay_ms(200);
      lcd8_out(2, 3, vasco);
    } else if (portb.rb1 == 0) {
      contadorF++;
      wordToStr(contadorF, flamengo);
      delay_ms(200);
      lcd8_out(2, 11, flamengo);
    }
  }
}
