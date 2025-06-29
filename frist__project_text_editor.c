#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxLength 100
#define notFound -1
// fuction
char *delete(char *source, int index, int n);
char *doEdit(char *source, char command);
char getCommand(void);
char *insert(char *source, const char *to_insert, int index);
int pos(const char *source, const char *to_find);

int main(void)
{
    char source[maxLength], command;
    printf("---------------------------------------------------------\n");
    printf("========Project Name :: Text Editor===========\n");
    printf("Group == Akbar Ali // Malaika Noor // Bibi Humna Bhojani\n");
    printf("Student Id == BDA-25S-028 // BDA-25S-045 // BDA-25S-043\n");
    printf("Department == Computer Science\n");
    printf("Program == BS Data Science\n");
    printf("Section ==  1A\n");
    printf("Sir == Sir Basit Hassan\n");
    printf("----------------------------------------------------------\n\n");

    printf("Enter the source string:\n> ");
    gets(source);

    for (command = getCommand();
         command != 'Q';
         command = getCommand())
    {
        doEdit(source, command);
        printf("New source: %s\n\n", source);
    }
    printf("String after editing: %s\n", source);
    return (0);
}
char *delete(char *source, int index, int n)
{
    char rest_str[maxLength];
    if (strlen(source) <= index + n)
    {
        source[index] = '\0';
    }
    else
    {
        strcpy(rest_str, &source[index + n]);
        strcpy(&source[index], rest_str);
    }
    return (source);
}
char *doEdit(char *source, char command)
{
    char str[maxLength];
    int index;
    switch (command)
    {
    case 'D':
        printf("String to delete> ");
        gets(str);
        index = pos(source, str);
        if (index == notFound)
            printf("'%s' not found\n", str);
        else
            delete(source, index, strlen(str));
        break;
    case 'I':
        printf("String to insert> ");
        gets(str);
        printf("Position of insertion> ");
        scanf("%d", &index);
        insert(source, str, index);
        break;
    case 'F':
        printf("String to find> ");
        gets(str);
        index = pos(source, str);
        if (index == notFound)
            printf("'%s' not found\n", str);
        else
            printf("'%s' found at position %d\n", str, index);
        break;
    default:
        printf("Invalid edit command '%c'\n", command);
    }
    return (source);
}
char getCommand(void)
{
    char command, ignore;
    printf("Choose the work\n D(Delete),\n I(Insert),\n F(Find),\n Q(Quit)> \n");
    scanf(" %c", &command);
    do
        ignore = getchar();
    while (ignore != '\n');
    return (toupper(command));
}
char *insert(char *source, const char *to_insert, int index)
{
    char rest_str[maxLength];
    if (strlen(source) <= index)
    {
        strcat(source, to_insert);
    }
    else
    {
        strcpy(rest_str, &source[index]);
        strcpy(&source[index], to_insert);
        strcat(source, rest_str);
    }
    return (source);
}
int pos(const char *source, const char *to_find)
{
    int i = 0, find_len, found = 0, position;
    char substring[maxLength];
    find_len = strlen(to_find);
    while (!found && i <= strlen(source) - find_len)
    {
        strncpy(substring, &source[i], find_len);
        substring[find_len] = '\0';
        if (strcmp(substring, to_find) == 0)
            found = 1;
        else
            ++i;
    }
    if (found)
        position = i;
    else
        position = notFound;
    return (position);
}
