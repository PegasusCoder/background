#include"fonction.h"


void init(SDL_Surface **screen)
{
*screen = SDL_SetVideoMode(1200, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(!screen) {
        fprintf(stderr, "Failed to set video mode: %s\n", SDL_GetError());
    }
}

void initmusic(Mix_Music **music)
{
  *music = Mix_LoadMUS("sing.mp3");
    if(!*music) {
        fprintf(stderr, "Failed to load music: %s\n", Mix_GetError());

    }
Mix_PlayMusic(*music, -1);
    
}
void init_background(Background *background, SDL_Surface *image,SDL_Rect *pos,SDL_Rect *pos1,Background *back2, SDL_Surface *image2,SDL_Rect *posb,Background *background1, SDL_Surface *image1) {
image = IMG_Load("back.png");
    if(!image) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
    }
    background->image = image;
    background->camera.x = 0;
    background->camera.y = 250;
    background->camera.w = 1200;
    background->camera.h =500;




image1 = IMG_Load("STAGE.png");
    if(!image1) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
    }
    background1->image = image1;
    background1->camera.x = 0;
    background1->camera.y = 0;
    background1->camera.w = 200;
    background1->camera.h =200;



image2 = IMG_Load("back.png");
    if(!image) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
    }
    back2->image = image2;
    back2->camera.x = 0;
    back2->camera.y = 250;
    back2->camera.w = 600;
    back2->camera.h =500;
initpos(pos,pos1,posb);
}
void scan(FILE **fp,int *num1,int *num2,int *num3)
{
    fscanf(*fp, "%d,%d,%d", num1, num2, num3);
}
void verifiemaxscore(int *score,int *num1,int *num2,int *num3)
{
	 // Check if the value is one of the top three numbers
    if (*score > *num1 || *score > *num2 || *score > *num3) 
{
        // Shift the numbers down if necessary
        if (*score > *num1) 
	{
            *num3 = *num2;
            *num2 = *num1;
            *num1 = *score;
        } 
	else if (*score > *num2) 
	{
            *num3 = *num2;
            *num2 = *score;
        } 
	else 
            *num3 = *score;
        
}
}
void afichage(int num1,int num2,int num3,TTF_Font* font,SDL_Color textColor,SDL_Surface *screen)
{
char str1[10], str2[10], str3[10];
sprintf(str1, "%d", num1);
sprintf(str2, "%d", num2);
sprintf(str3, "%d", num3);

// Render the text for num1
SDL_Surface* num1TextSurface = TTF_RenderText_Solid(font, str1, textColor);

// Render the text for num2
SDL_Surface* num2TextSurface = TTF_RenderText_Solid(font, str2, textColor);

// Render the text for num3
SDL_Surface* num3TextSurface = TTF_RenderText_Solid(font, str3, textColor);

// Blit the text surfaces onto the screen surface
SDL_Rect num1Rect = { 40, 100, num1TextSurface->w, num1TextSurface->h };
SDL_BlitSurface(num1TextSurface, NULL, screen, &num1Rect);

SDL_Rect num2Rect = {40, 130, num2TextSurface->w, num2TextSurface->h };
SDL_BlitSurface(num2TextSurface, NULL, screen, &num2Rect);

SDL_Rect num3Rect = { 40, 160, num3TextSurface->w, num3TextSurface->h };
SDL_BlitSurface(num3TextSurface, NULL, screen, &num3Rect);

}
void initpos(SDL_Rect *pos,SDL_Rect *pos1,SDL_Rect *posb)
{
pos->x=0;
pos->y=0;
pos->h=500;
pos->w=1200;
pos1->x=0;
pos1->y=100;
pos1->h=200;
pos1->w=200;

posb->x=600;
posb->y=0;
posb->h=500;
posb->w=600;
}
