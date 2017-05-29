String timestampString () {
 String timeString="";
  if (Clock.getDate() < 10) {
    timeString+="0";
  }
  //Serial.println(timeString);
  timeString+=String(Clock.getDate(), DEC);
  //Serial.println(timeString);
  timeString+=".";
  //Serial.println(timeString);
  if (Clock.getMonth(Century) < 10) {
    timeString+="0";
  }
  //Serial.println(timeString);
  timeString+=String(Clock.getMonth(Century),DEC);
  //Serial.println(timeString);
  timeString+=".";
  //Serial.println(timeString);
  timeString+=String(Clock.getYear(),DEC);
  //Serial.println(timeString);
  timeString+=" ";
  if (Clock.getHour(h12, PM) < 10) {
    timeString+="0";
  }
  //Serial.println(timeString);
  timeString+=String(Clock.getHour(h12, PM),DEC);
  //Serial.println(timeString);
  timeString+=":";
  if (Clock.getMinute() < 10) {
    timeString+="0";
  }
  //Serial.println(timeString);
  timeString+=String(Clock.getMinute(),DEC);
  //Serial.println(timeString);
  timeString+=":";
  if (Clock.getSecond() < 10) {
    timeString+="0";
  }
  //Serial.println(timeString);
  timeString+=String(Clock.getSecond(),DEC);
  return timeString;
}
