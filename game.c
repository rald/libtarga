#include <stdio.h>
#include <stdlib.h>

#include "libtarga.h"

int palette_numcolors=5;
int palette_colors[]={
	  0,  0,  0,  0,
	  0,  0,  0,255,
	103,103,103,255,
	182,182,182,255,
	255,255,255,255
};

int sprite_width=8;
int sprite_height=8;
int sprite_pixels[]={
	4,4,4,4,4,4,4,4,
	4,4,0,0,0,0,0,4,
	4,0,4,0,0,0,0,4,
	4,0,0,4,0,0,0,4,
	4,0,0,0,0,0,0,4,
	4,0,0,0,0,0,0,4,
	4,0,0,0,0,0,0,4,
	4,4,4,4,4,4,4,4
};

int getrgba(int *palette,int i,int *r,int *g,int *b,int *a) {
	*r=palette[i*4+0];
	*g=palette[i*4+1];
	*b=palette[i*4+2];
	*a=palette[i*4+3];
}

int main() {

	unsigned char *tga=tga_create(sprite_width,sprite_height,TGA_TRUECOLOR_32);

	if (tga==NULL) {
	  printf("Failed to create image!\n");
	  printf(tga_error_string(tga_get_last_error()));
	}

	for(int j=0;j<sprite_height;j++) {
		for(int i=0;i<sprite_width;i++) {

			int x=i;
			int y=sprite_height-j-1;

			int r,g,b,a;

			getrgba(palette_colors,sprite_pixels[i+j*sprite_width],&r,&g,&b,&a);

			tga[(x+y*sprite_width)*4+0]=r;
			tga[(x+y*sprite_width)*4+1]=g;
			tga[(x+y*sprite_width)*4+2]=b;
			tga[(x+y*sprite_width)*4+3]=a;
		}
	}

	if(!tga_write_raw("output.tga",sprite_width,sprite_height,tga,TGA_TRUECOLOR_32)) {
		printf("Failed to write image!\n");
		printf(tga_error_string(tga_get_last_error()));
	}

	free(tga);

	return 0;
}

