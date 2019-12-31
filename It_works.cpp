//=============================================================================
//                      SHORT STRING OPTIMIZATION                             ;
//=============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//=============================================================================

const int C_max_len_of_str = 20;

const int C_max_len_of_arr = 50;

//=============================================================================

char *Make_Right_Str (char *string, int *if_short_string);

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

    int if_short_string = 0;
    for (int i = 0; i < 5; i++)
    {
        gets (str);

        if_short_string = 0;
        if (Make_Right_Str (str, &if_short_string) == nullptr)
        {
            arr[i] = (char *) if_short_string;
            long long int helper = (long long int) if_short_string;

            printf ("String = (%s)\n", (char *) &helper);
        }
        else
        {
            arr[i] = str;
        }
    }

    return 0;
}

//=============================================================================

char *Make_Right_Str (char *string, int *if_short_string)
{
    if (strlen (string) >= sizeof (int))
    {
        return string;
    }
    else
    {
        *if_short_string = Case_Short_String (string);

        return nullptr;
    }
}

int Case_Short_String (const char *string)
{
    int res = 0;

    res += '$';
    int pow = 256;

    for (int i = 0; i < strlen (string); i++)
    {
        res += string[i] * pow;
        pow *= 256;
    }

    return res;
}
