import processing.serial.*;
import netP5.*;
import oscP5.*;

/*** Serial settings ***/
Serial serialPort;
final short lf = 10; // ASCII linefeed '\n'

/*** MAX communication settings ***/
OscP5 osc;
NetAddress oscOut;
final int OSC_IN_PORT = 32000;
final int OSC_OUT_PORT = 12000;
final String LOCALHOST = "127.0.0.1";
final String ENDPOINT= "/values";

void setup() {
  // Serial setup
  printArray(Serial.list());
  /** CAUTION: which port to use depends! **/
  serialPort = new Serial(this, "/dev/tty.usbmodem14401", 9600);
  serialPort.bufferUntil(lf);
  
  // OSC setup
  osc = new OscP5(this, OSC_IN_PORT);
  oscOut = new NetAddress(LOCALHOST, OSC_OUT_PORT);
}

void draw() {
  // do nothing here
}

void serialEvent(Serial p) {
  try {
    if (p.available() <= 0) return;

    // read from Serial and convert to JSON
    final String inMsg = p.readString();
    final JSONObject jsonMsg = parseJSONObject(inMsg);
    
    if (jsonMsg == null) {
      println("Invalid JSON format: " + inMsg);
      return;
    }
    
    // creat the OscMessage to send over UDP
    OscMessage message = new OscMessage(ENDPOINT);
    message.add(jsonMsg.getInt("fsr1"));
    message.add(jsonMsg.getInt("fsr2"));
    message.add(jsonMsg.getInt("pc"));
    message.add(jsonMsg.getInt("cap"));
    osc.send(message, oscOut);
  } catch (RuntimeException e) {
    e.printStackTrace();
  } finally {
    delay(1000);
  }
}
