## 三、一些没用但是优雅的配置

### 1.安装Vmware Tools

![1664278008275](D:\Linux\class\class one.assets\1664278008275.png)

进入系统后，点击虚拟机，选安装Vmware Tools

![1664278500467](D:\Linux\class\class one.assets\1664278500467.png)

可以看到桌面出现了一个VMware Tools

![1664278525714](D:\Linux\class\class one.assets\1664278525714.png)

在界面中按右键或者Ctrl+shift+n，创建一个文件夹

![1664278570536](D:\Linux\class\class one.assets\1664278570536.png)

起个名字，之后把VMware Tools文件夹中以.tar.gz结尾的文件（是一个压缩包）拖进去，如下图

![1664278711925](D:\Linux\class\class one.assets\1664278711925.png)

右键文件夹中的.tar.gz，选择Extract Here，即解压

![1664278853104](D:\Linux\class\class one.assets\1664278853104.png)

之后会看到一个新的文件

![1664278884544](D:\Linux\class\class one.assets\1664278884544.png)

双击进入解压出来的文件，进入到如下目录

![1664278935574](D:\Linux\class\class one.assets\1664278935574.png)

之后在文件夹空白处，右键，选择Open in Terminal

![1664278973402](D:\Linux\class\class one.assets\1664278973402.png)

输入该命令 `sudo ./vmware-install.pl`之后回车，输入密码

![1664279055845](D:\Linux\class\class one.assets\1664279055845.png)

输入yes，一直回车即可

![1664279099614](D:\Linux\class\class one.assets\1664279099614.png)

出现红框字样，即表示你的Vmware Tools已经装好啦

### 2.一些指令和让工作目录变得更加优雅

![1664279142904](D:\Linux\class\class one.assets\1664279142904.png)



`ls`：查看当前目录文件

`cd`：进入某个目录

`rm -rf`：删除文件



在工作目录下，即xxx@xxxxx:~$

输入`rf -rf *`

![1664279405161](D:\Linux\class\class one.assets\1664279405161.png)

就可以看到一些乱七八糟的东西就消失了，那么我们如何把我们的桌面变成工作目录呢

输入该指令`sudo gedit ./.config/user-dirs.dirs`,把$HOME/后的单词删除，之后Ctrl+s保存，关闭

![1664279517293](D:\Linux\class\class one.assets\1664279517293.png)

可以看到一下log，输入 `sudo reboot`重启虚拟机即可

![1664279601997](D:\Linux\class\class one.assets\1664279601997.png)

### 3.共享文件夹

点击虚拟机--》设置

![1664279803027](D:\Linux\class\class one.assets\1664279803027.png)

如下图

![1664279878147](D:\Linux\class\class one.assets\1664279878147.png)

创建一个共享文件夹，路径自己选择

![1664279907094](D:\Linux\class\class one.assets\1664279907094.png)

之后点击确定

![1664279924768](D:\Linux\class\class one.assets\1664279924768.png)

然后在windows上，往该文件夹随便放入一些文件

![1664279981317](D:\Linux\class\class one.assets\1664279981317.png)

之后在linux上，输入如下指令 `ls /mnt/hgfs/share`，哇，有相同的文件耶，那说明共享文件夹就安装成功了，这样未来进行文件传输就非常方便了

![1664280106868](D:\Linux\class\class one.assets\1664280106868.png)



如果不满意自己的用户名，可以通过`sudo gedit /etc/hostname`命令去更改，文件夹中对应的就是@符号后面的内容

![1664280163749](D:\Linux\class\class one.assets\1664280163749.png)



之后更新一下软件包

`sudo apt-get install update`

`sudo apt-get install vim`

`sudo apt-get install gcc`

`sudo apt-get install open-vm-tools`

`sudo apt-get install open-vm`



如果出现没有网络的情况，右上角也没有网络图标

`sudo gedit /etc/NetworkManager/NetworkManager.conf`

将`managed`的`false`改为`true`

然后重启一下网络服务

`sudo service network-manager stop`

`sudo rm /var/lib/NetworkManager/NetworkManager.state`

`sudo service network-manager start`

