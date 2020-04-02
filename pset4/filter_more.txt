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

// Detect edges
int Gx_ker[3][3] =
{
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};
int Gy_ker[3][3] =
{
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
};

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx_function(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB);
    int Gy_function(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB);
    int square_function(int a, int b);

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
            image[i][j].rgbtRed = square_function(Gx_function(i, j, height, width, tmp, 0), Gy_function(i, j, height, width, tmp, 0));
            image[i][j].rgbtGreen = square_function(Gx_function(i, j, height, width, tmp, 1), Gy_function(i, j, height, width, tmp, 1));
            image[i][j].rgbtBlue = square_function(Gx_function(i, j, height, width, tmp, 2), Gy_function(i, j, height, width, tmp, 2));
        }
    }
    return;
}

int Gx_function(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB)
{
    int counter = 0;
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
                    counter += image[a][b].rgbtRed * Gx_ker[a + 1 - i][b + 1 - j];
                }
                if (RGB == 1)
                {
                    counter += image[a][b].rgbtGreen * Gx_ker[a + 1 - i][b + 1 - j];
                }
                if (RGB == 2)
                {
                    counter += image[a][b].rgbtBlue * Gx_ker[a + 1 - i][b + 1 - j];
                }
            }
        }
    }
    return counter;
}

int Gy_function(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB)
{
    int counter = 0;
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
                    counter += image[a][b].rgbtRed * Gy_ker[a + 1 - i][b + 1 - j];
                }
                if (RGB == 1)
                {
                    counter += image[a][b].rgbtGreen * Gy_ker[a + 1 - i][b + 1 - j];
                }
                if (RGB == 2)
                {
                    counter += image[a][b].rgbtBlue * Gy_ker[a + 1 - i][b + 1 - j];
                }
            }
        }
    }
    return counter;
}

int square_function(int a, int b)
{
    int value = round(sqrt(a * a + b * b));
    if (value > 255)
    {
        value = 255;
    }
    return value;
}