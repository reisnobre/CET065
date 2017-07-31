#line 1 "C:/Users/COLCIC.COLCIC-037210/Documents/Rn/contador/Contador.c"

void main() {
 int a = 0;
 t0con = 0b11000111;
 tmr0l = 0b00000000;
 trisd = 0;
 portd = 0xff;
 while (1) {
 if (tmr0l == 0b11111111) {
 a += 1;
 tmr0l = 0b00000000;
 if (a ==  31  * 10 ) {
 portd = ~portd;
 a = 0;
 }
 }
 }
}
