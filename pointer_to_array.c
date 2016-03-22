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
    //  char *nosize_array_of_pointer[];     //  <GCC ERROR> error: array size missing in ‘ptr_arr’
    char (*pointer_to_nosize_array)[];

    array_of_pointer[0] = &a;
    array_of_pointer[1] = &b;
    array_of_pointer[2] = &c;
    array_of_pointer[3] = &d;

    pointer_to_array = &array;

    /**  <CONCLUSION 1> Double Pointer = Array of Pointer != Pointer to Array  **/
    foo(double_pointer);
    foo(array_of_pointer);
    //  foo(pointer_to_array);              //  <GCC ERROR> note: expected ‘char **’ but argument is of type ‘char (*)[4]’
    //  foo(pointer_to_nosize_array);       //  <GCC ERROR> expected ‘char **’ but argument is of type ‘char (*)[]’

    bar(double_pointer);
    bar(array_of_pointer);
    //  bar(pointer_to_array);              //  <GCC ERROR> note: expected ‘char **’ but argument is of type ‘char (*)[4]’

    //  hoo(double_pointer);                //  <GCC ERROR> note: expected ‘char (*)[]’ but argument is of type ‘char **’
    //  hoo(array_of_pointer);              //  <GCC ERROR> note: expected ‘char (*)[]’ but argument is of type ‘char **’
    hoo(pointer_to_array);
    hoo(pointer_to_nosize_array);
 
    //  wow(double_pointer);                //  <GCC ERROR> note: expected ‘char (*)[4]’ but argument is of type ‘char **’
    //  wow(array_of_pointer);              //  <GCC ERROR> note: expected ‘char (*)[4]’ but argument is of type ‘char **’
    wow(pointer_to_array);
    wow(pointer_to_nosize_array);


    /**  <CONCLUSION 2> Pointer != Array    **/
    pointer += 2;
    pointer_to_array += 2;
    //  pointer_to_nosize_array += 2;       //  <GCC ERROR> error: invalid use of array with unspecified bounds
    //  *pointer_to_array += 2;             //  <GCC ERROR> error: invalid operands to binary + (have ‘char[4]’ and ‘int’)
    //  array += 2;                         //  <GCC ERROR> error: invalid operands to binary + (have ‘char[4]’ and ‘int’)
    //  array_of_pointer += 2;              //  <GCC ERROR> error: invalid operands to binary + (have ‘char[4]’ and ‘int’)
    
    return 0;
}
