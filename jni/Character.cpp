#include "gl_code.h"

Character::Character(GeneralConfig &config) {
    char temp_path[1024]      = {0};
    heads      = new Image("head.png",0.25*480/800,0.25,standard_tex_coords);
    faces      = new Image("face.png",0.125*480/800,0.125,standard_tex_coords);
    left_legs  = new Image("left_leg.png",0.25*480/800,0.25,standard_tex_coords);
    right_legs = new Image("right_leg.png",0.25*480/800,0.25,standard_tex_coords);
    right_arms = new Image("right_arm.png",0.25*480/800,0.125,standard_tex_coords);
    left_arms  = new Image("left_arm.png",0.25*480/800,0.125,standard_tex_coords);
    torsos     = new Image("torso.png",0.25*480/800,0.25,standard_tex_coords);

    if(sizeof(temp_path) <= snprintf(temp_path,sizeof(temp_path),"%s - Level %d",config.name.c_str(),config.level)) {
        throw ErrorMessage(MEMORY_ERROR,"snprintf error in Character::Character");
    }
    temp_path[sizeof(temp_path)-1] = 0;
    title      = new Text(temp_path,font);
}

void Character::Draw (GLfloat x,GLfloat y,GLfloat xscale, GLfloat yscale) {
    heads->Draw(     x + 0.45  , y + 0.5, xscale,yscale);
    faces->Draw(     x + 0.47  , y + 0.58 ,xscale,yscale);
    torsos->Draw(    x + 0.434 , y + 0.295,xscale,yscale);
    left_legs->Draw( x + 0.5   , y + 0.085,xscale,yscale);
    right_legs->Draw(x + 0.38  , y + 0.092,xscale,yscale);
    left_arms->Draw( x + 0.558 , y + 0.445,xscale,yscale);
    right_arms->Draw(x + 0.305 , y + 0.456,xscale,yscale);

    title->Draw(x + 0.37,y + 0.080,1.5,1.5);
}
