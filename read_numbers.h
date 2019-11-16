#ifndef DEF_READ_NUMBERS
#define DEF_READ_NUMBERS

char *read_per_unit(char c);
char *read_hundreds(char a[], int mod);
void split_string(char s[], char k[], int a, int b);
char *read(char s[]);
void padding_0(char s[], char temp[], int n);

    void read_per_unit_test();
void read_hundreds_test();
void split_string_test();
void read_test();

#endif
