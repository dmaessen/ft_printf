<b>ft_printf</b>

The prototype of ft_printf() is:<br>
&emsp;int ft_printf(const char *, ...);<br>

Here are the requirements:<br>
&emsp;• Don’t implement the buffer management of the original printf().<br>
&emsp;• Your function has to handle the following conversions: cspdiuxX%.<br>
&emsp;• Your function will be compared against the original printf().<br>
&emsp;• You must use the command ar to create your library.<br>
&emsp;• Your libftprintf.a has to be created at the root of your repository.<br>

You have to implement the following conversions:<br>
&emsp;• %c Prints a single character.<br>
&emsp;• %s Prints a string (as defined by the common C convention).<br>
&emsp;• %p The void * pointer argument has to be printed in hexadecimal format.<br>
&emsp;• %d Prints a decimal (base 10) number.<br>
&emsp;• %i Prints an integer in base 10.<br>
&emsp;• %u Prints an unsigned decimal (base 10) number.<br>
&emsp;• %x Prints a number in hexadecimal (base 16) lowercase format.<br>
&emsp;• %X Prints a number in hexadecimal (base 16) uppercase format.<br>
&emsp;• %% Prints a percent sign.<br>
