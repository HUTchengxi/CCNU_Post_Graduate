## ��Ա�ڲ���

### ����

#### �䶨����ʽ��������ͨ��Ա����һ��

### ʾ��

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

### �����ļ�
![img.png](img.png)

### ע��

#### �ⲿ���ǲ���ֱ��ʹ���ڲ���ĳ�Ա�ͷ����ģ���ʹ��public staticҲ���У�����Ҫͨ���ⲿ����������Ӧ�ķ���

#### ����ڲ�������ⲿ�������ͬ�����ԣ��ڲ���Ĭ�Ϸ����Լ��ĳ�Ա���ԣ�Ҫ��������ⲿ������ԣ�����ʹ��this�ؼ��֣��磺Test.this.a


## ��̬�ڲ���

### ����

#### �䶨����ʽ��������ͨ��̬����һ��

### ʾ��

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

### ע��

#### ��̬�ڲ������ֱ�ӷ����ⲿ��ľ�̬��Ա

#### ��̬�ڲ��಻��ֱ�ӷ����ⲿ��ķǾ�̬��Ա������ͨ���ⲿ�������з���

#### �����̬�ڲ���ľ�̬�������ⲿ��ľ�̬����ͬ��������Ҫͨ���ⲿ������.���� ���з����ⲿ��ľ�̬����


## �����ڲ���

### ���� 

#### �������ⲿ��ķ����е��࣬�����ڲ���ֻ�ڸ÷����пɼ���������Ϊ�÷���

### ʾ��

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

### ע��

#### �����ڲ��಻��ʹ�÷������η���static�ؼ���

#### �����ڲ����еķ����ͱ���Ҳ����ʹ��static�ؼ��ֶ���



## �����ڲ���

### ����

#### û�����Ƶ��ֻ࣬���ڶ����ʱ�򴴽��������Ϊnew������һ����

#### ����Ҫִ�е�������Ҫһ�����󣬵�ȴ��ֵ�ô���ȫ�µĶ���ԭ����� �����������ڼ򵥣�����������ֻ��һ�������ڲ�ʹ�ã�����������Եú�����

#### ��ʽ��new <���ӿ�> <����>

### ʾ��

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

### �����ļ�
![img_1.png](img_1.png)

### ע��

#### ��������������ڱ���ʱ���еģ�ʵ����������ʱ���У�����ζ�� forѭ���е�һ��new���ᴴ����ͬ������ļ���ʵ���������Ǵ���������ͬ�������һ��ʵ��

#### ʹ�������ڲ���ʱ�����Ǳ����Ǽ̳�һ�������ʵ��һ���ӿڣ��������߲��ɼ�ã�ͬʱҲֻ�ܼ̳�һ�������ʵ��һ���ӿ�

#### �����ڲ��಻���ǳ���ģ�������Ҫʵ�ּ̳е������ʵ�ֵĽӿڵ����г��󷽷�

#### �����ڲ������ǲ��ܶ��幹�캯����

#### �����ڲ����в��ܴ����κεľ�̬��Ա�����;�̬����

#### �����ڵķ������β���Ҫ���ڲ�������ʹ��ʱ�����βα���Ϊfinal

## �ο�����

### [����1](https://www.cnblogs.com/hysum/p/7101974.html#_label0)