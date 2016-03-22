#include <stdio.h>
#include <stdlib.h>

void foo (char *aop[]) {

    printf("foo\n");
}

void bar (char *aop[4]) {

    printf("bar\n");
}

void hoo (char (*pta)[]) {

    printf("hoo\n");
}

void wow (char (*pta)[4]) {

    printf("wow\n");
}

int main (int argc, char *argv[]) {

    char a='a', b='b', c='c', d='d';
    char array[4] = {'e', 'f', 'g', 'h'};
    char *pointer = array;
    char **double_pointer;
    char *array_of_pointer[4];              //  Array of pointers (char *)
    char (*pointer_to_array)[4];            //  Pointer of array (char [])
    //  char *wrong_array_of_pointer[];     //  <GCC ERROR> error: array size missing in ‘ptr_arr’

    array_of_pointer[0] = &a;
    array_of_pointer[1] = &b;
    array_of_pointer[2] = &c;
    array_of_pointer[3] = &d;

    pointer_to_array = &array;

    /**  <CONCLUSION> Double Pointer = Array of Pointer != Pointer to Array  **/
    foo(double_pointer);
    foo(array_of_pointer);
    //  foo(pointer_to_array);              //  <GCC ERROR> note: expected ‘char **’ but argument is of type ‘char (*)[4]’

    bar(double_pointer);
    bar(array_of_pointer);
    //  bar(pointer_to_array);              //  <GCC ERROR> note: expected ‘char **’ but argument is of type ‘char (*)[4]’

    //  hoo(double_pointer);                //  <GCC ERROR> note: expected ‘char (*)[]’ but argument is of type ‘char **’
    //  hoo(array_of_pointer);              //  <GCC ERROR> note: expected ‘char (*)[]’ but argument is of type ‘char **’
    hoo(pointer_to_array);
 
    //  wow(double_pointer);                //  <GCC ERROR> note: expected ‘char (*)[4]’ but argument is of type ‘char **’
    //  wow(array_of_pointer);              //  <GCC ERROR> note: expected ‘char (*)[4]’ but argument is of type ‘char **’
    wow(pointer_to_array);

    return 0;
}
