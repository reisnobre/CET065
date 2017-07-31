#line 1 "C:/Users/COLCIC.COLCIC-037210/Documents/Rn/lcd_matricial/LCDMatricial.c"
void init_lcd(void){
 lcd8_config(&porte,&portd,2,1,0,7,6,5,4,3,2,1,0);
 lcd8_cmd(lcd_clear);
 lcd8_cmd(lcd_cursor_off);
 delay_ms(100);
}
void lcd(char str[5]) {
 trisd = 0;
 lcd8_cmd(lcd_clear);
 lcd8_out(1, 1, "Segredo");
 lcd8_out(2, 0, ' ');
 lcd8_out_cp(str);
 trisd = 255;
}

void main () {
 char var2;
 int segredo = 6969;
 int senha = 0;
 int multi = 1000;
 int tent = 0;
 ADCON1 = 0x06;
 trisd = 255;
 trisa = 0;
 init_lcd(void);
 lcd(" ");
 portb = 255;
 portd = 255;
 trisd = 255;
 trisb = 0;

 do {

 portb.rb0 = 0;
 var2 = portd;
 if (var2.rb0 == 0) {
 lcd("<--");
 } else if(var2.rb1 == 0) {
 senha += 7 * multi;
 tent++;
 multi /= 10;
 } else if(var2.rb2 == 0) {
 senha += 4 * multi;
 tent++;
 multi /= 10;
 } else if(var2.rb3 == 0) {
 senha += 1 * multi;
 tent++;
 multi /= 10;
 }
 portb.rb0 = 1;


 portb.rb1 = 0;
 var2 = portd;

 if (var2.rb0 == 0) {
 lcd("0");
 } else if(var2.rb1 == 0) {
 senha += 8 * multi;
 tent++;
 multi /= 10;
 } else if(var2.rb2 == 0) {
 senha += 5 * multi;
 tent++;
 multi /= 10;
 } else if(var2.rb3 == 0) {
 senha += 2 * multi;
 tent++;
 multi /= 10;
 }
 portb.rb1 = 1;



 portb.rb2 = 0;
 var2 = portd;

 if (var2.rb0 == 0){
 lcd("-->");
 } else if(var2.rb1 == 0) {
 senha += 9 * multi;
 tent++;
 multi /= 10;
 } else if(var2.rb2 == 0) {
 senha += 6 * multi;
 tent++;
 multi /= 10;
 } else if(var2.rb3 == 0) {
 senha += 3 * multi;
 tent++;
 multi /= 10;
 }
 portb.rb2 = 1;
 if (tent < 4) {
 lcd("Fechado");
 } else if (tent == 4) {
 if (senha == segredo) {
 lcd("Aberto");
 } else {
 lcd("Errado");
 delay_ms(1000);
 tent = 0;
 senha = 0;
 multi = 1000;
 }
 }
 delay_ms(100);
 } while(1);
}
