## 成员内部类

### 介绍

#### 其定义形式跟定义普通成员变量一样

### 示例

```
public class Test {

    int a = 11;

    public class Inner {

        int a = 22;

        public void test() {

            System.out.println("test inner test method");;
        }
    }

    public static void main(String[] args) {

        Test test = new Test();
        Inner inner = test.new Inner();
        inner.test();
    }

}
```

### 生成文件
![img.png](img.png)

### 注意

#### 外部类是不能直接使用内部类的成员和方法的，即使是public static也不行，必须要通过外部类对象进行相应的访问

#### 如果内部类和其外部类具有相同的属性，内部类默认访问自己的成员属性，要想访问其外部类的属性，可以使用this关键字，如：Test.this.a


## 静态内部类

### 介绍

#### 其定义形式跟定义普通静态变量一样

### 示例

```
public class Test {

    public static class Inner {

        int a = 22;

        public void test() {

            System.out.println("test inner test method");;
        }

        public static void test2() {
            System.out.println("test inner test2 method");
        }
    }

    public static void main(String[] args) {

        Test test = new Test();
        Inner inner = new Inner();
        inner.test();
        Inner.test2();
    }

}
```

### 注意

#### 静态内部类可以直接访问外部类的静态成员

#### 静态内部类不能直接访问外部类的非静态成员，必须通过外部类对象进行访问

#### 如果静态内部类的静态变量和外部类的静态变量同名，则需要通过外部类类名.变量 进行访问外部类的静态变量


## 方法内部类

### 介绍 

#### 定义在外部类的方法中的类，方法内部类只在该方法中可见，作用域为该方法

### 示例

````
public class Test {

    public void innerTest() {

        int a = 1;

        final int b = 2;

        class Inner {

            public void test() {
                System.out.println(a);
                System.out.println(b);
            }
        }

        Inner inner = new Inner();
        inner.test();
    }

    public static void main(String[] args) {


    }

}
````

### 注意

#### 方法内部类不能使用访问修饰符和static关键字

#### 方法内部类中的方法和变量也不能使用static关键字定义



## 匿名内部类

### 介绍

#### 没有名称的类，只能在定义的时候创建，因此作为new声明的一部分

#### 假如要执行的任务需要一个对象，但却不值得创建全新的对象（原因可能 是所需的类过于简单，或是由于他只在一个方法内部使用），匿名类就显得很有用

#### 格式：new <类或接口> <主体>

### 示例

```
public class Test {

    public static void main(String[] args) {

        Inter inter = new Inter() {

            @Override
            public void test() {
                System.out.println("anony inner class test method");
            }
        };

        inter.test();
    }
}

interface Inter {

    public abstract void test();
}
```

### 生成文件
![img_1.png](img_1.png)

### 注意

#### 匿名类的声明是在编译时进行的，实例化在运行时进行；这意味着 for循环中的一个new语句会创建相同匿名类的几个实例，而不是创建几个不同匿名类的一个实例

#### 使用匿名内部类时，我们必须是继承一个类或者实现一个接口，但是两者不可兼得，同时也只能继承一个类或者实现一个接口

#### 匿名内部类不能是抽象的，它必须要实现继承的类或者实现的接口的所有抽象方法

#### 匿名内部类中是不能定义构造函数的

#### 匿名内部类中不能存在任何的静态成员变量和静态方法

#### 当所在的方法的形参需要被内部类里面使用时，该形参必须为final

## 参考文献

### [文献1](https://www.cnblogs.com/hysum/p/7101974.html#_label0)