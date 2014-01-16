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

/* This says how to output assembler code to declare an
   uninitialized external linkage data object.  Under SVR4,
   the linker seems to want the alignment of data objects
   to depend on their types.  We do exactly that here.  */

#define COMMON_ASM_OP	"\t;; gcc/config/c6x/coff.h: COMMON_ASM_OP\n\t.comm\t"

/* The following macro defines the format used to output the second
   operand of the .type assembler directive.  Different svr4 assemblers
   expect various different forms for this operand.  The one given here
   is just a default.  You may need to override it in your machine-
   specific tm.h file (depending upon the particulars of your assembler).  */

#define TYPE_OPERAND_FMT	"@%s"

/* Define the strings used for the special svr4 .type and .size directives.
   These strings generally do not vary from one system running svr4 to
   another, but if a given system (e.g. m88k running svr) needs to use
   different pseudo-op names for these, they may be overridden in the
   file which includes this one.  */

#define TYPE_ASM_OP	"\t;; gcc/config/c6x/coff.h: TYPE_ASM_OP\n\t.type\t"
#define SIZE_ASM_OP	"\t;; gcc/config/c6x/coff.h: SIZE_ASM_OP\n\t.size\t"


/* Write the extra assembler code needed to declare a function's result.
   Most svr4 assemblers don't require any special declaration of the
   result value, but there are exceptions.  */

#ifndef ASM_DECLARE_RESULT
#define ASM_DECLARE_RESULT(FILE, RESULT)
#endif

/* This is how to allocate empty space in some section.  The .zero
   pseudo-op is used for this on most svr4 assemblers.  */

#define SKIP_ASM_OP	"\t;; gcc/config/c6x/coff.h: SKIP_ASM_OP\n\t.zero\t"

#undef  ASM_OUTPUT_SKIP
#define ASM_OUTPUT_SKIP(FILE, SIZE) \
   fprintf ((FILE), "%s"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\
	    SKIP_ASM_OP, (SIZE))

#define TARGET_ASM_NAMED_SECTION  default_coff_asm_named_section
