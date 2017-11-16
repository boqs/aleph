// asf
#include "print_funcs.h"
// bees
#include "net_protected.h"
#include "op_monome_arc.h"

//-------------------------------------------------
//----- static variables

//---- descriptor strings
static const char* op_marc_instring =  "FOCUS\0  RING\0   POS\0    VAL\0    ";
static const char* op_marc_outstring = "NUM\0    DELTA\0  ";
static const char* op_marc_opstring =  "ARC";

//-------------------------------------------------
//----- static function declaration

//---- input functions

//// network inputs: 
static void op_marc_in_focus(op_marc_t* grid, const io_t val);
static void op_marc_in_ring(op_marc_t* grid, const io_t val);
static void op_marc_in_pos(op_marc_t* grid, const io_t val);
static void op_marc_in_val(op_marc_t* grid, const io_t val);

// pickles
static u8* op_marc_pickle(op_marc_t* enc, u8* dst);
static const u8* op_marc_unpickle(op_marc_t* enc, const u8* src);

/// monome event handler
static void op_marc_handler(op_monome_t* op_monome, u32 data);

// input func pointer array
static op_in_fn op_marc_in_fn[5] = {
  (op_in_fn)&op_marc_in_focus,
  (op_in_fn)&op_marc_in_ring,
  (op_in_fn)&op_marc_in_pos,
  (op_in_fn)&op_marc_in_val,
};

//-------------------------------------------------
//----- extern function definition
void op_marc_init(void* mem) {
  //  print_dbg("\r\n op_marc_init ");
  op_marc_t* op = (op_marc_t*)mem;


  // superclass functions
  //--- op
  op->super.in_fn = op_marc_in_fn;
  op->super.pickle = (op_pickle_fn) (&op_marc_pickle);
  op->super.unpickle = (op_unpickle_fn) (&op_marc_unpickle);

  //--- monome
  op->monome.handler = (monome_handler_t)&op_marc_handler;
  net_monome_init(&op->monome, op);

  // superclass state

  op->super.type = eOpMonomeArc;
  op->super.flags |= (1 << eOpFlagMonomeRing);

  op->super.numInputs = 4;
  op->super.numOutputs = 2;

  op->super.in_val = op->in_val;
  op->super.out = op->outs;

  op->super.opString = op_marc_opstring;
  op->super.inString = op_marc_instring;
  op->super.outString = op_marc_outstring;

  op->in_val[0] = &(op->focus);
  op->monome.focus = &(op->focus);
  op->in_val[1] = &(op->ring);
  op->in_val[2] = &(op->pos);
  op->in_val[3] = &(op->val);

  op->outs[0] = -1;
  op->outs[1] = -1;

  op->focus = OP_ONE;
  op->ring = 0;
  op->pos = 0;
  op->val = 0;

  if(!recallingScene) {
    net_monome_set_focus(&(op->monome), 1);
  }
}

// de-init
void op_marc_deinit(void* op) {
  // release focus
  net_monome_set_focus(&(((op_marc_t*)op)->monome), 0);
}

//-------------------------------------------------
//----- static function definition

//--- network input functions
static void op_marc_in_focus(op_marc_t* op, const io_t v) {
  if((v) > 0) {
    op->focus = OP_ONE;
  } else {
    op->focus = 0;
  }
  net_monome_set_focus( &(op->monome), op->focus > 0);
}

// set ring number for next update
static void op_marc_in_ring(op_marc_t* op, const io_t v) {
  if(v<0) {
    op->ring = 0;
  }
  else if (v>3) {
    op->ring = 3;
  }
  else {
    op->ring = (u8)v;
  }
}

// set ring position for next update
static void op_marc_in_pos(op_marc_t* op, const io_t v) {
  if(v<0) {
    op->pos = 0;
  }
  else if (v>63) {
    op->pos = 63;
  }
  else {
    op->pos = (u8)v;
  }
}

// set value and perform update
static void op_marc_in_val(op_marc_t* op, const io_t v) {
  if (v<0) {
    op->val = 0;
  }
  else if (v>15) {
    op->val = 15;
  }
  else {
    op->val = (u8)v;
  }
  monome_arc_led_set(op->ring, op->pos, op->val);
}


static void op_marc_handler(op_monome_t* op_monome, u32 data) {
  u8 n;
  s8 v;
  
  op_marc_t* op = (op_marc_t*)(op_monome->op);
  monome_ring_enc_parse_event_data(data, &n, &v);
  net_activate(op, 0, (io_t)n);
  net_activate(op, 1, (io_t)v);
}


// pickle / unpickle
u8* op_marc_pickle(op_marc_t* marc, u8* dst) {
  dst = pickle_io(marc->focus, dst);
  int i;
  for (i=0; i < MONOME_MAX_LED_BYTES; i++) {
    *dst = marc->monome.opLedBuffer[i];
    dst++;
  }
  return dst;
}

const u8* op_marc_unpickle(op_marc_t* marc, const u8* src) {
  src = unpickle_io(src, (u32*)&(marc->focus));
  if (marc->focus > 0) {
    net_monome_set_focus( &(marc->monome), 1);
  }
  int i;
  for (i=0; i < MONOME_MAX_LED_BYTES; i++) {
    marc->monome.opLedBuffer[i] = *src;
    src++;
  }
  return src;
}
