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
### Install Vundle
Vundle is one of Plugin Manager of Vim. I think it is very easy to use. you can learn more about Vundle by [click](https://github.com/VundleVim/Vundle.vim)

### problem when use Vundle
* On OSX
But I have some ssh connect problem when I have go into Vim and use cmd `:VundleInstall`. I can't download the plugin by Vundle my cmd `:VundleInstall` in OSX. I think maybe something wrong when I configure git and github account. And Finally I find a way to install Plugin. Because Vundle have ssh connect problem, I download the plugin by `git clone`
```
cd ~/.vim/bundle/
git clone git@github.com:package.git #clone the package you want
```
And modify the `~/.vimrc` file
such as
```
Plugin "xxx/xxx"
```
And then open Vim and use comd `:VundleInstall` or `BundleInstall` to find whether install plugin successfully.

## Install 'iamcco/markdown-preview.vim'
这个插件是用来进行Markdown预览用的，这个插件支持Windows，OSX，Ubuntu。而且能够自动定位。是一款非常不错的插件。
> 这个插件需要vim支持python2或者python3。

### Windows
在Windows下需要使用gvim这个软件来实现，这样就不需要重新编译安装Vim。在安装过程有以下几个注意事项。
* 1.只有使用gvim能使用插件。
* 2.安装Vim和python得同样是32位程序或者是64位程序。同时python的版本不要太高，2.7就能使用。（[参考1](http://zengrong.net/post/1690.htm),[参考2](http://blog.sina.com.cn/s/blog_c52f07550102vi8p.html))
* 3.安装完成后，记得把python的路径包含到系统的环境变量中。然后重启电脑。
* 4.最后记得修改`vim\_vimrc`文件。设置浏览器的地址。([参考](https://github.com/iamcco/markdown-preview.vim/issues/36))

[插件官网](https://github.com/iamcco/markdown-preview.vim)   

## Solarized 配色
### Windows
在Windows下Solarized配色比较简单。
* 1.首先按照[网站](https://github.com/altercation/vim-colors-solarized)的Installation部分的Option1，将Solarized库下载下来。并复制到指定的文件夹
```
cd vim-colors-solarized/colors
mv solarized.vim ~/.vim/colors/
```
* 2.然后修改`vimrc`文件
```
syntax enable
set background=dark
colorscheme solarized
```
然后就安装配色成功了。

## Reference
1.[Vim install by source code in Ubuntu and OSX](http://www.vim.org/git.php)

2.[Rebuild vim for python support](https://elloop.github.io/tools/2016-06-26/upgrade-vim-built-in-mac)

3.[Plugin about markdown in vim introduction](http://www.jianshu.com/p/24aefcd4ca93)

4.[A good website which introduce VIM! recommend!!](http://blog.csdn.net/mergerly/article/details/51671890)
