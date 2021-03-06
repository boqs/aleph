// asf
#include "print_funcs.h"
// bees
#include "net_protected.h"
#include "op_monome_grid_classic.h"

//-------------------------------------------------
//----- static variables

//---- descriptor strings
static const char* op_mgrid_classic_instring = "FOCUS\0  TOG\0    MONO\0   ";
static const char* op_mgrid_classic_outstring = "COL\0    ROW\0    VAL\0    ";
static const char* op_mgrid_classic_opstring = "GRID";

//-------------------------------------------------
//----- static function declaration

//---- input functions

//// network inputs: 
static void op_mgrid_classic_in_focus(op_mgrid_classic_t* grid, const io_t val);
static void op_mgrid_classic_in_tog(op_mgrid_classic_t* grid, const io_t val);
static void op_mgrid_classic_in_mono(op_mgrid_classic_t* grid, const io_t val);

// pickles
static u8* op_mgrid_classic_pickle(op_mgrid_classic_t* enc, u8* dst);
static const u8* op_mgrid_classic_unpickle(op_mgrid_classic_t* enc, const u8* src);

/// monome event handler
static void op_mgrid_classic_handler(op_monome_t* op_monome, u32 data);

// input func pointer array
static op_in_fn op_mgrid_classic_in_fn[3] = {
  (op_in_fn)&op_mgrid_classic_in_focus,
  (op_in_fn)&op_mgrid_classic_in_tog,
  (op_in_fn)&op_mgrid_classic_in_mono,
};

//-------------------------------------------------
//----- extern function definition
void op_mgrid_classic_init(void* mem) {
  //  print_dbg("\r\n op_mgrid_classic_init ");
  op_mgrid_classic_t* op = (op_mgrid_classic_t*)mem;

  // superclass functions
  //--- op
  op->super.in_fn = op_mgrid_classic_in_fn;
  op->super.pickle = (op_pickle_fn) (&op_mgrid_classic_pickle);
  op->super.unpickle = (op_unpickle_fn) (&op_mgrid_classic_unpickle);

  //--- monome
  op->monome.handler = (monome_handler_t)&op_mgrid_classic_handler;
  net_monome_init(&op->monome, op);

  // superclass state

  op->super.type = eOpMonomeGridClassic;
  op->super.flags |= (1 << eOpFlagMonomeGrid);

  op->super.numInputs = 3;
  op->super.numOutputs = 3;

  op->super.in_val = op->in_val;
  op->super.out = op->outs;

  op->super.opString = op_mgrid_classic_opstring;
  op->super.inString = op_mgrid_classic_instring;
  op->super.outString = op_mgrid_classic_outstring;

  op->in_val[0] = &(op->focus);
  op->monome.focus = &(op->focus);
  op->in_val[1] = &(op->tog);  
  op->in_val[2] = &(op->mono);
  op->outs[0] = -1;
  op->outs[1] = -1;
  op->outs[2] = -1;

  op->lastPos = 0;
  op->focus = OP_ONE;
  if(!recallingScene) {
    net_monome_set_focus(&(op->monome), 1);
  }
}

// de-init
void op_mgrid_classic_deinit(void* op) {
  // release focus
  net_monome_set_focus(&(((op_mgrid_classic_t*)op)->monome), 0);
}

//-------------------------------------------------
//----- static function definition

//--- network input functions
static void op_mgrid_classic_in_focus(op_mgrid_classic_t* op, const io_t v) {
  if((v) > 0) {
    op->focus = OP_ONE;
  } else {
    // if(op->focus > 0) { net_monome_grid_clear(); }
    op->focus = 0;
  }
  net_monome_set_focus( &(op->monome), op->focus > 0);
}

static void op_mgrid_classic_in_tog(op_mgrid_classic_t* op, const io_t v) {
  op->tog  = (v > 0) ? OP_ONE : 0;
}

static void op_mgrid_classic_in_mono(op_mgrid_classic_t* op, const io_t v) {
  op->mono  = (v > 0) ? OP_ONE : 0;
}

