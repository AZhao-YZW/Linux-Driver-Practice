# 设计目标
1. 熟悉常见类型linux驱动编写
2. 开启Linux scsi中层打印，在文件系统上做一些操作，观察这些操作对应的scsi命令
3. 尝试Linux双系统(CentOS 7 + OpenEuler 24.03)
4. 树莓派3B+上编写测试主机驱动

# 注意事项
1. 在VMWare中运行CentOS 7时，使用图形界面调出的Terminal，不要长按上/下键，否则会引起系统卡死。更好的方法是远程ssh连接CentOS 7操作，这样更安全。并且，VMWare选择12个内核会出现此情况，而选择8个内核则不会。网络上说是Windows的Hyper-V启用的问题，但实测是和选择内核数量有关，怀疑是VMWare或者CentOS 7对某些数量内核兼容性问题。
2. VMWare配置虚拟机网络IP最好用静态IP，方便ssh远程连接
3. Linux dmesg出现日志'/dev/kmsg buffer overrun, some messages lost'，不确定为啥
4. Raspberry Pi 3B+: 可采用串口连接，注意红灯闪烁或不亮代表电源适配器供电能力不足，需更换更好的适配器(华为40W充电器，小米120W充电器都可以支持，这里也要注意连线是否接触不良)，还要注意串口硬件连接是否正常(我的电脑的其中一个usb口居然接触不良了，中途还误以为是串口通讯配置问题)

