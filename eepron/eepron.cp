#line 1 "C:/Users/COLCIC.COLCIC-037210/Documents/Rn/eepron/eepron.c"
void main () {
 char i = 0;
 char c[10];
 trisd = 0;
 trise = 0;
 ADCON1 = 0x06;
 trisb.rb0 = 1;
 trisb.rb1 = 1;
 lcd8_config(&porte,&portd,2,1,0,7,6,5,4,3,2,1,0);
 lcd8_cmd(lcd_clear);
 lcd8_cmd(lcd_cursor_off);
 lcd8_out(1, 1, "Y = X^2");
 while (1) {
 for(i = 1 ; i < 8 ; i++) {
 wordToStr(i, c);
 eeprom_write(0x20 + i, c);
 wordToStr(i * i, c);
 eeprom_write(0x50 + i, c);
 }
 for(i = 1 ; i < 8 ; i++) {
 lcd8_out(2, 0, eeprom_read(0x20 + i));
 lcd8_out(2, 6, "|");
 lcd8_out(2, 7, eeprom_read(0x50 + i));
 delay_ms(1000);
 }






 }
}
