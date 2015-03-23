Printf-compatiblity library
---------------------------

These files provide the common set of generic and buffered printf functions:
 printf    - sends output to user-supplied function putchar()
 sprintf   - stores formatted output to a buffer
 snprintf  - ditto, with limit
 vprintf   - as printf but takes varargs list argument
 vsprintf  - as sprintf ... ditto ...
 vsnprintf - as snprintf ... ditto ...
 
At the moment there is no test harness for this functions, so they are provided
as-is with no guarantees.
--

Dynamic-allocation tips:
---------------------------
Always intialize the Dynamic allocation using SRAMHeapInit()
Add the following two options in the linker script:
-L-Asramalloc=0200h-04FFh -L-p_SRAM_ALLOC_HEAP=sramalloc

