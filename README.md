# ft_printf

## Recoded `printf()` function.
<img src="./image.jpg" width=80% height=80%>

<span>Photo by <a href="https://unsplash.com/@laurachouette?utm_source=unsplash&amp;utm_medium=referral&amp;utm_content=creditCopyText">Laura Chouette</a> on <a href="/s/photos/typewriter?utm_source=unsplash&amp;utm_medium=referral&amp;utm_content=creditCopyText">Unsplash</a></span>

### Desctiprion

 format spec construction:
 `%[flags][width][.precision][length]type`

#### my ft_printf works with:

Conversions:	`[cspdiuxX%]`
 
Flags:			`[-0.*]` and minimum field width with all conversions

Also prints `0` or `'\0'` with `%c` conversion. To check this you can use `| cat -e` on output (as in makefile `main` rule).

Details about displaying printed `0` on [stackoverflow](https://stackoverflow.com/questions/62235315/what-do-these-signs-mean)

### Install

`git clone https://github.com/kukinpower/ft_printf.git`

`cd ft_printf`

`git submodule update --init` to clone `libft`

### Compilation

`make` to compile library

Makefile works with rules: `re` `clean` `fclean` `main` `main clean`

Rule `main` compiles with main and runs `a.out`

Compiles with flags: `-Wall -Wextra -Werror`

`ft_printf()` uses `libft` library functions. And compiles with it.

[my libft project](https://github.com/kukinpower/libft)

### Use

`#include "libftprintf.h"`

Then use as standard `printf()` with a format string.
