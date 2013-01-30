/* encoders.c
 * aleph
 */

// asf
#include "compiler.h"
#include "gpio.h"
#include "print_funcs.h"

// aleph
#include "conf_aleph.h"
#include "events.h"
#include "event_types.h"
#include "encoders.h"

//--------------------------
//---- external variables

enc_t enc[NUM_ENC];

//---------------------------
//---- static variables

// encoder movement map
static const S8 enc_map[4][4] = { {0,1,-1,0}, {-1,0,0,1}, {1,0,0,-1}, {0,-1,1,0} };
//------------------------------
//----- external functions

// initialize encoder positions
void init_encoders(void) {
  U8 i;
  // constant data
  enc[0].pin[0] = ENC0_S0_PIN;
  enc[0].pin[1] = ENC0_S1_PIN;
  enc[0].event = kEventEncoder0;
  enc[1].pin[0] = ENC1_S0_PIN;
  enc[1].pin[1] = ENC1_S1_PIN;
  enc[1].event = kEventEncoder1;
  enc[2].pin[0] = ENC2_S0_PIN;
  enc[2].pin[1] = ENC2_S1_PIN;
  enc[2].event = kEventEncoder2;
  enc[3].pin[0] = ENC3_S0_PIN;
  enc[3].pin[1] = ENC3_S1_PIN;
  enc[3].event = kEventEncoder3;
  
  // realtime initial pin values
  for(i=0; i<NUM_ENC; i++) {
    enc[i].pos = gpio_get_pin_value(enc[i].pin[0]) + (gpio_get_pin_value(enc[i].pin[1]) << 1);
    enc[i].thresh = 15;
  }

  ////// TEST:
  /// make enc3 slow
  //  enc[3].thresh = 40;

}

// post events based on encoder movements
void process_enc( const U8 idx) {
  //event_t e;  
  // S8 val = 0;
  U8 pos;
  
  pos = gpio_get_pin_value(enc[idx].pin[0]) + (gpio_get_pin_value(enc[idx].pin[1]) << 1);
  
  /*
  print_dbg("\r\nprocessing encoder, idx: ");
  print_dbg_ulong(idx);
  print_dbg(" , pos: ");
  print_dbg_hex(pos);
  */

  if (pos != enc[idx].pos) {
    enc[idx].val -= enc_map[enc[idx].pos][pos];
    enc[idx].pos = pos;
  }
  
}
  

