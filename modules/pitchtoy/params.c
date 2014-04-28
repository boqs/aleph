// autogenerated from param_gen.scd 
 

#include <string.h>
#include "module.h"
#include "params.h" 
extern void fill_param_desc(ParamDesc* desc) {
  strcpy(desc[eParam_dac0].label, "dac0");
  desc[eParam_dac0].type = eParamTypeFix; 
  desc[eParam_dac0].min = 0x00000000; 
  desc[eParam_dac0].max = PARAM_DAC_MAX;
  desc[eParam_dac0].radix = PARAM_DAC_RADIX;

  strcpy(desc[eParam_dac1].label, "dac1");
  desc[eParam_dac1].type = eParamTypeFix; 
  desc[eParam_dac1].min = 0x00000000; 
  desc[eParam_dac1].max = PARAM_DAC_MAX;
  desc[eParam_dac1].radix = PARAM_DAC_RADIX;

  strcpy(desc[eParam_dac2].label, "dac2");
  desc[eParam_dac2].type = eParamTypeFix; 
  desc[eParam_dac2].min = 0x00000000; 
  desc[eParam_dac2].max = PARAM_DAC_MAX;
  desc[eParam_dac2].radix = PARAM_DAC_RADIX;

  strcpy(desc[eParam_dac3].label, "dac3");
  desc[eParam_dac3].type = eParamTypeFix; 
  desc[eParam_dac3].min = 0x00000000; 
  desc[eParam_dac3].max = PARAM_DAC_MAX;
  desc[eParam_dac3].radix = PARAM_DAC_RADIX;

  strcpy(desc[eParam_slew0].label, "slew0");
  desc[eParam_slew0].type = eParamTypeIntegrator; 
  desc[eParam_slew0].min = 0x00000000; 
  desc[eParam_slew0].max = 0x7fffffff;
  desc[eParam_slew0].radix = 32;

  strcpy(desc[eParam_slew1].label, "slew1");
  desc[eParam_slew1].type = eParamTypeIntegrator; 
  desc[eParam_slew1].min = 0x00000000; 
  desc[eParam_slew1].max = 0x7fffffff;
  desc[eParam_slew1].radix = 32;

  strcpy(desc[eParam_slew2].label, "slew2");
  desc[eParam_slew2].type = eParamTypeIntegrator; 
  desc[eParam_slew2].min = 0x00000000; 
  desc[eParam_slew2].max = 0x7fffffff; 
  desc[eParam_slew2].radix = 32;

  strcpy(desc[eParam_slew3].label, "slew3");
  desc[eParam_slew3].type = eParamTypeIntegrator; 
  desc[eParam_slew3].min = 0x00000000; 
  desc[eParam_slew3].max = 0x7fffffff;
  desc[eParam_slew3].radix = 32;

  strcpy(desc[eParam_auxL0].label, "auxL0");
  desc[eParam_auxL0].type = eParamTypeAmp; 
  desc[eParam_auxL0].min = 0x00000000; 
  desc[eParam_auxL0].max = FR32_MAX;
  desc[eParam_auxL0].radix = 1;

  strcpy(desc[eParam_auxR0].label, "auxR0");
  desc[eParam_auxR0].type = eParamTypeAmp; 
  desc[eParam_auxR0].min = 0x00000000; 
  desc[eParam_auxR0].max = FR32_MAX;
  desc[eParam_auxR0].radix = 1;

  strcpy(desc[eParam_pan0].label, "pan0");
  desc[eParam_pan0].type = PAN_TYPE; 
  desc[eParam_pan0].min = PAN_MIN; 
  desc[eParam_pan0].max = PAN_MAX;
  desc[eParam_pan0].radix = PAN_RADIX;

  strcpy(desc[eParam_fader0].label, "fader0");
  desc[eParam_fader0].type = eParamTypeAmp; 
  desc[eParam_fader0].min = 0x00000000; 
  desc[eParam_fader0].max = FR32_MAX;
  desc[eParam_fader0].radix = 1;

  strcpy(desc[eParam_effect0].label, "effect0");
  desc[eParam_effect0].type = EFFECT_TYPE;
  desc[eParam_effect0].min = EFFECT_MIN;
  desc[eParam_effect0].max = EFFECT_MAX;
  desc[eParam_effect0].radix = EFFECT_RADIX;

  strcpy(desc[eParam_auxL1].label, "auxL1");
  desc[eParam_auxL1].type = eParamTypeAmp; 
  desc[eParam_auxL1].min = 0x00000000; 
  desc[eParam_auxL1].max = FR32_MAX;
  desc[eParam_auxL1].radix = 1;

  strcpy(desc[eParam_auxR1].label, "auxR1");
  desc[eParam_auxR1].type = eParamTypeAmp; 
  desc[eParam_auxR1].min = 0x00000000; 
  desc[eParam_auxR1].max = FR32_MAX;
  desc[eParam_auxR1].radix = 1;

  strcpy(desc[eParam_pan1].label, "pan1");
  desc[eParam_pan1].type = PAN_TYPE; 
  desc[eParam_pan1].min = PAN_MIN; 
  desc[eParam_pan1].max = PAN_MAX;
  desc[eParam_pan1].radix = PAN_RADIX;

  strcpy(desc[eParam_fader1].label, "fader1");
  desc[eParam_fader1].type = eParamTypeAmp; 
  desc[eParam_fader1].min = 0x00000000; 
  desc[eParam_fader1].max = FR32_MAX;
  desc[eParam_fader1].radix = 1;

  strcpy(desc[eParam_effect1].label, "effect1");
  desc[eParam_effect1].type = EFFECT_TYPE;
  desc[eParam_effect1].min = EFFECT_MIN;
  desc[eParam_effect1].max = EFFECT_MAX;
  desc[eParam_effect1].radix = EFFECT_RADIX;

  strcpy(desc[eParam_auxL2].label, "auxL2");
  desc[eParam_auxL2].type = eParamTypeAmp; 
  desc[eParam_auxL2].min = 0x00000000; 
  desc[eParam_auxL2].max = FR32_MAX;
  desc[eParam_auxL2].radix = 1;

  strcpy(desc[eParam_auxR2].label, "auxR2");
  desc[eParam_auxR2].type = eParamTypeAmp; 
  desc[eParam_auxR2].min = 0x00000000; 
  desc[eParam_auxR2].max = FR32_MAX;
  desc[eParam_auxR2].radix = 1;

  strcpy(desc[eParam_pan2].label, "pan2");
  desc[eParam_pan2].type = PAN_TYPE; 
  desc[eParam_pan2].min = PAN_MIN; 
  desc[eParam_pan2].max = PAN_MAX;
  desc[eParam_pan2].radix = PAN_RADIX;

  strcpy(desc[eParam_fader2].label, "fader2");
  desc[eParam_fader2].type = eParamTypeAmp; 
  desc[eParam_fader2].min = 0x00000000; 
  desc[eParam_fader2].max = FR32_MAX;
  desc[eParam_fader2].radix = 1;

  strcpy(desc[eParam_effect2].label, "effect2");
  desc[eParam_effect2].type = EFFECT_TYPE;
  desc[eParam_effect2].min = EFFECT_MIN;
  desc[eParam_effect2].max = EFFECT_MAX;
  desc[eParam_effect2].radix = EFFECT_RADIX;

  strcpy(desc[eParam_auxL3].label, "auxL3");
  desc[eParam_auxL3].type = eParamTypeAmp; 
  desc[eParam_auxL3].min = 0x00000000; 
  desc[eParam_auxL3].max = FR32_MAX;
  desc[eParam_auxL3].radix = 1;

  strcpy(desc[eParam_auxR3].label, "auxR3");
  desc[eParam_auxR3].type = eParamTypeAmp; 
  desc[eParam_auxR3].min = 0x00000000; 
  desc[eParam_auxR3].max = FR32_MAX;
  desc[eParam_auxR3].radix = 1;

  strcpy(desc[eParam_pan3].label, "pan3");
  desc[eParam_pan3].type = PAN_TYPE; 
  desc[eParam_pan3].min = PAN_MIN; 
  desc[eParam_pan3].max = PAN_MAX;
  desc[eParam_pan3].radix = PAN_RADIX;

  strcpy(desc[eParam_fader3].label, "fader3");
  desc[eParam_fader3].type = eParamTypeAmp; 
  desc[eParam_fader3].min = 0x00000000; 
  desc[eParam_fader3].max = FR32_MAX;
  desc[eParam_fader3].radix = 1;

  strcpy(desc[eParam_effect3].label, "effect3");
  desc[eParam_effect3].type = EFFECT_TYPE;
  desc[eParam_effect3].min = EFFECT_MIN;
  desc[eParam_effect3].max = EFFECT_MAX;
  desc[eParam_effect3].radix = EFFECT_RADIX;

  strcpy(desc[eParam_pitchshift0].label, "pitchshift0");
  desc[eParam_pitchshift0].type = PITCHSHIFT_TYPE;
  desc[eParam_pitchshift0].min = PITCHSHIFT_MIN;
  desc[eParam_pitchshift0].max = PITCHSHIFT_MAX;
  desc[eParam_pitchshift0].radix = PITCHSHIFT_RADIX;

  strcpy(desc[eParam_pitchshift0slew].label, "slew0");
  desc[eParam_pitchshift0slew].type = eParamTypeIntegrator;
  desc[eParam_pitchshift0slew].min = 0x00000000;
  desc[eParam_pitchshift0slew].max = 0x7fffffff;
  desc[eParam_pitchshift0slew].radix = 32;

  strcpy(desc[eParam_pitchshift1].label, "pitchshift1");
  desc[eParam_pitchshift1].type = PITCHSHIFT_TYPE;
  desc[eParam_pitchshift1].min = PITCHSHIFT_MIN;
  desc[eParam_pitchshift1].max = PITCHSHIFT_MAX;
  desc[eParam_pitchshift1].radix = PITCHSHIFT_RADIX;

  strcpy(desc[eParam_pitchshift1slew].label, "slew1");
  desc[eParam_pitchshift1slew].type = eParamTypeIntegrator; 
  desc[eParam_pitchshift1slew].min = 0x00000000; 
  desc[eParam_pitchshift1slew].max = 0x7fffffff;
  desc[eParam_pitchshift1slew].radix = 32;

  strcpy(desc[eParam_pitchshift2].label, "pitchshift2");
  desc[eParam_pitchshift2].type = PITCHSHIFT_TYPE;
  desc[eParam_pitchshift2].min = PITCHSHIFT_MIN;
  desc[eParam_pitchshift2].max = PITCHSHIFT_MAX;
  desc[eParam_pitchshift2].radix = PITCHSHIFT_RADIX;

  strcpy(desc[eParam_pitchshift2slew].label, "slew2");
  desc[eParam_pitchshift2slew].type = eParamTypeIntegrator; 
  desc[eParam_pitchshift2slew].min = 0x00000000; 
  desc[eParam_pitchshift2slew].max = 0x7fffffff;
  desc[eParam_pitchshift2slew].radix = 32;

  strcpy(desc[eParam_pitchshift3].label, "pitchshift3");
  desc[eParam_pitchshift3].type = PITCHSHIFT_TYPE;
  desc[eParam_pitchshift3].min = PITCHSHIFT_MIN;
  desc[eParam_pitchshift3].max = PITCHSHIFT_MAX;
  desc[eParam_pitchshift3].radix = PITCHSHIFT_RADIX;

  strcpy(desc[eParam_pitchshift3slew].label, "slew3");
  desc[eParam_pitchshift3slew].type = eParamTypeIntegrator; 
  desc[eParam_pitchshift3slew].min = 0x00000000; 
  desc[eParam_pitchshift3slew].max = 0x7fffffff;
  desc[eParam_pitchshift3slew].radix = 32;

}

// EOF
