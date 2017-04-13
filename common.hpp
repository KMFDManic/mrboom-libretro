#ifndef COMMON_H__
#define COMMON_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#define GAME_NAME          "Mr.Boom"
#define GAME_VERSION       "3.2"
#define PATH_MAX_LENGTH    256
#define WIDTH              320
#define HEIGHT             200
#define NB_COLORS_PALETTE  256
#define nb_dyna            8

enum Button {
	button_b,
	button_y,
	button_select,
	button_start,
	button_up,
	button_down,
	button_left,
	button_right,
	button_a,
	button_x,
	button_l,
	button_r,
	button_error
};

#define FIRST_RW_VARIABLE replayer_saver
#define FIRST_RW_VARIABLE_DB nosetjmp
#define NB_DD_VARIABLES_IN_RW_SEGMENT (offsetof(struct Mem,FIRST_RW_VARIABLE_DB)-offsetof(struct Mem,FIRST_RW_VARIABLE))/4
#define FIRST_RO_VARIABLE master
#define SIZE_RO_SEGMENT offsetof(struct Mem,FIRST_RW_VARIABLE)-offsetof(struct Mem,FIRST_RO_VARIABLE)
#define SIZE_SER offsetof(struct Mem,selectorsPointer)-offsetof(struct Mem,FIRST_RW_VARIABLE)
bool mrboom_init();
void mrboom_deinit(void);
void mrboom_update_input(int keyid,int playerNumber,int state,bool isIA);
void mrboom_play_fx(void);
bool mrboom_debug_state_failed();
void mrboom_reset_special_keys();
void mrboom_tick_ai();
extern bool cheatMode;

#ifdef __LIBRETRO__
#include <libretro.h>
#define FPS_RATE 60.0
#define SAMPLE_RATE 48000.0f
extern int16_t *frame_sample_buf;
extern uint32_t num_samples_per_frame;
extern retro_audio_sample_batch_t audio_batch_cb;
void audio_callback(void);
#endif
#ifdef __cplusplus
}
#endif
#endif