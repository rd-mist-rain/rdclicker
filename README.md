# rdclicker
注："rd"本身并没有什么含义，只是继承自我个人的代码习惯，因为在随机数2中使用的主程序代码名称是"rd",它取自"random"
#### 声明
我们将Qt源代码上传到了QQ群中，若您需要，可以自取
## 内容
### 1.0版本
#### 发行时间
2024年4月14日，此版本正式发行
#### 使用说明
注:每个大版本几乎所有更新都是在上个版本的基础上
##### 1.0.1版本
打开.exe后按下Ctrl键开始自动点击鼠标左键，松开Ctrl键则停止自动点击鼠标左键<br/>
特别说明<br/>
早期版本的打包可能存在一些问题，要将vcruntime140_1d.dll(已上传到文件中,不放心可以自己下同名文件)放置在C:\Windows\System32中以解决缺少文件的问题
##### 1.0.2版本
新增<br/>
1.按下Alt键后在控制台中输入一个整数可以调节每次点击后等待的毫秒数<br/>
2.按下Esc可以关闭程序<br/>
修复<br/>
以改变打包方式的方式降低了文件大小，同时修复了缺少dll导致无法运行的bug
##### 1.0.3版本
新增<br/>
1.按下右Ctrl键可以进行鼠标右键连点<br/>
2.按下小键盘上下键可以进行鼠标滚轮上下滚动<br/>
3.按下空格键是可以暂停程序一段时间，回到控制台按下任意键重新开启程序<br/>
4.使用内联函数增加点击左右键的效率，实测相同延迟下CPS增加0.7~10左右
### 1.1版本
#### 发行时间
2024年4月30日，此版本正式发行
#### 使用说明(1.1版本公有)
1.打开.exe后按下Ctrl键开始自动点击鼠标，松开Ctrl键则停止自动点击鼠标(左、右Ctrl分别对应左右键)<br/>
2.按下小键盘上下键可以进行鼠标滚轮上下滚动<br/>
3.按下Alt键后在控制台中输入一个整数可以调节每次点击后等待的微秒数<br/>
4.按下Esc可以关闭程序<br/>
5.按下空格键可以暂停程序一段时间，回到控制台按下任意键重新开启程序<br/>
##### 1.1.0版本
新增<br/>
6.程序打开时会读取settings.txt文件，文件的每一行分别输入一个十进制键值，读取键值对应原先热键的应用顺序分别是:①Alt键、②上键、③下键、④左Ctrl键、⑤右Ctrl键、⑥Esc键、⑦空格键
#### 设计初衷
由于国内许多连点程序都不是免费使用，故我打算运用C++来写一个属于自己的、开源(或部分开源)、免费的连点器
#### 我们的计划
我们还有另一个程序，即“随机数”，开发此连点器的过程中我们也不会放弃随机数。我打算使用Qt来进行此程序GUI界面的开发，这可能需要较长时间的学习。
#### 联系我们
您可以加入我们的QQ群以联系我们，群号:694771157