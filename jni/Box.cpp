#include "gl_code.h"
#include <unistd.h>


Box::Box(GLfloat _width,GLfloat _height, GLfloat _thickness) {
    width          = _width*480/800;
    height         = _height;
    thickness      = _thickness*480/800;

    
    GLshort indicies[] = {0,1,2,3};
    memcpy(mIndexBuffer,indicies,sizeof(mIndexBuffer));
    memcpy(mTexBuffer,standard_tex_coords,sizeof(mTexBuffer));

    
    GLfloat coords[] = {
        // X, Y, Z
        0, 0, 0,
        0, height, 0,
        width, height, 0,
        width, 0, 0
    };

    //top bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = height-thickness;
    coords[ 0] = coords[ 3] = 0;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer,coords,4*3*sizeof(GLfloat));

    //right bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = 0;
    coords[ 0] = coords[ 3] = width-thickness;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer+4*3,coords,4*3*sizeof(GLfloat));

    //bottom bar
    coords[ 4] = coords[ 7] = 0;
    coords[ 1] = coords[10] = thickness;
    coords[ 0] = coords[ 3] = 0;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer+8*3,coords,4*3*sizeof(GLfloat));

    //left bar
    coords[ 4] = coords[ 7] = 0;
    coords[ 1] = coords[10] = height;
    coords[ 0] = coords[ 3] = 0;
    coords[ 6] = coords[ 9] = thickness;
    memcpy(mFVertexBuffer+12*3,coords,4*3*sizeof(GLfloat));

}

HalfBox::HalfBox(GLfloat _width,GLfloat _height, GLfloat _thickness) {
    width          = _width*480/800;
    height         = _height;
    thickness      = _thickness*480/800;

    
    GLshort indicies[] = {0,1,2,3};
    memcpy(mIndexBuffer,indicies,sizeof(mIndexBuffer));
    memcpy(mTexBuffer,standard_tex_coords,sizeof(mTexBuffer));

    
    GLfloat coords[] = {
        // X, Y, Z
        0, 0, 0,
        0, height, 0,
        width, height, 0,
        width, 0, 0
    };

    //top bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = height-thickness;
    coords[ 0] = coords[ 3] = 0;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer,coords,4*3*sizeof(GLfloat));

    //right bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = 0;
    coords[ 0] = coords[ 3] = width-thickness;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer+4*3,coords,4*3*sizeof(GLfloat));

}

ItemConditionBar::ItemConditionBar(GLfloat _value) {
    width          = 0.1*480/800;
    height         = 0.035;
    value          = _value;
    
    GLshort indicies[] = {0,1,2,3};
    memcpy(mIndexBuffer,indicies,sizeof(mIndexBuffer));
    memcpy(mTexBuffer,standard_tex_coords,sizeof(mTexBuffer));

    
    GLfloat coords[] = {
        // X, Y, Z
        0, 0, 0,
        0, height, 0,
        width*value, height, 0,
        width*value, 0, 0
    };

    GLfloat coords1[] = {
        // X, Y, Z
        width*value, 0, 0,
        width*value, height, 0,
        width, height, 0,
        width, 0, 0
    };

    memcpy(mFVertexBuffer,coords,4*3*sizeof(GLfloat));
    memcpy(mFVertexBuffer+4*3,coords1,4*3*sizeof(GLfloat));

}

void ItemConditionBar::SetSize(GLfloat _value) {
    width          = 0.1*480/800;
    height         = 0.035;
    value          = _value;
    
    GLshort indicies[] = {0,1,2,3};
    memcpy(mIndexBuffer,indicies,sizeof(mIndexBuffer));
    memcpy(mTexBuffer,standard_tex_coords,sizeof(mTexBuffer));

    
    GLfloat coords[] = {
        // X, Y, Z
        0, 0, 0,
        0, height, 0,
        width*value, height, 0,
        width*value, 0, 0
    };

    GLfloat coords1[] = {
        // X, Y, Z
        width*value, 0, 0,
        width*value, height, 0,
        width, height, 0,
        width, 0, 0
    };

    memcpy(mFVertexBuffer,coords,4*3*sizeof(GLfloat));
    memcpy(mFVertexBuffer+4*3,coords1,4*3*sizeof(GLfloat));

}

