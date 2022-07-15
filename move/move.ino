int moterMove(int moterNumber1, int moterNumber2, int moterNumber, int moterSpeed){
  if(moterSpeed>=0){
    digitalWrite(moterNumber1, HIGH);
    digitalWrite(moterNumber2, LOW);
    digitalWrite(moterNumber1, moterSpeed);
  }else{
    digitalWrite(moterNumber1, LOW);
    digitalWrite(moterNumber2, HIGH);
    digitalWrite(moterNumber1, -1*moterSpeed);
  }
  return 0;
}
