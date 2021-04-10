## Java�쳣��ṹͼ

![img.png](img.png)

### Error���Լ����������ʵ����������JVM����Ĵ��󡣴����ܱ�����Աͨ�����봦��
### Exception�Լ��������࣬�����������ʱ���͵ĸ��ֲ������������¼������Ա�Java�쳣�������ʹ�ã����쳣����ĺ���



## unchecked-error �� checked-error

### unchecked-error��Error �� RuntimeException �Լ����ǵ����ࡣjavac�ڱ���ʱ��������ʾ�ͷ����������쳣����Ҫ���ڳ�������Щ�쳣
### checked-error������Error �� RuntimeException�������쳣��javacǿ��Ҫ�����ԱΪ�������쳣��Ԥ����������ʹ��try...catch...finally����throws��


## �쳣�׳�

### throw exceptionObject
```throw new Exception("personal exception")```

## �쳣����

### throws exception

```
public class Test() throws Exception {
    method body
}
```

### try-catch��
```
try {

} catch(Exception e) {

}
```


## �쳣����
```
try {
    methodbody
} catch(Exception e) {
    exception deal body
} finally {
    do something
}
```

### finally��

#### ����try-catch-finally�飬����ִ��˳���ǣ�try-finally���쳣ִ��˳���ǣ�try-catch-finally������try��catch�Ƿ�return��finally����ִ�У�����ִ����```System.exit()```����

