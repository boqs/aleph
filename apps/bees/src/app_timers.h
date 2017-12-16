#ifndef _ALEPH_AVR32_APP_TIMERS_H_
#define _ALEPH_AVR32_APP_TIMERS_H_

#include "timers.h"
#include "types.h"
#include "util.h"
EXTERN_C_BEGIN


//! if set, poll and display CPU use of DSP
#if RELEASEBULD==1
#define POLL_DSP_CPU 0
#else
#define POLL_DSP_CPU 1
#endif

//! create application timers
extern void init_app_timers(void);

//! start monome polling/refresh timers
extern void timers_set_monome(void);

//! stop monome polling/refresh timers
extern void timers_unset_monome(void);

//! start midi polling/refresh timers
extern void timers_set_midi(void);

//! stop midi polling/refresh timers
extern void timers_unset_midi(void);

//! start adc polling timer
extern void timers_set_adc(u32 period);

//! stop adc polling timer
extern void timers_unset_adc(void);

//! change period of adc polling timer
extern void timers_set_adc_period(u32 period);

//! start hid polling timer
extern void timers_set_hid(void);

//! stop hid polling timer
extern void timers_unset_hid(void);

//! change period of hid polling timer
extern void timers_set_hid_period(u32 period);

//! set metro timer
//! arguments: 
//! - pointer to timer data,
//! - period in ticks
//! - pointer to polled operator class data
extern void timers_set_custom(softTimer_t* timer, u32 period, void* obj);

//! unset metro timer
extern void timers_unset_custom(softTimer_t* timer);
extern s32 timers_ms_tick_to_libavr32_tick (s16 ticks_2ms);
extern s16 timers_libavr32_tick_to_ms_tick (s32 ticks_libavr32);
EXTERN_C_END

#endif
