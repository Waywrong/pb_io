#include <iostream>
#include <fstream>
#include "proto/helloworld.pb.h"

 int pb_write(void) 
 { 
  lm::helloworld msg1; 
  msg1.set_id(101); 
  msg1.set_str("hello"); 
    
  // Write the new address book back to disk. 
  std::fstream output("./log.pb", std::ios::out | std::ios::trunc | std::ios::binary); 
        
  if (!msg1.SerializeToOstream(&output)) 
  { 
      std::cerr << "Failed to write msg." << std::endl; 
      return -1; 
  }         
  return 0; 
 }
 
 void ListMsg(const lm::helloworld & msg) { 
  std::cout << msg.id() << std::endl; 
  std::cout << msg.str() << std::endl; 
 } 
 
 int pb_read(void) 
 { 
  lm::helloworld msg1; 
  { 
    std::fstream input("./log.pb", std::ios::in | std::ios::binary); 
    if (!msg1.ParseFromIstream(&input)) { 
      std::cerr << "Failed to parse address book." << std::endl; 
      return -1; 
    } 
  } 
  ListMsg(msg1); 

  return 0;
 }
 
int main(int argc, char **argv)
{
  pb_write();
  pb_read();
  return 0;
}
