//=============================================================================
//                      SHORT STRING OPTIMIZATION                             ;
//=============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//=============================================================================
//                          GLOBAL/CONST VARIABLES                            ;
//=============================================================================

const int C_max_len_of_str = 20;

const int C_max_len_of_arr = 50;

const char C_special_symbol = '!';   // because we want odd

//=============================================================================

char *Transform_If_Short (char *string, int *if_short_string);

int Case_Short_String (const char *string);

char *Make_Right_Str (char *string);

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
    for (int i = 0; i < 3; i++)
    {
        gets (str);

        if_short_string = 0;
        if (Transform_If_Short (str, &if_short_string) == nullptr)
        {
            arr[i] = (char *) if_short_string;
        }
        else
        {
            arr[i] = str;
        }
    }


    for (int i = 0; i < 3; i++)
    {

        printf ("Line [%d] = (%s)\n", i, Make_Right_Str (arr[i]));
    }

    return 0;
}

//=============================================================================

char *Transform_If_Short (char *string, int *if_short_string)
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

    res += C_special_symbol;
    int pow = 256;

    for (int i = 0; i < strlen (string); i++)
    {
        res += string[i] * pow;
        pow *= 256;
    }

    return res;
}

//-----------------------------------------------------------------------------

char *Make_Right_Str (char *string)
{
    long long int helper = (long long int) string;
    int val = (int) helper;

    if (val % 256 == C_special_symbol)
    {
        val /= 256;
        return (char *) &val;
    }

    return string;
}
