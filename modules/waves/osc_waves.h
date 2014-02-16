/* osc.h
   dsp
   aleph

   a simple wavetable oscillator with phase and shape modulation.
 */

#ifndef _ALEPH_WAVES_OSC_H_
#define _ALEPH_WAVES_OSC_H_

#include "fix.h"


// base-frequency limits in fix16
#define OSC_HZ_MIN 0x00010000      // 1 hz
#define OSC_HZ_MAX 0x40000000    // 16384 hz
#define OSC_HZ_RADIX 15

//---- expected parameters for wavetable data
// how many wavetables
#define WAVE_TAB_NUM 5
// size of each table
#define WAVE_TAB_SIZE 	1024
#define WAVE_TAB_SIZE_1 (WAVE_TAB_SIZE - 1)
#define WAVE_TAB_MAX16 	(WAVE_TAB_SIZE * FIX16_ONE - 1)
// rshift from shape variable to get table index
/// #define WAVE_TAB_RSHIFT 29
// 16b waveshape:
#define WAVE_TAB_RSHIFT 13
// mask to get interpolation constant
// #define WAVE_SHAPE_MASK 0x1fffffff
#define WAVE_SHAPE_MASK 0x1fff
// lshift after mask to get multiplier 
#define WAVE_TAB_LSHIFT 18

// index-per-sample at 1hz : tablesize / samplerate in 16.16
/// FIXME: this is a pretty dumb way to calculate it...
/// should use a higher base hz for accuracy.
#define OSC_IPS 0x00000576

// wavetable type: pointer to 2d array
typedef const fract32 (*wavtab_t) [WAVE_TAB_NUM][WAVE_TAB_SIZE];

// class structure
typedef struct _ComplexOsc {
  // output value
  fract32 val;
  // wavetable data (pointer to table of tables)
  wavtab_t tab;
  // normalized waveshape
  fract16 shape;
  // frequency in hz
  fix16 hz;
  // tuning ratio
  fix16 ratio;
  // base phase as fractional index
  fix16 idx;
  // modulated phase
  fix16 idxMod;
  // fixed-point index increment
  fix16 inc;
  // phase modulation amount [0-1)
  fract16 pmAmt;
  // shape modulation amount [0-1)
  fract16 wmAmt;
  /// store last modulation input values for recalculation
  fract32 pmIn, wmIn;
} ComplexOsc;

// collection of pointers for param smoother i/o ...
typedef struct _ComplexOsc_paramSlew {
  fract32* incIn;
  fract32* incOut;
  fract16* pmIn;
  fract16* pmOut;
  fract16* shapeIn;
  fract16* shapeOut;
} ComplexOsc_params;

// initialize given table data, 
/// pointers to parameter smoothing i/o
extern void osc_init( ComplexOsc* osc, 
		      wavtab_t tab, 
		      ComplexOsc_params* params
		     );

// set waveshape (table)
extern void osc_set_shape(ComplexOsc* osc, fract32 shape);
// set base frequency in hz
extern void osc_set_hz(ComplexOsc* osc, fix16 hz);
// set fine-tuning ratio
extern void osc_set_tune(ComplexOsc* osc, fix16 ratio);

// phase modulation amount
extern void osc_set_pm(ComplexOsc* osc, fract32 wmAmt);
// shape modulation amount
extern void osc_set_wm(ComplexOsc* osc, fract32 wmAmt);

// phase modulation input
extern void osc_pm_in(ComplexOsc* osc, fract32 pm);
// shape modulation input
extern void osc_wm_in(ComplexOsc* osc, fract32 wm);

// set bandlimiting coefficient
extern void osc_set_bl(ComplexOsc* osc, fract32 bl);

// compute next value
extern fract32 osc_next( ComplexOsc* osc);



#endif