#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    // Validate number of arguments
    if (argc == 2)
    { 
        string keyword = (argv[1]);
        int keywordlen = strlen(keyword);
        
        // Loop through each char in the keyword to check if it is alphabetical
        for (int i = 0, n = keywordlen; i < n; i++)
        {
            if (isalpha(keyword[i]))
            {
            }
            // End the program if the keyword isn't entirely alphabetical
            else
            {
                printf("Usage: ./vigenere <keyword>\n");
                return 1;
            }
        }    
            
        string text = GetString();
        
        // Encrypt plaintext
        for (int i = 0, n = strlen(text), j = 0; i < n; i++)
        {
            // Encrypt char if it is a letter
            int cipher;
            int key = toupper(keyword[j]) - 65;
            if (isalpha(text[i]))
            {
                    
                if (isupper(text[i]))
                {
                    cipher = ((text[i] - 65 + key) % 26) + 65;
                }
                else 
                {
                    cipher = ((text[i] - 97 + key) % 26) + 97;
                }
                j = (j + 1) % keywordlen;    
            }            
            
            // Don't encrypt char if it's not a letter
            else
            {
                cipher = text[i];
            }
            
            // Print char of ciphertext
            printf("%c", cipher);      
        }
        
        printf("\n");
    
    }
    
    // Return an error if user input is not valid
    else
    {
        printf("Usage: ./vigenere <keyword>\n");
        return 1;
    }
}
