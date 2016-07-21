  #include "test.h"
  #include "packets.h" 
  void initiate_communication(){
      Serial.begin(BAUD_RATE); 
      Serial1.begin(BAUD_RATE); 
      Serial2.begin(BAUD_RATE); 
      Serial3.begin(BAUD_RATE); 
  }

  void process_packet(uint8_t* fee_ptr, int index){
    if(packet_exists[index]){
      print_packet(fee_ptr, index); 
      check_checksum(fee_ptr, index); 
      packet_exists[index] = false; 
      response_packet_counter[index] = 0; 
      global_packet_counter[index]++; 
    }
    
  }
  
  void serial_write(bool send_cmd[3]){  
    process_packet(fee_packet_ptr, 0);                                           //on every rising edge we will first check to see if a packet exists and proces it accordingly, re-initialzing the flag to false and the counter to its initial value
    process_packet(fee_packet1_ptr, 1); 
    process_packet(fee_packet2_ptr, 2); 
    if(!packet_exists[0] && send_cmd[0]){ 
        Serial1.write(cmd_packet, PACKET_SIZE);                     //if the packet doesn't exist to be processed then we move send our packet; 
    }   
    if(!packet_exists[1] && send_cmd[1]){
        Serial2.write(cmd_packet1, PACKET_SIZE); 
    }
    if(!packet_exists[2] && send_cmd[2]){    
        Serial3.write(cmd_packet2, PACKET_SIZE); 
    }
  }
  
  
  bool check_capacity(int crt_pckt_size)
  {
    if (crt_pckt_size > FEE_PACKET_SIZE){
      //do something 
       return true; 
    }
    else{
      return false; 
    }
  }
  
  
  void recieve_reply()
  {
   // if(!send_command){
        if(Serial1.available()){
          packet_exists[0] = true;
                 //  set_flag(0); 
                   fee_packet[response_packet_counter[0]] = Serial1.read(); 
                   Serial.println(fee_packet[response_packet_counter[0]]); 
                   checksum[0] ^= fee_packet[response_packet_counter[0]]; // Serial.println(FEE_PACKET1.bytes[response_packet_counter[0]]); 
                   response_packet_counter[0]++;
         }
  
         if(Serial2.available()){
          packet_exists[1] = true; 
                  // set_flag(1); 
                   fee_packet1[response_packet_counter[1]] = Serial2.read();
                   checksum[1] ^= fee_packet1[response_packet_counter[1]];  
                   response_packet_counter[1]++;  
                   //if(response_packet_counter[1] == 6){
                    //  packet_exists = true; 
                     // response_packet_counter[1] = 0; 
                   //}
         }
         
         if(Serial3.available()){
          packet_exists[2] = true; 
                     // set_flag(2);
                     fee_packet2[response_packet_counter[2]] = Serial3.read(); 
                     checksum[2] ^= fee_packet[response_packet_counter[2]];  
                     //Serial.println(FEE_PACKET3.bytes[response_packet_counter[2]]);  
                     response_packet_counter[2]++; 
                     //if(response_packet_counter[2] == 6){
                      //  response_packet_counter[2] = 0; 
                     //}
                    
         }
   // }
    
  }
  bool set_flag(int index){
    if(check_capacity[index]){ 
      //digitalWrite(13, HIGH); 
      //response_packet_counter[index] = 0; 
      check_cap[index] = true;
    } 
  }

