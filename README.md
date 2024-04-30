# QtPropertyManager 动态库修改版

原仓库：

​	https://github.com/qt/qttools



**参见目录**

​	 ./src/shared/qtpropertybrowser

​	[./src/shared/qtpropertybrowser](./src/shared/qtpropertybrowser)



## 修改内容：

1. 令其编译为动态库，并生成 CMake Module 对外调用；

2. 修正属性管理器界面中中文字体显示异常的问题，强行令其字体等于 QApplication 中设置的字体（QApplication::font()）。

   （需要设置 `QApplication::setFont("Microsoft YaHei UI", 9);`）