# 参考资料
- [Linux驱动之Ubuntu下下载内核源码——学习笔记（7）](https://blog.csdn.net/lang523493505/article/details/104413086)
- [Linux驱动入门（一）字符设备驱动基础](https://blog.csdn.net/weixin_42462202/article/details/99887783)
- [Linux内核 - 模块编译和安装](https://www.cnblogs.com/lrh-xl/p/5315994.html)
- [驱动编译 - 缺少Module.symvers文件](https://www.jianshu.com/p/05450481c10e)
- [Unable to find the ncurses libraries的解决办法](https://blog.csdn.net/zn2857/article/details/53618443)
- [insmod加载内核模块后报错，Invalid module format](https://blog.csdn.net/lijunnanxcx/article/details/104714202)
- [linux 内核模块 编译绕过insmod版本检查](https://blog.csdn.net/whatday/article/details/108865961)
- [Linux强制卸载内核模块(由于驱动异常导致rmmod不能卸载)](https://blog.csdn.net/gatieme/article/details/75108154)
- [解密 Linux 包管理：apt 和 apt-get 的区别](https://www.sysgeek.cn/apt-vs-apt-get)
- [yum与apt的区别](https://blog.csdn.net/qq_26182553/article/details/79869666)
- [关于 root 和 wheel：在 Linux 中创建管理员账号（root 权限）的正确方式](https://sysin.org/blog/linux-root/)
- [Centos7下载linux内核源码](https://blog.csdn.net/wh_computers/article/details/114272949)
- [CentOS Vault Mirror](https://vault.centos.org/)
- [通过12个实例掌握 linux wget 命令的使用](https://segmentfault.com/a/1190000043454293)
- [linux tar打包、解包命令](https://www.jianshu.com/p/b9a667d8cb1e)
- [Linux如何重复执行命令每隔几秒或者每隔几分钟](https://www.cnblogs.com/Hackerman/p/16032582.html)
- [Linux 物理卷(PV)、逻辑卷(LV)、卷组(VG)管理](https://www.cnblogs.com/lijiaman/p/12885649.html)
- [VMware设置CentOS7系统磁盘扩容](https://blog.csdn.net/weixin_43744059/article/details/109612543)
- [嵌入式Linux：提升VMware虚拟机运行速度的方法](https://cloud.tencent.com/developer/article/2375523)
- [Vmware核心处理器及内核数量相关概念](https://www.cnblogs.com/gambler/p/13227652.html)
- [centos7分区、挂载、磁盘合并](https://blog.csdn.net/qq_43076825/article/details/117125811)
- [mdadm使用 移除raid](https://blog.csdn.net/u010953692/article/details/107364357)
- [使用 fdisk 对分区进行扩容（非LVM）](https://blog.csdn.net/sx_1706/article/details/127673151)
- [linux扩容磁盘后，文件系统大小还是没变化](https://blog.csdn.net/qq_41999034/article/details/111031490)
- [tr与sed命令：将换行符替换为空格](https://www.jianshu.com/p/82c7a18c1120)
- [linux less命令详解(9个实用案例演示)](https://blog.csdn.net/weixin_51376678/article/details/121485496)
- [Linux磁盘格式化(mkfs、mkfs.xfs、mkfs.ext4)、Linux文件系统的校验(xfs_repair、fsck_ext4)](https://blog.csdn.net/qq_41453285/article/details/86822769)
- [在Linux中查找文件系统类型的7种方法](https://cloud.tencent.com/developer/article/2126656)
- [Linux下用mdadm创建软RAID以及避坑](https://ruohai.wang/202310/mdadm-create-soft-raid-guide/)
- [linux FIO命令详解：磁盘IO测试工具 fio (并简要介绍iostat工具)](https://www.cnblogs.com/chenjunwu/p/14420178.html)
- [centos7下解决journal日志越来越大的问题](https://cloud.tencent.com/developer/article/1671561)
- [/dev/kmsg buffer overrun, some messages lost](https://wiki.gentoo.org/wiki/Systemd#.2Fdev.2Fkmsg_buffer_overrun.2C_some_messages_lost)
- [如何在一台电脑上安装多个Linux发行版](https://blog.csdn.net/u011507599/article/details/52537846)
- [CentOS 7 分区方案](https://www.cnblogs.com/yogurtwu/p/10717001.html)
- [Linux分区方案、分区建议及手动分区操作步骤](https://zhiliao.h3c.com/theme/details/213685)
- [在同一个硬盘上安装多个 Linux 发行版](https://www.cnblogs.com/youxia/p/linux018.html)
- [CentOS7磁盘管理-分区扩容-使用gparted图形化工具或系统命令](https://www.jianshu.com/p/e5de5f6c3229)
- [VMware 虚拟SCSI、SATA 和 NVMe 存储控制器条件、限制和兼容性](https://blog.csdn.net/allway2/article/details/121842811)
- [VMware创建虚拟机时选择是否将虚拟磁盘拆分](https://www.cnblogs.com/realzhangsan/p/17759698.html)
- [在Linux中，支持哪些文件系统类型？](https://www.cnblogs.com/huangjiabobk/p/18160095)
- [RaspBerry Pi官网](https://www.raspberrypi.com/)
- [树莓派官方系统（raspbian）安装及使用教程](https://blog.csdn.net/Yhen1/article/details/120355150)
- [树莓派开启串口和串口控制台功能](https://lingshunlab.com/book/raspberry-pi/connect-raspberry-pi-terminal-via-serial-port-from-pc)
- [【持续更新】树莓派启动与故障系列集锦](https://blog.csdn.net/junzhu_beautifulpig/article/details/125947358)
- [树莓派 ACT LED 指示灯闪烁模式代表的状态](https://shumeipai.nxez.com/2021/05/26/raspberry-pi-act-led-error-patterns.html)
- [树莓派LED指示灯状态的解释](https://shumeipai.nxez.com/2014/09/30/raspberry-pi-led-status-detail.html)
- [树莓派四种登录方法详解](https://blog.csdn.net/qq_44333320/article/details/125476095)
- [树莓派的串口无法接收但是可以发送](https://wenku.csdn.net/answer/895rwxunh9)
- [关于树莓派3B+串口pi3-miniuart-bt-overlay 与 pi3-miniuart-bt的区别](https://www.cnblogs.com/wuquaaa/p/11922801.html)
- [树莓派用默认账号和密码登录不上怎么办；修改树莓派的密码](https://blog.csdn.net/l_z_y_000/article/details/129017995)