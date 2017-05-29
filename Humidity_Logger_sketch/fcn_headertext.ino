void headertext (String filename) {
  String StrTemp = "--> sketch: ";
  StrTemp = StrTemp + filename;
  dataFile.println("---------------------------------------------------------------------------------------------");
  dataFile.println("--> File opened");
  dataFile.println(StrTemp);
  dataFile.println("--> Start of measurement log");
  dataFile.println(timestampString());
  dataFile.println("---------------------------------------------------------------------------------------------");
  dataFile.print("Date and Time");
  dataFile.print("\t");
  dataFile.print("Data Capacitance");
  dataFile.print("\t");
  dataFile.println("Data Capacitance Prozent");
}

