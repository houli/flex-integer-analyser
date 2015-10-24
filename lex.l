%{
#include "types.h"
%}

%%
[0-7]+[bB]       return OCTAL;
[0-9a-fA-F]+[hH] return HEX;
[+-]?[0-9]+      return DECIMAL;
[ \t\n]          ;
.                printf("Invalid\n");
%%
