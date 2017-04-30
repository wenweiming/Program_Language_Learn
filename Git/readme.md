# Git Learn
## Reason I want to learn Git
Git is a distribution manager, It is one of the best tool for open source community and it will help a software develop to a great one. So I think every programmer should learn Git and GitHub which is a web repository for code manager. Even though I am a chinese, but I think if we should want to learn program well we have to learn english well. Firstly, English is another style word to describe the world and every complex word is consisted of 26 letter. And Chinese is another style word wich is consisted thousands of hunnreds of different word. As a Chinese I really want to code with chinese, but I can not image we use thousands of word to code the world. So I really want to learn English well

## Road to Learn Git
This is the second time or the third to learn Git and Github. Because I am not a formal programmer and I just want to learn the thing I will use, so evey time when I have learn something I want about Git and Github and I will not continune learning. And more worse is that I do not make note and eveytime I continue learn Git and Github is a new start. And this time I must learn from the problem I have made. And spend less time to restart learn the sme thing. So I must to make some note in English.

## Problem of use Git
### error:src refspec master does not match any
Because there is no file in local repository and when we use `git push` the erro appear. [Click](http://www.jianshu.com/p/8d26730386f3) to solve.
### error:connect to host github.com port22:Connection timed out
I want to use two github account in my mac, I face this problem. and you need todo as follow [Click](http://blog.csdn.net/xiaoshiyiqie/article/details/52846408) which will be connect to github, but It's not the best way to solve the "port22 connect problem".

## Git的技巧
每办法了，英语是在是太难写了，我还是用中文先写一段时间吧。等通过一段时间的英语训练以后再进行英文的笔记把。

### 合并两个Git仓库
——[参考博客](http://blog.csdn.net/gouboft/article/details/8450696)
在学习这个技巧的时候，我还另外学到一点东西，就是我们把Git放到Github上面托管的时候，因为我们用的是免费的Github，所以我们在Github上面的代码都是公开的，谁都可以看我们的代码，这样如果我们的项目是私人项目，或者是只允许项目内几个人看的时候，我们就不能把我们的项目放到Github上面了，要是被所谓的网络爬虫爬取到了就更加麻烦了。
同时我还发现国内有个叫Coding的公司，提供免费私有库的服务，现在我想把我已有的几个库合并在一起，而且还想保存以前的Commit记录，所以不是简单的拷贝或者粘贴那么简单。然后再将合并后的库统一放到私有库中。现在我们看看如何**合并两个Git仓库**。
通过下面的例子，学会合并两个Github仓库。

* 总体流程
 * 1.目前有两个Git仓库，Repo1，和Repo2.
 * 2.想将Repo1中的文件移入Repo2.
 * 3.Repo1的历史日志要保留。
* 创建两个仓库
 ```
 mkdir Repo1
 cd Repo1
 git init 
 echo "repol1.txt" > Repo1.txt
 git add Repo1.txt
 git commit -m "init Repo1"

 mkdir Repo2
 cd Repo2
 git init 
 echo "repo2.txt" > Reop2.txt
 git add Repo2.txt
 git commit -m "init Repo2"
 ```

* 然后通过五步命令合并两个仓库
 * 1.将Repo1作为远程仓库，添加到Repo2中，设置别名为other
 ```
 git remote add other ../Repo1/
 ```
 * 2.从Repo1仓库中抓取数据到本仓库
 ```
 git fetch other
 ```
 * 3.将Repo1仓库抓取的mater分支作为新分支checkout到本地，新分支名设定为Repo1
 ```
 git checkout -b Repo1 other/master
 ```
 * 4.切换回Repo2的master分支
 ```
 git checkout master
 ```
 * 5.将Repo1合并入master分支
 ```
 git merge Repo1
 ```

通过上述5个步骤就能够将两个分支合并。但是其中还有一些细节没有弄懂，例如这个other的远程仓库名称好像用完这一次就没有用了，该如何删除能？还有Repo1分支名最后怎么样了。

