//=============================================================================
//                      SHORT STRING OPTIMIZATION                             ;
//=============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>

//=============================================================================

const int C_max_len_of_str = 20;

const int C_max_len_of_arr = 50;

//=============================================================================

char *Make_Right_Str  (const char *string, int *if_short_string);

int Case_Short_String (const char *string);

//=============================================================================

int main ()
{
    char** arr = (char **) calloc (C_max_len_of_arr, sizeof (char *));
    for (int i = 0; i < C_max_len_of_arr; i++)
    {
        arr[i] = (char *) calloc (C_max_len_of_str, sizeof (char));
    }

    char *str = (char *) calloc (10, sizeof (char));

    for (int i = 0; i < 5; i++)
    {
        gets (str);

        int if_short_string = 0;
        if (Make_Right_Str (str, &if_short_string) == nullptr)
        {
            arr[0] = (char *) if_short_string;
            long long int helper = (long long int) if_short_string;
//            printf ("HELPER = [%llu]\n", helper);
//            printf ("MOd = [%d]\n", (int) floor (pow (256, 4)));
//            helper %= (int) floor (pow (256, 4));
//            printf ("HELPER = [%llu]\n", helper);
//            helper += pow (256, 4);
//            printf ("HELPER = [%llu]\n", helper);

            printf ("String = (%s)\n", (char *) &helper);
        }
        else
        {
            arr[0] = str;
        }
    }

    return 0;
}

//=============================================================================

char *Make_Right_Str (const char *string, int *if_short_string)
{
    if (strlen (string) >= sizeof (int)) // +1 because we need special elem
    {
        return (char *) string;
    }
    else
    {
        *if_short_string = Case_Short_String (string);

        return nullptr;
    }
}

int Case_Short_String (const char *string)
{
    int ptr = 0;

    ptr += '$';
    int pow = 256;

    for (int i = 0; i < strlen (string); i++)
    {
        ptr += string[i] * pow;
        pow *= 256;
    }

    return ptr;
}
