#include "city.h"
#include <stdio.h>
#include <math.h>   /* For sin, cos. */
#include <time.h>   /* For time. */

/**
 * Initialize global varible
 */
int k = 0;  
char unit = 'M';
int num = 0;

/**
 * PROGRAMMED BY : Jade Tran
 * CLASS : CS1D
 * SECTION : TTh 11:3 - 1:50
 * FILE: driver.c
 *     Design a algorithm that, given a list of n cities and some number k,  
 *     returns a list of thek cities that are closest to you, 
 *     sorted by increasing order of distance
 * ASSIGNMENT : Finding closest cities
 */

#define pi 3.14159265358979323846

/**
 * Reference: GeoDataSource
 * https://www.geodatasource.com/developers/c
 * *********************************************************************************
 * This function converts decimal degrees to radians.
 */
double deg2rad(double deg) {
  return (deg * pi / 180);
}

/**
 * This function converts radians to decimal degrees.
 */
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

/**
 *This function calculate the distance between 2 points.
 */
float distance(float my_lat, float my_lon, float city_lat, float city_lon) 
{
  float theta, dist;
  if ((my_lat == city_lat) && (my_lon == city_lon)) 
    {
        return 0;
    }
  else 
    {
        theta = my_lon - city_lon;
        dist = sin(deg2rad(my_lat)) * sin(deg2rad(city_lat)) + cos(deg2rad(my_lat)) * cos(deg2rad(city_lat)) * cos(deg2rad(theta));
        dist = acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        switch(unit) {
        case 'M':
            break;
        case 'K':
            dist = dist * 1.609344;
            break;
        }
    return (dist);
  }
}


int main(int argc, char **argv)
{
    FILE *input_file;
    float my_lon =  -117.6931;
    float my_lat =  33.6500;
    int index = 0;
    int read1 = 0;
    int read2 = 0;
    int read3 = 0;

    /**
     * Variables used to read (city) name and store (city) name.
     */
    char line1[LENGTH];        /*Used to read in words*/
    char *new_word = NULL;
    
    /**
     * Variables for read in longitude and latitude for city.
     */
    char  line2[LENGTH];        /*Used to read in "float" for longitude*/
    char  line3[LENGTH];        /*Used to read in "float" for latitude*/
    char city_lo[LENGTH];
    char city_la[LENGTH];
    float city_lat, city_lon;

    /**
     * Variable used to store the result of 'distance' function.
     */
    float dis = 0.0;

    /**
     * BST of nodes used to store city names and city longitudes and latitudes.
     */
    node *root = NULL;
    

    if (argc != 2)
    {
        exit(1);
    }
    /*
     * Open the input file.  For simplicity, we specify that the
     * input file has to contain exactly one word per line.
     */
    input_file = fopen(argv[1], "r");

    /**
     * Open failed. 
     */
    if (input_file == NULL)  
        {
            fprintf(stderr, "Input file \"%s\" does not exist! "
                            "Terminating program.\n", argv[1]);
            return 1;
        }

    /**
     * Prompt input from the user for 'k'. 
     * If the input is out of range (either smaller than 0 or greater than the size of original array - NUMBER_CITIES),
     *         print out some message "input is invalid".
     * Then create a 'distance' list of size 'k'.
     */
    printf("The give list contains %d cities.\n", NUMBER_CITIES);
    printf("Please enter size of a list that you wish to sort (in ascending order) and print. (valid range: 1-%d)\n", NUMBER_CITIES);
    scanf("%d", &k);  
    printf("Enter: %d\n", k);
    while(k < 0 || k > NUMBER_CITIES)
        {
            printf("Invalid input. Please enter a integer in range of 1-%d\n", NUMBER_CITIES);
            printf("Enter: %d\n", k);
        }


    /**
     *  Add the words until there are none left. 
     */
    while (fgets(line1, LENGTH, input_file) != NULL && fgets(line2, LENGTH, input_file) != NULL && fgets(line3, LENGTH, input_file) != NULL && index <  NUMBER_CITIES)
        {         
            new_word = malloc(sizeof(line1));   
            /**
             *  Convert the lines to a char and float variables. 
             */
            read1 = sscanf(line1, "%[^\t\n]", new_word);    /* Read all characters include spaces. */
            read2 = sscanf(line2, "%s", city_lo);
            read3 = sscanf(line3, "%s", city_la);

            /**
             *  Conversion failed, e.g. due to a blank line. 
             */
            if (read1 != 1 && read2 != 1 && read3 != 1)  
                {
                    printf("Error occurred inside while loop! Terminating program.\n");
                    return 1;
                }
            else    
                {
                    city_lon = atof(city_lo);
                    city_lat = atof(city_la);

                    /**
                     * Calculate the distance.
                     */
                    dis = distance(my_lat, my_lon, city_lat, city_lon);

                    /**
                     * Store datas to the 'node' variables.
                     */
                    create_bst(&root, new_word, dis);
                    printf("Size of node root in driver.c: %zu bytes\n", sizeof(root));

                }
                             
            /**
             * Clear the contents of 'words'.
             */
            city_lo[0] = '\0';   
            city_la[0] = '\0';
        }
    /**
     * Close the file.
     */
    fclose(input_file); 



    /**
     * Print out a list of k citites in sorted order.
     */
    printf("\n\n========================================================================\n");
    printf("== List of %d cities that closedt to Lake Forst, CA                    ==\n", k);
    printf("========================================================================\n"); 
    traverse_list(root);
    printf("========================================================================\n"); 

    /**
     * Free the tree
     */
    free_tree(root);
    
    return 0;
}


