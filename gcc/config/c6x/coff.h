/* This is how to store into the string LABEL
   the symbol_ref name of an internal numbered label where
   PREFIX is the class of label and NUM is the number within the class.
   This is suitable for output with `assemble_name'.

   For most svr4 systems, the convention is that any symbol which begins
   with a period is not put into the linker symbol table by the assembler.  */

#undef  ASM_GENERATE_INTERNAL_LABEL
#define ASM_GENERATE_INTERNAL_LABEL(LABEL, PREFIX, NUM)		\
  /* gcc/config/c6x/coff.h: ASM_GENERATE_INTERNAL_LABEL */\
  do								\
    {								\
      char *__p;						\
      (LABEL)[0] = '*';						\
      (LABEL)[1] = '.';						\
      __p = stpcpy (&(LABEL)[2], PREFIX);			\
      sprint_ul (__p, (unsigned long) (NUM));			\
    }								\
  while (0)
