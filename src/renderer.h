#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct RenFont RenFont;
typedef enum { FONT_HINTING_NONE, FONT_HINTING_SLIGHT, FONT_HINTING_FULL } ERenFontHinting;
typedef enum { FONT_STYLE_BOLD = 1, FONT_STYLE_ITALIC = 2, FONT_STYLE_UNDERLINE = 4 } ERenFontStyle;
typedef struct { uint8_t b, g, r, a; } RenColor;
typedef struct { int x, y, width, height; } RenRect;

RenFont* ren_font_load(const char *filename, float size, bool subpixel, unsigned char hinting, unsigned char style);
RenFont* ren_font_copy(RenFont* font, float size);
void ren_font_free(RenFont *font);
void ren_font_set_tab_size(RenFont *font, int n);
int ren_font_get_tab_size(RenFont *font);
float ren_font_get_width(RenFont *font, const char *text);
int ren_font_get_height(RenFont *font);
float ren_font_get_size(RenFont *font);
float ren_draw_text(RenFont *font, const char *text, float x, int y, RenColor color);

void ren_draw_rect(RenRect rect, RenColor color);

void ren_init(SDL_Window *win);
void ren_resize_window();
void ren_update_rects(RenRect *rects, int count);
void ren_set_clip_rect(RenRect rect);
void ren_get_size(int *x, int *y); /* Reports the size in points. */
void ren_free_window_resources();


#endif
