#include <EtherCard.h>
#include<SoftwareSerial.h>

SoftwareSerial listener(2,3); //pin4 Rx , pin3 Tx
int iterador = 0;
int salida = 0;

static byte mac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
byte Ethernet::buffer[700];
static uint32_t retraso;
char web[] = "centinela.local";

static void responseHandler (byte status, word off, word len) {
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

void setup () {
  Serial.begin(9600);
  
  Serial.println("Inicializando dispositivo de lectura ....");
  listener.listen();
  listener.begin(9600);
  delay(10);
  listener.write(0x02);
  
  Serial.println("\n Inicializando cliente web");

  if (ether.begin(sizeof Ethernet::buffer, mac) == 0){ 
    Serial.println( "---  No se pudo conectar con el servidor");
  }
  if (!ether.dhcpSetup()){
    Serial.println("--- DHCP no responde");
  }else{
    Serial.println("Informacion de conexion \n");
    ether.printIp("IP:  ", ether.myip);
    ether.printIp("GW:  ", ether.gwip);  
  }  
}

void loop () {
  String numero = "";
  if(listener.available()){
    for (int i=0; listener.available() ; i++){
      byte C = listener.read();
      numero += String(int(C));
   }
   salida = 1;
  }
  
  if(salida == 1){
    Serial.print(" -- numero leido : " + numero);
    salida = 0;
    
    ether.packetLoop(ether.packetReceive());
    
    Serial.println(" -- enviando peticion ");
    ether.browseUrl(PSTR("/index.php"), "?r=device/register&id=" + numero, web, responseHandler);
    
    ether.browseUrl(PSTR("/index.php"), "?r=device/read&id=" + numero, web, responseHandler);
  }  
}