//copy paste <OMG>
void HalfBox::SetSize(GLfloat _width,GLfloat _height,GLfloat _thickness) {
    width          = _width*480/800;
    height         = _height;
    thickness      = _thickness*480/800;

    
    GLshort indicies[] = {0,1,2,3};
    memcpy(mIndexBuffer,indicies,sizeof(mIndexBuffer));
    memcpy(mTexBuffer,standard_tex_coords,sizeof(mTexBuffer));

    
    GLfloat coords[] = {
        // X, Y, Z
        0, 0, 0,
        0, height, 0,
        width, height, 0,
        width, 0, 0
    };

    //top bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = height-thickness;
    coords[ 0] = coords[ 3] = 0;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer,coords,4*3*sizeof(GLfloat));

    //right bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = 0;
    coords[ 0] = coords[ 3] = width-thickness;
    coords[ 6] = coords[ 9] = width;
    memcpy(mFVertexBuffer+4*3,coords,4*3*sizeof(GLfloat));
}

ConditionBar::ConditionBar(GLfloat _value, ConditionBarType _type) {
    GLshort indicies[] = {0,1,2,3};
    memcpy(mIndexBuffer,indicies,sizeof(mIndexBuffer));
    memcpy(mTexBuffer,standard_tex_coords,sizeof(mTexBuffer));
    value  = _value;
    type   = _type;
    height = 0.038;
    width  = 0.14*480/800;
    thickness = 0.007*480/800;

    GLfloat coords[] = {
        // X, Y, Z
        0, 0, 0,
        0, height, 0,
        width, height, 0,
        width, 0, 0
    };

    //left bar
    if(type == cb_plain || type == cb_pointright) {
        coords[ 4] = coords[ 7] = 0;
        coords[ 1] = coords[10] = height;
        coords[ 0] = coords[ 3] = 0;
        coords[ 6] = coords[ 9] = thickness;
    }
    else
    {
        coords[ 4] = coords[ 7] = height;
        coords[ 1] = coords[10] = 0;
        coords[ 0] = coords[ 3] = width-thickness;
        coords[ 6] = coords[ 9] = width;
    }
    memcpy(mFVertexBuffer,coords,4*3*sizeof(GLfloat));

    //top bar
    coords[ 4] = coords[ 7] = height;
    coords[ 1] = coords[10] = height-thickness;
    if(type == cb_plain) {
        coords[ 0] = coords[ 3] = 0;
        coords[ 6] = coords[ 9] = width;
    }
    else if(type == cb_pointleft) {
        coords[ 0] = coords[ 3] = -0.18*width;
        coords[ 6] = coords[ 9] = width;
    }
    else if(type == cb_pointright) {
        coords[ 0] = coords[ 3] = 0;
        coords[ 6] = coords[ 9] = 1.18*width;
    }
    memcpy(mFVertexBuffer+4*3,coords,4*3*sizeof(GLfloat));

    if(type == cb_plain) {
        coords[ 4] = coords[ 7] = height;
        coords[ 1] = coords[10] = 0;
        coords[ 0] = coords[ 3] = width-thickness;
        coords[ 6] = coords[ 9] = width;
        memcpy(mFVertexBuffer+12*3,coords,4*3*sizeof(GLfloat));
    }

    //The actual bar:
    coords[ 4] = coords[ 7] = 0;
    coords[ 1] = coords[10] = height - 2*thickness;
    coords[ 0] = coords[ 3] = 2*thickness*0.75;
    coords[ 6] = coords[ 9] = width-2*thickness*0.75;
    memcpy(mFVertexBuffer+8*3,coords,4*3*sizeof(GLfloat));

    if(type == cb_pointleft) {
        memset(coords,0,sizeof(coords));
        coords[4] = coords[7] = height;
        coords[1] = 0.35*height;
        coords[0] = coords[3] = thickness;
        coords[6] = -width*0.1;
        memcpy(mFTriangleBuffer,coords,3*3*sizeof(GLfloat));
    }
    if(type == cb_pointright) {
        memset(coords,0,sizeof(coords));
        coords[4] = coords[7] = height;
        coords[1] = 0.35*height;
        coords[0] = coords[3] = width-thickness;
        coords[6] = width*1.1;
        memcpy(mFTriangleBuffer,coords,3*3*sizeof(GLfloat));
    }
        
}

