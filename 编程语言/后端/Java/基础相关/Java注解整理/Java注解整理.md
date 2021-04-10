## 注解概述

### Java 注解用于为 Java 代码提供元数据。作为元数据，注解不直接影响你的代码执行，但也有一些类型的注解实际上可以用于这一目的


## 元注解

### 概述
#### 元注解顾名思义我们可以理解为注解的注解，它是作用在注解中，方便我们使用注解实现想要的功能

### 分类
#### @Retention：注解保留时期
1. RetentionPolicy.SOURCE：注解仅存于源码中，不包含在class字节码文件中
2. RetentionPolicy.CLASS：默认的保留策略，注解会存在于class字节码文件中，但运行时无法获得
3. RetentionPolicy.RUNTIME：注解会再class字节码中存在，并且在运行时可以通过反射得到
#### @Target：注解作用对象类型
1. ElementType.TYPE：可作用于接口、类、枚举、注解
2. ElementType.FIELD：可作用于属性字段、枚举的常量
3. ElementType.METHOD：可作用于方法
4. ElementType.PARAMETER：可作用于方法参数
5. ElementType.CONSTRUCTOR：可作用于构造函数
6. ElementType.LOCAL_VARIABLE：可作用于局部变量
7. ElementType.ANNOTATION_TYPE：可作用于注解
8. ElementType.PACKAGE：可作用于包
9. ElementType.TYPE_PARAMETER：可作用于泛型，如泛型方法、泛型类、泛型接口等
10. ElementType.TYPE_USE：可作用于除了class以外的任何类型
#### @Document：使用了该元注解修饰了的注解可以通过javadoc命令加入到javadoc文档中去
#### @Inherited：可继承，对于被该元注解修饰了的注解，如果类A使用了该注解，那么类A的所有子类也都会默认使用该注解
#### @Repeatable：可重复，表示该注解是否可以被同一个对象同时作用多次，需要搭配另一个注解一起使用


## 注解的属性

### 注解中的变量都是成员变量（属性），并且注解中是没有方法的，只有成员变量，变量名就是使用注解括号中对应的参数名，变量返回值注解括号中对应参数类型

### 注解定义示例
```
@Inherited
@Documented
@Retention(RetentionPolicy.SOURCE)
@Target(ElementType.METHOD)
public @interface MyAnnotations {

    MyAnnotation[] value();
}


@Inherited
@Documented
@Repeatable(MyAnnotations.class)
@Retention(RetentionPolicy.SOURCE)
@Target(ElementType.METHOD)
public @interface MyAnnotation {

    String value();
}
```

### 注解使用示例
```
@MyAnnotation("value1")
public class Main1 {

}

@MyAnnotation("value2");
@MyAnnotation("value3")
public class Main2 {

}
```
#### 对于上述这两个类，第一个类通过反射是获取不到MyAnnotations的，第二个类可以获取到，因为有多个MyAnnotation注解修饰


## 注解 + 反射

### 注解相关反射API
<table>
    <tr>
        <td>返回值</td>
        <td>方法名称</td>
        <td>说明</td>
    </tr>
    <tr>
        <td>&lt;A extends Annotation&gt;</td>
        <td>getAnnotation(Class<A> annotationClass)</td>
        <td>该元素如果存在指定类型的注解，则返回这些注解，否则返回 null</td>
    </tr>
    <tr>
        <td>Annotation[]</td>
        <td>getAnnotations()</td>
        <td>返回此元素上存在的所有注解，包括从父类继承的</td>
    </tr>
    <tr>
        <td>boolean</td>
        <td>isAnnotationPresent(Class<? extends Annotation> annotationClass)</td>
        <td>如果指定类型的注解存在于此元素上，则返回 true，否则返回 false</td>
    </tr>
    <tr>
        <td>Annotation[]</td>
        <td>getDeclaredAnnotations()</td>
        <td>返回直接存在于此元素上的所有注解，注意，不包括父类的注解，调用者可以随意修改返回的数组；这不会对其他调用者返回的数组产生任何影响，没有则返回长度为0的数组</td>
    </tr>
</table>