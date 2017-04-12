# VIM

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