static void op_mgrid_classic_handler(op_monome_t* op_monome, u32 edata) {
  static u8 x, y, z;
  static u32 pos;
  static u8 val;

  op_mgrid_classic_t* op = (op_mgrid_classic_t*)(op_monome->op);


  monome_grid_key_parse_event_data(edata, &x, &y, &z);

  /* print_dbg("\r\n op_mgrid_classic_handler received event; x: 0x"); */
  /* print_dbg_hex(x); */
  /* print_dbg("; y: 0x"); */
  /* print_dbg_hex(y); */
  /* print_dbg("; z: 0x"); */
  /* print_dbg_hex(z); */

  // flat position into led buffer
  pos = monome_xy_idx(x, y);

  if(op->mono) {
    if(op->tog > 0) { // mono, toggle
      if(z > 0) {        // ignore lift
	val = ( op_monome->opLedBuffer[pos] == 0 );
	op_monome->opLedBuffer[pos] = val * 15;
	if(pos != op->lastPos) {
	  op_monome->opLedBuffer[op->lastPos] = 0;
	}
	net_activate(op, 0, op_from_int(x));
	net_activate(op, 1, op_from_int(y));
	net_activate(op, 2, op_from_int(val));
	// refresh flag for current quadrant
	monome_calc_quadrant_flag(x, y);
	// refresh flag for previous quadrant
	monome_idx_xy(op->lastPos, &x, &y);
	monome_calc_quadrant_flag(x, y);
      }
    } else { // mono, momentary
      val = z;
      op_monome->opLedBuffer[pos] =  val * 15;
      op_monome->opLedBuffer[op->lastPos] = 0;
      net_activate(op, 0, op_from_int(x));
      net_activate(op, 1, op_from_int(y));
      net_activate(op, 2, op_from_int(val));
      // refresh flag for current quadrant
      monome_calc_quadrant_flag(x, y);
      // refresh flag for previous quadrant
      monome_idx_xy(op->lastPos, &x, &y);
      monome_calc_quadrant_flag(x, y);  
    }
  } else {
    if(op->tog > 0) { // poly, toggle
      if(z > 0) {      /// ignore lift
	val = ( op_monome->opLedBuffer[pos] == 0 );
	op_monome->opLedBuffer[pos] = val * 15;
	net_activate(op, 0, op_from_int(x));
	net_activate(op, 1, op_from_int(y));
	net_activate(op, 2, op_from_int(val));
	// refresh flag for current quadrant
	monome_calc_quadrant_flag(x, y);
      }
    } else {   // poly, momentary
      val = z;
      op_monome->opLedBuffer[pos] = val * 15;
      net_activate(op, 0, op_from_int(x));
      net_activate(op, 1, op_from_int(y));
      net_activate(op, 2, op_from_int(val));
      // refresh flag for current quadrant
      monome_calc_quadrant_flag(x, y);
    }
  }
  op->lastPos = pos;
}



// pickle / unpickle
u8* op_mgrid_classic_pickle(op_mgrid_classic_t* mgrid, u8* dst) {
  dst = pickle_io(mgrid->focus, dst);
  dst = pickle_io(mgrid->tog, dst);
  dst = pickle_io(mgrid->mono, dst);
  int i;
  for (i=0; i < MONOME_MAX_LED_BYTES; i++) {
    *dst = mgrid->monome.opLedBuffer[i];
    dst++;
  }
  return dst;
}

const u8* op_mgrid_classic_unpickle(op_mgrid_classic_t* mgrid, const u8* src) {
  src = unpickle_io(src, (u32*)&(mgrid->focus));
  src = unpickle_io(src, (u32*)&(mgrid->tog));
  src = unpickle_io(src, (u32*)&(mgrid->mono));
  int i;
  for (i=0; i < MONOME_MAX_LED_BYTES; i++) {
    mgrid->monome.opLedBuffer[i] = *src;
    src++;
  }

  if(mgrid->focus > 0) {
    net_monome_set_focus( &(mgrid->monome), 1);
  }
  return src;
}
