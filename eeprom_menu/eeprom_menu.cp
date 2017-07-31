#line 1 "C:/Users/COLCIC.COLCIC-037210/Documents/Rn/eeprom_menu/eeprom_menu.c"
void mainMenu (void) {
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "1. READ 2.WRITE");
 lcd_custom_out(2, 1, "3. DELETE");
}

void reading (void) {
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "READING EEPROM");
 delay_ms(1000);
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, eeprom_read(0x69));
 delay_ms(2000);
 mainMenu();
}
void writing (void) {
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "WRITING EEPROM");
 eeprom_write(0x69, "ALGO");
 delay_ms(1000);
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "WROTE");
 delay_ms(1000);
 mainMenu();
}
void deleting (void) {
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "DELETING EEPROM");
 eeprom_write(0x69, "VOID");
 delay_ms(1000);
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "DELETED");
 delay_ms(2000);
 mainMenu();
}
void main () {
 ADCON1 = 0x06;
 trise = 0;
 trisd = 0;
 portb = 1;



 lcd_custom_config(&portd, 7, 6, 5, 4, &porte, 2, 0, 1);
 lcd_custom_cmd(lcd_clear);
 lcd_custom_cmd(lcd_cursor_off);
 mainMenu();
 do {
 if (portb.rb0 == 0) {
 reading();
 }
 if (portb.rb1 == 0) {
 writing();
 }
 if (portb.rb2 == 0) {
 deleting();
 }
 } while(1);
}
