#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {

  int fd=open("image.ppm",O_CREAT|O_WRONLY,0644);
  int r,g,b,i,j;
  r=255;
  g=0;
  b=255;
  char buff[100];
  

  int y=1;
  int z=1;
  write(fd,"P3\n500 500\n255\n", strlen("P3\n500 500\n255\n"));
  i=0;
  for (;i<500;i++) {

    
    j=0;
    if (g==255) {
      y=0;
      g--;
    }
    else if (y) g++;    
    else g--;

    for (;j<500;j++) {
      if (r==0) {
	z=0;
	r++;
      }
      else if (z) r--;    
      else r++;
      sprintf(buff,"%d %d %d\n",r,g,b);
      write(fd,buff,strlen(buff));
    }
    r=255;
    z=1;
  }

  
  
  //printf("buff: [%s]\n | strlen(buff): %d\n",buff,strlen(buff));
  //write(fd,buff,strlen(buff)-1);
  close(fd);

  return 0;
}
