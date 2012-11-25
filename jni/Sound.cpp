#include "gl_code.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void LoadSoundFile(const char *filename,short **buffer,size_t *size) {
    FILE *data = NULL;
    struct stat st;

    //LOGI("Loading %s",filename);

    if(0 != stat(filename,&st))
        throw FILE_NOT_FOUND;

    *buffer = (short int *)malloc(st.st_size);
    if(NULL == *buffer)
        throw MEMORY_ERROR;

    data = fopen(filename,"rb");
    if(NULL == data) 
        throw FILE_NOT_FOUND;
    
    if(st.st_size != fread(*buffer,1,st.st_size,data)) {
        free(*buffer);
        *buffer = NULL;
        throw FILE_ERROR;
    }

    *size = st.st_size;
}

SoundClip::SoundClip(const char *filename) {
    LoadSoundFile(filename,&buffer,&size);
}

SoundClip::~SoundClip() {
    if(NULL != buffer) 
        free(buffer);
}

void SoundClip::GetBuffer(short **out,size_t *outs) {
    *out = buffer;
    *outs = size;
}

RandomSoundClip::RandomSoundClip(char **filename) {
    buffer = NULL;
    size   = NULL;
    count = 0;
    try {
        if(NULL == filename)
            throw MEMORY_ERROR;
        //count how many we want
        for(char **p = filename; *p; p++)
            count ++;

        LOGI("Got %u rs filenames",count);

        if(count > 256)
            throw MEMORY_ERROR;

        buffer = (short **)malloc(sizeof(short*)*count);
        if(NULL == buffer)
            throw MEMORY_ERROR;
        memset(buffer,0,sizeof(short*)*count);

        size   = (size_t*)malloc(sizeof(size_t)*count);
        if(NULL == size)
            throw MEMORY_ERROR;
        memset(size,0,sizeof(size_t)*count);
        int i = 0;
        for(char **p = filename; *p; p++,i++) 
            LoadSoundFile(*p,&(buffer[i]),&(size[i]));
    }
    catch (error e) {
        if(NULL != buffer) {
            for(int i=0;i<count;i++) {
                if(NULL != buffer[i]) {
                    free(buffer[i]);
                    buffer[i] = NULL;
                }
            }
            free(buffer);
            buffer = NULL;
        }
        if(NULL != size) {
            free(size);
            size = NULL;
        }
        throw e;
    }
}

RandomSoundClip::~RandomSoundClip() {
    if(NULL != buffer) {
        for(int i=0;i<count;i++) {
            if(NULL != buffer[i]) {
                free(buffer[i]);
                buffer[i] = NULL;
            }
        }
        free(buffer);
        buffer = NULL;
    }
    if(NULL != size) {
        free(size);
        size = NULL;
    }
}

void RandomSoundClip::GetBuffer(short **outbuffer, size_t *outsize) {
    unsigned long val = lrand48();
    val = val%count;
    //LOGI("Choosing item %d",val);
    
    *outbuffer = buffer[val];
    *outsize   = size[val];
}

void PlayClip(SoundClip &sc,int queue,int q) {
    short *buffer;
    size_t size;
    sc.GetBuffer(&buffer,&size);
    if(NULL != buffer)
        PlayClip_c(buffer,size,queue,q);
}
