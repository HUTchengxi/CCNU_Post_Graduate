![img.png](img.png)
### ����FinalReferenceǿ�������ǰ��ڿɼ��⣬���������඼��public class
![img_1.png](img_1.png)

## ǿ����
### ʹ�����ձ�����ã���```A a = new A()``
### ǿ���õĶ���GC�ǲ���������л��յģ���ʹ�ڴ治�㣬JVMҲ��Ը�׳��쳣ʹ������ֹҲ�������ǿ���ö���


## ������
### �������������õ��������ڣ�ֻ���������õĶ���ӵ�и����ݵ��������ڡ��������������߳�ɨ��������Ͻ���ڴ�����Ĺ����У�һ��������ֻ���������õĶ��󣬲��ܵ�ǰ�ڴ�ռ��㹻��񣬶�����������ڴ�
### ���������ڵڶ���GCʱ����
### �����ÿ��Ժ�һ�����ö��У�ReferenceQueue������ʹ�ã���������������õĶ����������գ�Java������ͻ����������ü��뵽��֮���������ö�����
### ʵ��
```
public class Solution {

    public static void main(String[] args) {

        Object object = new Object();
        WeakReference reference = new WeakReference(object);
        object = null;
        // �ֶ�����gc�����null
//        System.gc();
        System.out.println(reference.get());
        // ���ض����Ƿ��������������
        System.out.println(reference.isEnqueued());
    }

}
```
### ��������Ҫ���ڼ�ض����Ƿ��Ѿ����������������Ϊ�������յ�����




## ������
### ���������õĶ�������ڴ�ռ��㹻����GC���������������ڴ�ռ䲻�㣬��GC������ǽ��л���
### �����ÿ��Ժ�һ�����ö��У�ReferenceQueue������ʹ�ã���������������õĶ����������������գ�Java������ͻ����������ü��뵽��֮���������ö�����
### ʵ��
```
import java.lang.ref.SoftReference;

public class Solution {

    public static void main(String[] args) {

        Object object = new Object();
        SoftReference reference = new SoftReference(object);
        object = null;
        // �ڴ��㹻������»��ȡobject�����ڴ治�������»��ȡnull
        System.out.println(reference.get());
    }

}
```
### SoftReference�����ó�����ʵ��ĳЩ���ݵĻ��湦�ܣ����ڴ��㹻�������ֱ��ͨ��������ȡֵ������ӷ�æ����ʵ��Դ��ѯ���ݣ������ٶȣ����ڴ治��ʱ���Զ�ɾ���ⲿ�ֻ������ݣ�����������Դ��ѯ��Щ����






## ������
### �����ò��������������������ڡ����һ����������������ã���ô���ͺ�û���κ�����һ�������κ�ʱ�򶼿��ܱ���������������
### ��������Ҫ�������ٶ����������������յĻ
### �����ñ�������ö��� ��ReferenceQueue������ʹ�á�������������׼������һ������ʱ��������������������ã��ͻ��ڻ��ն�����ڴ�֮ǰ������������ü��뵽��֮ ���������ö�����
### ������������ԣ������ÿ����������ٶ������������ڻ��յĻ���������ͨ���ж����ö������Ƿ��Ѿ����������������˽ⱻ���õĶ����Ƿ�Ҫ����������
### ʵ��
```
public class Solution {

    public static void main(String[] args) {

        Object object = new Object();
        ReferenceQueue queue = new ReferenceQueue();
        // �����ñ����ReferenceQueue���й���
        PhantomReference reference = new PhantomReference(object, queue);
        object = null;
        // ���null
        System.out.println(reference.get());
        // �������Ƿ��Ѿ����ڴ���ɾ��
        System.out.println(reference.isEnqueued());
    }

}
```

















