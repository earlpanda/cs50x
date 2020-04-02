#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        float average_value = 0;
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed != image[i][j].rgbtGreen || image[i][j].rgbtGreen != image[i][j].rgbtBlue
            || image[i][j].rgbtBlue != image[i][j].rgbtRed)
            {
                average_value = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue) / 3);
            }

            else
            {
                continue;
            }

            image[i][j].rgbtRed = average_value;
            image[i][j].rgbtGreen = average_value;
            image[i][j].rgbtBlue = average_value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed = 0, sepiaGreen = 0, sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * (float)image[i][j].rgbtRed + .769 * (float)image[i][j].rgbtGreen + .189 * (float)image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = round(.349 * (float)image[i][j].rgbtRed + .686 * (float)image[i][j].rgbtGreen + .168 * (float)image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = round(.272 * (float)image[i][j].rgbtRed + .534 * (float)image[i][j].rgbtGreen + .131 * (float)image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = round((float)width / 2); j < k; j++)
        {
            RGBTRIPLE temp = image[i][width - 1 - j];
            image[i][width - 1 - j] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blur_function(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB);
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blur_function(i, j, height, width, tmp, 0);
            image[i][j].rgbtGreen = blur_function(i, j, height, width, tmp, 1);
            image[i][j].rgbtBlue = blur_function(i, j, height, width, tmp, 2);
        }
    }
    return;
}

int blur_function(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB)
{
    float counter = 0;
    int sum = 0;
    for (int a = i - 1; a < (i + 2); a++)
    {
        for (int b = j - 1; b < (j + 2); b++)
        {
            if (a < 0 || b < 0 || a >= height || b >= width)
            {
                continue;
            }

            else
            {
                if (RGB == 0)
                {
                    sum += image[a][b].rgbtRed;
                }
                else if (RGB == 1)
                {
                    sum += image[a][b].rgbtGreen;
                }
                else if (RGB == 2)
                {
                    sum += image[a][b].rgbtBlue;
                }

                counter++;
            }
        }
    }

    return (int)round(sum / counter);

}