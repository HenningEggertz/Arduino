unsigned char cmd[9],checksumma;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);



}

void loop() {
   
    cmd[0] = 1;                     // adress  i    sändpaketet läggs i cmd[0]
    cmd[1] = 3;                     //kommando                 -"-      cmd[1]
    cmd[2] = 0;                     // kommandotyp              -"      cmd[2]
    cmd[3] = 0;                     // motor                    -"-     cmd[3]
    // value = antal steg består av 4 bytes    
    cmd[4] = 0;//(unsigned char)((value>> 24) & 0xFF);      //  byte 1 läggs i cmd[4]   // beräknar innehållet i byte 1
    cmd[5] = 0;//(unsigned char)((value>> 16) & 0xFF);      // byte 2     -"-  cmd[5}   //            -"-        byte 2
    cmd[6] = 0;//(unsigned char)((value>> 8) & 0xFF);       // byte 3     -"-   cmd[6]  //             -"-        byte 3     
    cmd[7] = 0;//(unsigned char)((value>> 0) & 0xFF);       // byte 4     -"-   cmd[7]  //              -"-       byte 4
    checksumma = 0;                  // nollställer checksumma
    for(int i=0;i<8;i++){               // 
      checksumma+= cmd[i];          // summera de 8 byten och lägg i checksumma
    }
    cmd[8] = checksumma;            // lägg checksumma i cmd[9]
    for(int i = 0; i<9;i++){
    //Serial.print();
    Serial.write(cmd[i]);           // skriv ut alla 9 byten till motorn
    }

delay(5000);

    cmd[0] = 1;                     // adress  i    sändpaketet läggs i cmd[0]
    cmd[1] = 1;                     //kommando                 -"-      cmd[1]
    cmd[2] = 0;                     // kommandotyp              -"      cmd[2]
    cmd[3] = 0;                     // motor                    -"-     cmd[3]
    // value = antal steg består av 4 bytes    
    cmd[4] = 0;//(unsigned char)((value>> 24) & 0xFF);      //  byte 1 läggs i cmd[4]   // beräknar innehållet i byte 1
    cmd[5] = 0;//(unsigned char)((value>> 16) & 0xFF);      // byte 2     -"-  cmd[5}   //            -"-        byte 2
    cmd[6] = 3;//(unsigned char)((value>> 8) & 0xFF);       // byte 3     -"-   cmd[6]  //             -"-        byte 3     
    cmd[7] = 232;//(unsigned char)((value>> 0) & 0xFF);       // byte 4     -"-   cmd[7]  //              -"-       byte 4
    checksumma = 0;                  // nollställer checksumma
    for(int i=0;i<8;i++){               // 
      checksumma+= cmd[i];          // summera de 8 byten och lägg i checksumma
    }
    cmd[8] = checksumma;            // lägg checksumma i cmd[9]
    for(int i = 0; i<9;i++){
    //Serial.print();
    Serial.write(cmd[i]);           // skriv ut alla 9 byten till motorn
    }

delay(5000);
}
