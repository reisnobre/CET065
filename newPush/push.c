void main(){
  trisb.rb1 = 1;
  trisb.rb5 = 0;
  trisb.rb6 = 0;
  portb.rb0 = portb.rb1 = portb.rb2 = portb.rb3 = portb.rb4 = portb.rb5 = 1
  while (1) {
    if(portb.rb1 == 0) {
      portb.rb5 = portb.rb6 = 1;
    } else {
      portb.rb5 = portb.rb6 = 0;
    }
  }
}
