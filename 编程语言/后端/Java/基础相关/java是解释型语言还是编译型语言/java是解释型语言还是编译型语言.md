## 解释型语言和编译型语言概念
### 编译型语言
#### 程序在执行之前需要一个专门的编译过程，把程序编译成为机器语言的文件，运行时不需要重新翻译，直接使用编译的结果就行了。程序执行效率高，依赖编译器，跨平台性差些
#### 编译型语言举例：C/C++、Pascal/Object Pascal（Delphi）、Golang
### 解释型语言
#### 程序不需要编译，程序在运行时才翻译成机器语言，每执行一次都要翻译一次。因此效率比较低。在运行程序的时候才翻译，专门有一个解释器去进行翻译，每个语句都是执行的时候才翻译。效率比较低，依赖解释器，跨平台性好
#### 解释型语言举例：C#、PHP、JavaScript、VBScript、Perl、Python、Ruby、MATLAB

## Java：解释型语言
### Java首先由编译器编译成.class类型的文件，这个是java自己类型的文件 然后在通过虚拟机(JVM)从.class文件中读一行解释执行一行，所以他是解释型的语言，正是由于java在JVM上解释运行，对于多种不同的操作系统有不同的JVM，所以 Java才实现了真正意义上的跨平台！
### 个人认为，java是解释型的语言，因为虽然java也需要编译，编译成.class文件，但是并不是机器可以识别的语言，而是字节码，最终还是需要 jvm的解释，才能在各个平台执行，这同时也是java跨平台的原因。所以可是说java即是编译型的，也是解释型，但是假如非要归类的话，从概念上的定义，恐怕java应该归到解释型的语言中

## 参考文献
### [文献1](https://blog.csdn.net/wanghai__/article/details/6967537?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-2.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-2.control)
### [文献2](https://blog.csdn.net/weixin_43876206/article/details/93330986)