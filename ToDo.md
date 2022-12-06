# ToDo List
## 0.1.0-beta.1
+ player functions
+ basic functions
+ memory functions
  + memory standard
  + readin function
    + ini
    + login
      + setUser
        + 获取ID和Name写在主程序里
        + 通过ID和Name读取文件定位用户记录 --> playerHis.readmap 实现
    + passward [cancelled]
  + write out function

## 0.1.1-beta.1
+ 修改memoryfile里版本记录错误的问题
+ 添加设置内容的存档 config.memoryfile
  + 语言 [done]
  + password
    + 编写外置加密算法 封装成 dll [done]
    + 导入 dll
    + memory 储存密文然后校验
+ Virtue Command 实现

## 0.2.1-bete.1
+ 主程序参数运作功能
  + 特别判断
  + 读取功能转接
    + 在all目录下的
  + 外置 dll
    + -showmap
    + -up down -left -right
    + -pshtmem (name) (passward)