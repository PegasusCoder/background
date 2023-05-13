#ifndef BCK_H_INCLUDED
#define BCK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 00

typedef struct  {
    SDL_Surface *image;
    SDL_Rect camera;
} Background;

void init(SDL_Surface **screen) ;
void initmusic(Mix_Music **music);
void init_background(Background *background, SDL_Surface *image,SDL_Rect *pos,SDL_Rect *pos1,Background *back2, SDL_Surface *image2,SDL_Rect *posb,Background *background1, SDL_Surface *image1) ;
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination) ;
void scan(FILE **fp,int *num1,int *num2,int *num3);
void verifiemaxscore(int *score,int *num1,int *num2,int *num3);
void read(FILE **X,int *num1,int *num2,int *num3);
void afichage(int num1,int num2,int num3,TTF_Font* font,SDL_Color textColor,SDL_Surface *screen);
void initpos(SDL_Rect *pos,SDL_Rect *pos1,SDL_Rect *posb);
#endif
