# VIM

# VIM基础学习

## VIM复制、剪切、粘贴
——[参考博客1](http://blog.csdn.net/nkguohao/article/details/8937695)
——[参考博客2](https://linuxtoy.org/archives/efficient-editing-with-vim.html)
* 如果只想使用系统粘贴板的话直接在`INSERT MODE`下按键盘的`shift`+`Insert`就能够复制系统粘贴板上的东西。
* Vim有12个粘贴板，分别是0、1、2、......、9、a、"、+。使用`:reg`命令可以查看各个粘贴板里的内容。在vim中简单用`y`**只是复制**到`"`粘贴板上的内容，同样用`p`粘贴的也是这个粘贴板里的内容。
* 要将Vim的内容复制到某个粘贴板，需要退出编辑模式，**进入正常模式**，选择要复制的内容，然后按`"Ny`命令完成复制，其中`N`为粘贴板号，例如如果要把内容复制到粘贴板`a`，选中内容以后按`"ay`就可以了。这里还有两点需要说明：
 * `"`号粘贴板是临时粘贴板，这个粘贴板比较特殊，直接按`y`就复制到这个粘贴板上了，直接按`p`就粘贴这个粘贴板上的内容。
 * `+`号粘贴板是系统粘贴板，用`"+y`将内容复制到该粘贴板后可以用`Ctrl+v`将其粘贴到其他文档中，同理，要把其他地方用`Ctrl+c`复制的内容拷贝到Vim中，需要在正常模式下按`"+p`。
 * Vim复制粘贴的基本命令：
   * `d{motion}`（{motion}指的是位移命令，如`w`、`b`、`方向键`等，使用这个命令就就位移命令中的内容剪切。
   * `y{motion}`将位移命令中的内容拷贝
   * `c{motion}`将位移命令汇总的内容剪切并进入插入模式。
   * `yy`复制游标所在行整行，或大写一个`Y`。
   * `dd`剪切当前行。
   * `cc`剪切当前行并且进入插入模式。
   * `2yy`或者`y2y`复制两行。
   * `y^`复制到行首，或`y0`。不含游标所处子元。
   * `y$`复制到行尾。含游标所处字元。
   * `yw`复制一个word。
   * `y2w`复制两个子（单词）。
   * `yG`复制到文档尾部。
   * `y1G`复制到文档顶部。
   * `p`代表粘贴到游标后。
   * `P`（大写）代表粘贴到游标前。
   * `"N`使用寄存器模式加上`y`、`p`进行灵活的复制与粘贴。


## 在Visual模式下剪切与复制
——[参考博客](https://linuxtoy.org/archives/efficient-editing-with-vim.html)
使用可视选择（visual selections）和合适的选择模式
不像最初的VI，Vim允许你高亮（选择）一些文本，并且进行操作，这里有三种选择模式：
* v：按照字符选择。
* V：按行选择，这在你想拷贝或者移动很多行的文本的时候特别有用。
* `Ctrl+v`：按块选择。非常强大，你可以选择一个矩形块，并且在这个矩形里面的文本会被高亮。

一旦你高亮了选区，你或许想进行一些操作：
* `d`：剪切选择的内容到剪切板。
* `y`：拷贝选择的内容到剪切板。
* `c`：剪切选择的内容到剪切板并且进入插入模式。

##用Vim写代码
——[参考博客](https://linuxtoy.org/archives/efficient-editing-with-vim.html)
Vim是一个用来写代码的绝好编辑器，因为它有一些特性是专名为程序员而设计的。这里是一些常用的：
* `]p`：和`p`的功能差不多，但是它会自动调整被粘贴的文本的缩进去适应当前代码的位置。
* `%`：匹配花括号、方括号、括号等。在一个括号的上面，然后按`%`，光标就会出现在另一个半括号上。
* `>>`：缩进所有选择的代码。
* `<<`：反缩进所有选择的代码。
* `gd`：到达光标所处函数或者变量的定义处。
* `K`：在Man里面查找光标当前所处的词。


# VIM插件学习
VIM中有许多非常强大的插件，掌握必要的插件对于我们效率的提升有非常大的作用。下面记录以下我现在使用的插件。

## 插件管理器：Vundle

## 配色方案：Solarized
Solarized配色方案是一种应用非常广泛的配色方案，其能够用在Mac，Windows，Ubuntu上，而且显示效果非常好看，所以选择了这款配色方案。

### Ubuntu下Solarized的使用。
要使用solarized的前提是要安装git这个工具。通过`git --version`这条命令查看是否安装上git，如果没有安装，就通过下面命令来安装：`sudo apt-get install git-core`

* 1.设置solarized theme for GNU ls，不然在Terminal下ls命令出来效果都是灰蒙蒙的
 * 首先下载设置solarized theme for GNU ls的文件：
```
git clone git://github.com/seebi/dircolors-solarized.git
```
 * 选择一种`dircolor-solarized`目录下的一种配色，并应用。
 ```
cp ~/dircolors-solarized/dircolors.ansi-dark ~/.dircolors
eval 'dircolors .dircolors'
 ```
 * 然后设置Terminal支持256色，通过命令`vim .barshrc`打开文件，并在最后添加`export TERM=xterm-256color`，这样dircolors for GNU ls算设置完成了。最后别忘了`source.bashrc`。
* 2.接下来安装Solarized的Gnome-Terminal配色：
 * 下载：
 ```
 git clone git://github.com/sigurdga/gnome-terminal-colors-solarized.git
 ```
 * 安装脚本：
 ```
 cd gnome-terminal-colors-solarized 
 ./set_dark.sh
 ```
 
 ([1、2部分参考](http://blog.csdn.net/angle_birds/article/details/11694325))
* 3.配置Vim的Solarized配色方案：
 * 下载：
 ```
 git clone git@github.com:altercation/vim-colors-solarized.git
 ```

 * 拷贝文件
 ```
 cd vim-colors-solarized/colors
 cp solarized.vim ~/.vim/colors/
 ```
 * 修改`.vimrc`文件
 ```
 cd ~
 vim .vimrc 
 ```
 到`.vimrc`文件的最后，然后在文件中加入：
 ```
 syntax enable
 set background=dark
 colorscheme solarized
 ```
 到这个地方，VIM的Solarized配色配置就算完成了。

 ([3部分参考](https://github.com/altercation/vim-colors-solarized))

## 文件管理：NERDTree
* 安装：
打开`.vimrc`文件，然后到文件的加入插件的地方插入`Plugin 'scrooloose/nerdtree'`。
打开Vim，输入：`VundleInstall`安装NERDTree。
* 设置快捷键：
如在`.vimrc`文件最后面加上：`map <leader>e :NERDTreeToggle<CR>`，即可在Vim中通过`\e`命令打开NERDTree。

[NERDTree官网](https://github.com/scrooloose/nerdtree)

## 查找文件：Ctrlp
基本上不太会用

[Ctrlp官网](https://github.com/ctrlpvim/ctrlp.vim)

## Source code browser：Taglist
* 首先安装ctags
```
sudo apt-get install ctags
```

[Taglist官网](https://github.com/vim-scripts/taglist.vim)

## YouCompleteMe

[YouCompleteMe官网](https://github.com/Valloric/YouCompleteMe)


# Vim小问题

## Vim在Windows系统中的编码问题。
在Windows上使用gvim的时候，中文有的时候会显示乱码，具体原因不太明白，参考两篇文章好问题得到了解决。
* 参考[第一篇文章](http://blog.csdn.net/keepliving/article/details/5623362)
* 在_vimcm中加入:
```
set enc=utf8
set fencs=utf8,gbk,gb2312,gb18030,cp936
```
就能够解决文章的中文显示问题。
* 参考[第二篇](https://www.douban.com/note/145491549/)
 * 在_vimrc中加入：
```
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
```
解决菜单中文显示问题。
 * 在_vimrc中加入：
```
language messages zh_CN.utf-8
```
解决提示中文显示问题。
