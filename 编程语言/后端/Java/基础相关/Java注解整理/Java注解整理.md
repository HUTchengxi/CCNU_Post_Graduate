## ע�����

### Java ע������Ϊ Java �����ṩԪ���ݡ���ΪԪ���ݣ�ע�ⲻֱ��Ӱ����Ĵ���ִ�У���Ҳ��һЩ���͵�ע��ʵ���Ͽ���������һĿ��


## Ԫע��

### ����
#### Ԫע�����˼�����ǿ������Ϊע���ע�⣬����������ע���У���������ʹ��ע��ʵ����Ҫ�Ĺ���

### ����
#### @Retention��ע�Ᵽ��ʱ��
1. RetentionPolicy.SOURCE��ע�������Դ���У���������class�ֽ����ļ���
2. RetentionPolicy.CLASS��Ĭ�ϵı������ԣ�ע��������class�ֽ����ļ��У�������ʱ�޷����
3. RetentionPolicy.RUNTIME��ע�����class�ֽ����д��ڣ�����������ʱ����ͨ������õ�
#### @Target��ע�����ö�������
1. ElementType.TYPE���������ڽӿڡ��ࡢö�١�ע��
2. ElementType.FIELD���������������ֶΡ�ö�ٵĳ���
3. ElementType.METHOD���������ڷ���
4. ElementType.PARAMETER���������ڷ�������
5. ElementType.CONSTRUCTOR���������ڹ��캯��
6. ElementType.LOCAL_VARIABLE���������ھֲ�����
7. ElementType.ANNOTATION_TYPE����������ע��
8. ElementType.PACKAGE���������ڰ�
9. ElementType.TYPE_PARAMETER���������ڷ��ͣ��緺�ͷ����������ࡢ���ͽӿڵ�
10. ElementType.TYPE_USE���������ڳ���class������κ�����
#### @Document��ʹ���˸�Ԫע�������˵�ע�����ͨ��javadoc������뵽javadoc�ĵ���ȥ
#### @Inherited���ɼ̳У����ڱ���Ԫע�������˵�ע�⣬�����Aʹ���˸�ע�⣬��ô��A����������Ҳ����Ĭ��ʹ�ø�ע��
#### @Repeatable�����ظ�����ʾ��ע���Ƿ���Ա�ͬһ������ͬʱ���ö�Σ���Ҫ������һ��ע��һ��ʹ��


## ע�������

### ע���еı������ǳ�Ա���������ԣ�������ע������û�з����ģ�ֻ�г�Ա����������������ʹ��ע�������ж�Ӧ�Ĳ���������������ֵע�������ж�Ӧ��������

### ע�ⶨ��ʾ��
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

### ע��ʹ��ʾ��
```
@MyAnnotation("value1")
public class Main1 {

}

@MyAnnotation("value2");
@MyAnnotation("value3")
public class Main2 {

}
```
#### ���������������࣬��һ����ͨ�������ǻ�ȡ����MyAnnotations�ģ��ڶ�������Ի�ȡ������Ϊ�ж��MyAnnotationע������


## ע�� + ����

### ע����ط���API
<table>
    <tr>
        <td>����ֵ</td>
        <td>��������</td>
        <td>˵��</td>
    </tr>
    <tr>
        <td>&lt;A extends Annotation&gt;</td>
        <td>getAnnotation(Class<A> annotationClass)</td>
        <td>��Ԫ���������ָ�����͵�ע�⣬�򷵻���Щע�⣬���򷵻� null</td>
    </tr>
    <tr>
        <td>Annotation[]</td>
        <td>getAnnotations()</td>
        <td>���ش�Ԫ���ϴ��ڵ�����ע�⣬�����Ӹ���̳е�</td>
    </tr>
    <tr>
        <td>boolean</td>
        <td>isAnnotationPresent(Class<? extends Annotation> annotationClass)</td>
        <td>���ָ�����͵�ע������ڴ�Ԫ���ϣ��򷵻� true�����򷵻� false</td>
    </tr>
    <tr>
        <td>Annotation[]</td>
        <td>getDeclaredAnnotations()</td>
        <td>����ֱ�Ӵ����ڴ�Ԫ���ϵ�����ע�⣬ע�⣬�����������ע�⣬�����߿��������޸ķ��ص����飻�ⲻ������������߷��ص���������κ�Ӱ�죬û���򷵻س���Ϊ0������</td>
    </tr>
</table>