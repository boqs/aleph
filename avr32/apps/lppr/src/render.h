#ifndef _ALEPH_APP_LPPR_RENDER_H_
#define _ALEPH_APP_LPPR_RENDER_H_


// init
extern void render_init(void);
// update
extern void render_update(void);
// force refresh
extern void render_force_refresh(void);

// render text to statusbar
void render_status(const char* str);

// fill with initial graphics (id strings)
void render_startup(void);

// draw text in a region
// extern void 

// draw a buffer in a quadrant
//extern void render_quad(u8 quad, u8* data);

// draw switch-on
 extern void render_sw_on(u8 sw, u8 on);

// draw delay time
extern void render_delay_time(u8 id, u32 ms, u32 samps);

/* // render milliseconds */
/* extern void render_ms(u8 x, u8 y, u32 ms); */

/* // render text */
/* extern void render_txt(u8 x, u8 y, char* txt); */

/* // render fixed-point number */
/* extern void render_fix(u8 x, u8 y, fix16 val); */
  
#endif // h guard
