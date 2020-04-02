#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage:./recover image \n");
        return 1;
    }

    //declare file name and other variables
    char *file = argv[1];
    BYTE buffer[512];
    int img_counter = 0;
    FILE *img;
    char *filename = malloc(8);

    //open file
    FILE *inptr = fopen(file, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "File %s not found.\n", file);
        return 2;
    }

    //Read a block of memory
    while (fread(&buffer, sizeof(BYTE), BLOCK_SIZE, inptr))
    {
        //check the first 4 bytes of the buffer block
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if found another JPEG, close the file
            if (img_counter > 0)
            {
                fclose(img);
            }

            //if found JPEG header, start a new file for writing, add 1 to the counter
            sprintf(filename, "%03i.jpg", img_counter);
            img = fopen(filename, "w");
            img_counter++;

        }
        //continue writing once found jpeg
        if (img_counter > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    free(filename);
    fclose(inptr);

    return 0;

}
