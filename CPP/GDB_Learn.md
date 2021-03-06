# GDB学习
GDB是一款在命令行中使用的调试工具。下面记录一下在学习使用GDB时候的一些技巧与注意事项。

## 程序能够进入GDB调试的条件。
我们要想使用GDB调试，必须做一些准备工作。不然的话不能进入调试界面。其实要想调试一个程序，需要在编译指令里面加入`-g`选项，而在`makefile`里，需要把`-g`选项加入到与汇编阶段的编译命令里。[参考](https://my.oschina.net/yumifan/blog/272512?p={{page}})
GCC编译选项
```
-c			Compile and assemble, but do not link
-o <file>	Place the Output into <file>
-g			Generate debug information in default format
```
## x的用法
x是GDB用来检查内存的命令，其使用方法是[参考](http://www.zmonster.me/2014/07/27/gdb-tricks.html)：
```
x/nfu addr
```
* n
其中n表示要重复打印的次数，**默认值**为1。
* f
表示输出的格式，支持
 * x（十六进制）
 * d（十进制）
 * u（无符号整型）
 * o（八进制）
 * t（二进制）
 * a（地址值）
 * c（字符型）
 * f（浮点型）
 * s（字符串型）
**默认值**为x
* u
u表示每个输出的宽度，可以选择
 * b（1个字节）
 * h（2个字节）
 * w（4个字节）
 * g（8个字节）
**默认值**为4个字节（w）
* 小结
这里的`n`是控制打印的个数，配合后面的`u`来使用，例如后面`u`如果是`b`，而`n`是2，就代表会打印两次宽度为1个字节的内容。而输出的内容表示形式则由`f`来表示。如果`f`是d，则将内容按照十进制来输出出来。

## `p`的用法
`p`其实就是打印，一般可以用来打印变量，显示变量的内容，同时也可以打印地址，如果对于指针而言，打印指针就是打印地址，而对于普通变量而言，想要打印地址就需要用到取址符号`&`。例如如果程序中有个`int`变量`myvalue`，当想要查看它的地址的时候就能够通过命令`p &myvalue`来读取变量的地址。


