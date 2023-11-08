#include "shell.h"
/**
 * custom_strtok - Tokenize a string while preserving quoted strings as single tokens.
 * @str: The string to tokenize.
 * @delim: The delimiter character (usually space).
 *
 * Return: A pointer to the next token or NULL if no more tokens are found.
 */
char *custom_strtok(char *str, char delim)
{
    static char *token;
    char *start, *end;
    int inside_quotes = 0;

    if (str != NULL)
    {
        token = str;
    }

    if (token == NULL || *token == '\0')
    {
        return NULL;
    }

    /* Skip leading delimiters */
    while (*token == delim)
    {
        token++;
    }

    /* Check for double-quoted strings */
    if (*token == '\"')
    {
        inside_quotes = 1;
        token++;
    }

    start = token;

    /* Find the end of the token */
    while (*token != '\0')
    {
        if (*token == '\"')
        {
            inside_quotes = !inside_quotes;
        }
        else if (*token == delim && !inside_quotes)
        {
            *token = '\0';
            token++;
            break;
        }
        token++;
    }

    end = token - 1;

    return start;
}