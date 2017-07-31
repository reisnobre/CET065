#line 1 "C:/Users/COLCIC.COLCIC-037210/Documents/Rn/newPush/push.c"
void main(){
 trisb.rb1 = 1;
 trisb.rb5 = 0;
 trisb.rb6 = 0;

 while (1) {
 if(portb.rb1 == 0) {
 portb.rb5 = portb.rb6 = 1;
 } else {
 portb.rb5 = portb.rb6 = 0;
 }
 }
}