void ConditionBar::Draw(GLfloat x,GLfloat y,GLfloat xscale, GLfloat yscale) {
    int i;
    for(i=0;i<((type == cb_plain) ? 4 : 3);i++) {
        glLoadIdentity();checkGlError(__LINE__);
        glTranslatef(x,y,0);checkGlError(__LINE__);

        glBindTexture(GL_TEXTURE_2D, white_texture);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_REPEAT);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_REPEAT);

        glFrontFace(GL_CCW);checkGlError(__LINE__);

        glVertexPointer(3,GL_FLOAT, 0, mFVertexBuffer+i*12);checkGlError(__LINE__);
 
        glEnable(GL_TEXTURE_2D);checkGlError(__LINE__);

        glTexCoordPointer(2, GL_FLOAT, 0, mTexBuffer);checkGlError(__LINE__);

        glDrawElements(GL_TRIANGLE_FAN, 4,
                       GL_UNSIGNED_SHORT, mIndexBuffer);checkGlError(__LINE__);

    }

    if(type == cb_pointleft || type == cb_pointright) {
        glLoadIdentity();checkGlError(__LINE__);
        glTranslatef(x,y,0);checkGlError(__LINE__);

        glBindTexture(GL_TEXTURE_2D, white_texture);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_REPEAT);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_REPEAT);

        glFrontFace(GL_CCW);checkGlError(__LINE__);

        glVertexPointer(3,GL_FLOAT, 0, mFTriangleBuffer);checkGlError(__LINE__);
 
        glEnable(GL_TEXTURE_2D);checkGlError(__LINE__);

        glTexCoordPointer(2, GL_FLOAT, 0, mTexBuffer);checkGlError(__LINE__);

        glDrawElements(GL_TRIANGLE_FAN, 3,
                       GL_UNSIGNED_SHORT, mIndexBuffer);checkGlError(__LINE__);
    }
}


void Box::Draw(GLfloat x,GLfloat y,GLfloat xscale, GLfloat yscale) {

    int i;
    for(i=0;i<4;i++) {
        glLoadIdentity();checkGlError(__LINE__);
        glTranslatef(x,y,0);checkGlError(__LINE__);

        glBindTexture(GL_TEXTURE_2D, white_texture);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_REPEAT);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_REPEAT);

        glFrontFace(GL_CCW);checkGlError(__LINE__);

        glVertexPointer(3,GL_FLOAT, 0, mFVertexBuffer+i*12);checkGlError(__LINE__);
 
        glEnable(GL_TEXTURE_2D);checkGlError(__LINE__);

        glTexCoordPointer(2, GL_FLOAT, 0, mTexBuffer);checkGlError(__LINE__);

        glDrawElements(GL_TRIANGLE_FAN, 4,
                       GL_UNSIGNED_SHORT, mIndexBuffer);checkGlError(__LINE__);

    }
}

void HalfBox::Draw(GLfloat x,GLfloat y,GLfloat xscale, GLfloat yscale) {

    int i;
    GLuint texts[] = {white_texture,fade->texture};
    
    for(i=0;i<2;i++) {
        glLoadIdentity();checkGlError(__LINE__);
        glTranslatef(x,y,0);checkGlError(__LINE__);

        glBindTexture(GL_TEXTURE_2D, texts[i]);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_REPEAT);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_REPEAT);

        glFrontFace(GL_CCW);checkGlError(__LINE__);

        glVertexPointer(3,GL_FLOAT, 0, mFVertexBuffer+i*12);checkGlError(__LINE__);
 
        glEnable(GL_TEXTURE_2D);checkGlError(__LINE__);

        glTexCoordPointer(2, GL_FLOAT, 0, mTexBuffer);checkGlError(__LINE__);

        glDrawElements(GL_TRIANGLE_FAN, 4,
                       GL_UNSIGNED_SHORT, mIndexBuffer);checkGlError(__LINE__);

    }
}

void ItemConditionBar::Draw(GLfloat x,GLfloat y,GLfloat xscale, GLfloat yscale) {

    int i;
    GLuint texts[] = {white_texture,grey_texture};
    
    for(i=0;i<2;i++) {
        glLoadIdentity();checkGlError(__LINE__);
        glTranslatef(x,y,0);checkGlError(__LINE__);

        glBindTexture(GL_TEXTURE_2D, texts[i]);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                        GL_REPEAT);
        glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                        GL_REPEAT);

        glFrontFace(GL_CCW);checkGlError(__LINE__);

        glVertexPointer(3,GL_FLOAT, 0, mFVertexBuffer+i*12);checkGlError(__LINE__);
 
        glEnable(GL_TEXTURE_2D);checkGlError(__LINE__);

        glTexCoordPointer(2, GL_FLOAT, 0, mTexBuffer);checkGlError(__LINE__);

        glDrawElements(GL_TRIANGLE_FAN, 4,
                       GL_UNSIGNED_SHORT, mIndexBuffer);checkGlError(__LINE__);

    }
}
