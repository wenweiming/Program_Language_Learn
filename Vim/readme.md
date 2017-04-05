# Learn Vim
As I know before, Vim is just a editor with much difficult keyword to remember. But after I have learned Vim in Last two day, I'm really fall in love with Vim which is not only as a editor but also as a great tools to code. With so many contribution in the internet. Vim gradually become very powerful. With thousands of hundreds of plugin in the internet, we can make our vim as an "IDE". And Vim not just as a tool but also become a script language known as Vimscript. And now I can readly know how powerful vim is.

## Install Vim
As we want to learn Vim, we must install Vim first, and vim is a multiplatform tool which can be used in Windows, Linux and OSX. And I recommend Linux and OSX because it's really convenient.

### Linux & OSX
Firstly I will introduce Vim install in Linux & OSX. Because it is really convenient. And Vim maybe have install in your system and you can check as cmd below:

```
vim --version
```

If you have't install vim, I recommend you install it by the source code as below

* You can obtain Vim for the first time with:
```
git clone https://github.com/vim/vim.git
```

* And, if you don't have local changes, update to the latest version with:
```
cd vim
git pull
```
* Building vim
```
cd src
make distclean #if you build vim before
make
```
* If you want to make some change, like support python in vim, you should modify something and rebuild vim.
```
cd src/
make distclean
./configure --enable-pythoninterp
make
make install
```
and then you can check by `./vim --version` and you will find a + before python which means we have make vim support python. And if you want to uninstall vim which you build you can use cmd:`make uninstall` which will remove the file in "/usr/local/bin"
* If you have install in your OSX system, and you need to change PATH as follow:
```
echo "$PATH" #to check your PATH
vim ~/.bash_profile
```
and make shure `/usr/local/bin` is in the headmost of PATH
### Windows
Install vim by [download](https://github.com/vim/vim-win32-installer/releases/download/v8.0.0003/gvim_8.0.0003_x86.exe) and double click exe file.
## Introduce Vim
ToDo

## Plugin Manager Vundle
ToDo

## Reference
1.[Vim install by source code in Ubuntu and OSX](http://www.vim.org/git.php)

2.[Rebuild vim for python support](https://elloop.github.io/tools/2016-06-26/upgrade-vim-built-in-mac)
