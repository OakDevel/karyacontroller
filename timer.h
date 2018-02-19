#include "motion.h"

#include <stdint.h>
#define TMSCALE 1024L
extern int feedthedog();
#ifndef ISPC
#define timescale 1000000L

#else
#define timescale 1000000L
extern uint32_t micros();

#endif
#define SUBMOTION 1
#define timescaleLARGE timescale*TMSCALE



extern uint32_t	next_step_time;
extern void timer_init();
extern void timer_stop();
extern void timer_reset();
extern uint8_t timer_set(int32_t delay);


#ifndef MASK
  /// MASKING- returns \f$2^PIN\f$
  #define MASK(PIN) (1 << PIN)
#endif


#ifdef USETIMER1
#ifdef __AVR__
#define CLI cli();
#define SEI sei();
#define MEMORY_BARRIER()
#endif
#endif


#ifndef CLI
#define CLI
#define SEI
#define MEMORY_BARRIER()
#endif
