#line 1 "C:/Users/COLCIC.COLCIC-037210/Documents/Rn/eeprom_8/eeprom_8.c"
void lcd(char str[15]) {
 trisd = 0;
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, str);
 trisd = 255;
}

void w_24c04 (int addr, char data) {
 i2c_start();
 i2c_wr(0xa0);
 i2c_wr(addr);
 i2c_wr(data);
 i2c_stop();
}

int r_24c04 (int addr) {
 int k;
 i2c_start();
 i2c_wr(0xa0);
 i2c_wr(addr);
 i2c_repeated_start();
 i2c_wr(0xa1);
 k = i2c_rd(0u);
 i2c_stop();
 return k;
}

void solve (int x) {
 char aux[10], maux[10];
 int tx, i;
 i = 0;
 tx = -1;
 trisd = 0;
 lcd_custom_cmd(lcd_clear);
 lcd_custom_out(1, 1, "y=5*(2+T[x]-x)");

 while (i < 5) {
 if (r_24c04(20 + i) == x) {
 tx = r_24c04(30 + i);
 }
 i = i + 1;
 }
 if (tx == -1) {
 lcd("Valor não definido");
 } else {
 tx = 5 * ( 2 + tx- x);
 intToStr(tx, aux);
 lcd_custom_out(2, 1, aux);
 }
 trisd = 255;
}

void eeprom_init (void) {
 int i, x[5] = {3, 5, 7, 8, 9}, tx[5] = {7, 10 , 13, 3, 1}, key = 20, value = 30;

 for (i = 0; i < 5; i++) {
 w_24c04(key + i, x[i]);
 delay_ms(300);
 w_24c04(value + i, tx[i]);
 delay_ms(300);
 }
}

void main () {
 int i;
 char num1, var2;
 ADCON1 = 0x06;
 trise = 0;
 trisa = 0;
 portb = 0xff;
 portd = 0xff;
 trisd = 0xff;
 trisb = 0;
 i2c_init(100000);
 lcd_custom_config(&portd, 7, 6, 5, 4, &porte, 2, 0, 1);
 lcd_custom_cmd(lcd_clear);
 lcd_custom_cmd(lcd_cursor_off);
 lcd("Carregando");
 eeprom_init();
 lcd("Pronto");
 delay_ms(1000);
 lcd("");
 do {
 portb.rb0 = 0;
 var2 = portd;
 if (var2.f0 == 0) {
 lcd("<--");
 } else if (var2.f1 == 0) {
 solve(7);
 } else if (var2.f2 == 0) {
 solve(4);

 } else if (var2.f3 == 0) {
 solve(1);

 }

 portb.rb1 = 0;
 var2 = portd;

 if (var2.f0 == 0) {
 solve(0);
 } else if (var2.f1 == 0) {
 solve(8);
 } else if (var2.f2 == 0) {
 solve(5);
 } else if (var2.f3 == 0) {
 solve(2);
 }

 portb.rb1 = 1;
 portb.rb2 = 0;
 var2 = portd;

 if (var2.f0 == 0) {

 } else if (var2.f1 == 0) {
 solve(9);
 } else if (var2.f2 == 0) {
 solve(6);
 } else if (var2.f3 == 0) {
 solve(3);
 }
 } while(1);
}
