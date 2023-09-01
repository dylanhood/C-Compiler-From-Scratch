#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"
int main()
{   
    int res = compile_file("./test.c", "./test", 0);
    if (res == COMPILER_FILE_COMPILED_OK)
    {
        printf("Compiled Successfully\n");
    }
    else if(res == COMPILER_FAILED_WITH_ERRORS)
    {
        printf("Compile failed\n");
    }
    else
    {
        printf("Unknown response for compile file\n");
    }
    return 0;
}

#if 0
    Template Error System Stuff:
    vector_push(vec, &x);

    //vector_pop(vec);

    vector_set_peek_pointer(vec, 0);

    printf("Hello World\n");
    return 0;
#endif