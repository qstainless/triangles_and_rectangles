/**
 * File:    triangles_and_rectangles.c
 *
 * Author:  Queue Stainless (qs9001006@gmail.com)
 * Date:    24 Sep 2021
 *
 * License: MIT
 *
 * Summary:
 *
 *      This program asks the user for the dimensions of three sides of a triangle.
 *      If the side dimensions can make a valid triangle, the program will use
 *      those valies to calculate the permiter and the area of the valid triangle.
 *      The program exits if it is not a valid triangle.
 *
 *      The program then asks the user for a width and length of a rectangle,
 *      calculates the area of the rectangle, and compares it to the area of the
 *      valid triangle.
 *
 *      Finally, the program informs the user which of the two areas is greater,
 *      or if they are the same.
 *
 * Requirements:
 *      - The length of the sides of the triangle must be integers between 1 and 100, inclusive
 *      - The width and length of the rectangle must be float or double
 *      - Use C math functions
 *      - All results must be rounded to one decimal place
 *
 * Program input:
 *      - Length of three sides of a triangle
 *      - Width and length of a rectangle
 *
 * Program output:
 *      - The perimeter and area of a valid triangle
 *      - The area of the rectangle
 *      - The comparison of both areas
 */

// Include required header files
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Function prototypes
 *
 * see https://www.tutorialspoint.com/importance-of-function-prototype-in-c
 *     https://www.learnconline.com/2010/03/function-prototype-in-c-language.html
 *     https://www.geeksforgeeks.org/what-is-the-purpose-of-a-function-prototype/
 */
double calculateTriangle();

double calculateRectangle();

int validateTriangleDimensions(int, int, int);

int validateTriangleSides(int, int, int);


// Main function
int main(void) {

    double triangle_area;
    double rectangle_area;

    printf("This program calculates the perimeter and area of a triangle and compares its"
           "area with the area of a rectangle.\n\n");

    // Process the perimeter and area of the triangle
    triangle_area = calculateTriangle();

    // Process the area of the rectangle
    rectangle_area = calculateRectangle();

    // Compare the area of the triangle with the area of the rectangle and display the results
    printf("The area of the triangle is ");

    if (triangle_area == rectangle_area) {

        printf("equal to");

    } else if (triangle_area > rectangle_area) {

        printf("greater than");

    } else {

        printf("less than");
    }

    printf(" the area of the rectangle.\n");
}

/**
 * Calculate the triangle's perimeter and area based on user input.
 * Uses Heron's Formula to calculate the area of the triangle
 *
 * @return The triangle area
 */
double calculateTriangle() {

    // Define variables
    int sideA;
    int sideB;
    int sideC;
    double s; // the triangle's semi-perimeter; used to calculate the area of the triangle
    double triangle_area;
    double triangle_perimeter;

    // Ask the user to input the triangle side lengths
    printf("Please enter a triangle's dimensions.\n");

    printf("Side A (1 - 100): ");
    scanf(" %d", &sideA);

    printf("Side B (1 - 100): ");
    scanf(" %d", &sideB);

    printf("Side C (1 - 100): ");
    scanf(" %d", &sideC);

    printf("\n");

    if (validateTriangleSides(sideA, sideB, sideC) && validateTriangleDimensions(sideA, sideB, sideC)) {

        triangle_perimeter = sideA + sideB + sideC;

        printf("The dimensions entered create a valid triangle. "
               "It's perimeter is %0.1f ", triangle_perimeter); // output limited to 1 decimal point

        // calculate the area of the triangle using Heron's Formula
        s = triangle_perimeter / 2;

        triangle_area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));

        printf("and its area is %0.1f. \n", triangle_area); // output limited to 1 decimal point

        return triangle_area;

    } else {

        printf("\n\nProgram must now terminate.");

        exit(0);
    }
}

/**
 * Validate the values entered by the user
 *
 * @param a SideA
 * @param b SideB
 * @param c SideC
 * @return 1 if all sides of the triangle are within the required range
 */
int validateTriangleSides(int a, int b, int c) {

    if (a >= 1 && a <= 100) {

        if (b >= 1 && b <= 100) {

            if (c >= 1 && c <= 100) {

                return 1;

            } else {
                printf("Side C");
            }

        } else {
            printf("Side B");
        }

    } else {
        printf("Side A");
    }

    printf(" of the triangle is out of range.");

    return 0;
}

/**
 * For a triangle to be valid, the sum of any two sides must be greated than the third side
 *
 * @param a SideA
 * @param b SideB
 * @param c SideC
 * @return 1 if the triangle has valid dimensions
 */
int validateTriangleDimensions(int a, int b, int c) {

    if ((a + b > c) && (b + c > a) && (a + c > b)) {
        return 1;
    }

    printf("The dimensions of the given sides do not create a valid triangle.");

    return 0;
}

/**
 * Returns the area of a rectangle based on user input
 *
 * @return The area of the rectangle
 */
double calculateRectangle() {

    double rectangle_length;
    double rectangle_width;
    double rectangle_area;

    printf("\nWe will now calculate the area of a rectangle. \n\n");

    printf("Enter the length of the rectangle: ");
    scanf(" %lf", &rectangle_length);

    printf("Enter the width of the rectangle: ");
    scanf(" %lf", &rectangle_width);

    rectangle_area = rectangle_length * rectangle_width;

    printf("\nThe area of the rectangle is: %0.1lf.\n\n", rectangle_area); // output limited to 1 decimal point

    return rectangle_area;
}
