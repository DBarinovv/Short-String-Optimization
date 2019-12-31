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

char *Make_Right_Str  (const char *string);

int Case_Short_String (const char *string);

char *Transform_Int_To_Short_String (int val);

//-----------------------------------------------------------------------------

char *Make_Right_Str (const char *string, int *if_short_string)
{
//    printf ("!!!!!!!!!!!!!!!!\nSTRING = [%d]\n!!!!!!!!!!!!!!!!\n\n", strlen (string));
//    printf ("SIZEOF INT = [%d]\n", sizeof (int));

    if (strlen (string) + 1 >= sizeof (int)) // +1 because we need special elem
    {
        return (char *) string;
    }
    else
    {
        int val = Case_Short_String (string);

        *if_short_string = val;

//        char *helper = (char *) calloc (C_max_len_of_str, sizeof (char));
//        helper = Transform_Int_To_Short_String (val);
//
//        printf ("\n!POG!\nSTR = [%s]\n", helper);

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

    printf ("RES = [%d]\n", ptr);

    return ptr;
}

char *Transform_Int_To_Short_String (int val)
{
    char *res = (char *) calloc (C_max_len_of_str, sizeof (char));

    val /= 256;   // skip special symbol

//    for (int i = sizeof (int) - 2; i >= 0; i--)  // -2 because we skip one symbol
//    {
//        res[sizeof (int) - i - 2] = val % 256;
//        val /= 256;
//    }

    res = (char *) &val;

    for (int i = 0; i < strlen (res); i++)
    {
        printf ("Elem = (%c)\n", res[i]);
    }

    return res;
}

int main ()
{
    char** arr = (char **) calloc (C_max_len_of_arr, sizeof (char *));
    for (int i = 0; i < C_max_len_of_arr; i++)
    {
        arr[i] = (char *) calloc (C_max_len_of_str, sizeof (char));
    }

    char *str = (char *) calloc (10, sizeof (char));

    gets (str);

    int if_short_string = 0;
    if (Make_Right_Str (str, &if_short_string) == nullptr)
    {
        arr[0] = (char *) if_short_string;
        Transform_Int_To_Short_String (if_short_string);
    }
    else
    {
        arr[0] = str;
    }

//    printf ("STR = [%s]\nSIZE = [%d]\n", str, strlen (str));


    return 0;
}
