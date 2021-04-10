## ǰ�� - �����

### ���������
#### ÿ���ڵ�Ҫô�Ǻ�ɫ��Ҫô�Ǻ�ɫ
#### ���ڵ����Ϊ��ɫ
#### ��ɫ�ڵ㲻�������� (��ɫ�ڵ�ĺ��Ӳ���Ϊ��ɫ)
#### ����ÿ���ڵ㣬�Ӹýڵ㵽 null ����β�ˣ����κ�·������������ͬ�����ĺ�ɫ�ڵ�
![img_1.png](img_1.png)

### 1.8ΪʲôҪ��������
#### �������ȱȽϳ��˵�ʱ��ȥ�洢���ݡ���ȡ���ݶ���Ҫ��ͣ��ȥ����ѭ�������Դ�ʱ�ٲ�������ṹ�Ļ�Ч�ʻ������½�������JDK1.8֮�������Ż���������ĳ��ȴ���8��ʱ���������תΪ��������洢���������ƽ�������������һ��ʵ�֣�������ͨ�Ķ��������ָ����죬��Ϊ��ͨ�Ĳ�ѯ��������һ��������Ҳ���ܻ�������ṹ�������������ƽ���������һ�֣�����ͨ������������ɫ�ȱ�������ƽ�⡣

### ��������
#### ��ɫ
1. ���Կ������ĺ��������������3,����˽���ͼһ�Ҳ�ת��
2. ��ɫ������Υ��������4�����ǽ���ͼ���Ҳ�ת��
3. ��ɫ���ֻ��ǲ���������3������4�����ǽ���ͼ���Ҳ�ת�䣬���������������ʣ��ɹ���ɫ
![img_2.png](img_2.png)
![img.png](img.png)
![img_3.png](img_3.png)

#### ��ת
1. ������ͼһ���Լ������ӽڵ��Ϊ�Լ��ĸ��ڵ㣬�Լ����ӽڵ�����ӽڵ������Լ������ӽڵ�
2. ������ͼ�����Լ������ӽڵ��Ϊ�Լ��ĸ��ڵ㣬�Լ����ӽڵ�����ӽڵ������Լ������ӽڵ�
![img_4.png](img_4.png)
![img_5.png](img_5.png)


## HashMap�ṹͼ

### 1.8��ǰ
![img_7.png](img_7.png)

### 1.8
![img_8.png](img_8.png)


## HashMap����
![img_9.png](img_9.png)
### ΪʲôC���±���ˣ� ������ΪԪ�ص���������λ������key��hashֵ������ĳ��Ⱦ�����
### ���ǲ���ÿ��resize���ݶ���Ҫ�����е�key����ȡһ��hash��1.8�Ժ����ˣ�Node������hash��Ա����



## HashMap��modcount������
```
/**
 * The number of times this HashMap has been structurally modified
 * Structural modifications are those that change the number of mappings in
 * the HashMap or otherwise modify its internal structure (e.g.,
 * rehash).  This field is used to make iterators on Collection-views of
 * the HashMap fail-fast.  (See ConcurrentModificationException).
 */
transient int modCount;
```
### Fast-Fail����
#### java.util.HashMap �����̰߳�ȫ�ģ���������ʹ�õ������Ĺ������������߳��޸���map����ô���׳�ConcurrentModificationException���������νfail-fast����
### jdk1.7��ǰmodcountʹ��volatile�ؼ������Σ�1.7�Ƴ���volatile�ؼ��֣���ô����α�֤fast-fail������
#### HashMap.HashIterator
```
private abstract class HashIterator<E> implements Iterator<E> {
        Entry<K,V> next;        // next entry to return
        int expectedModCount;   // For fast-fail
        int index;              // current slot
        Entry<K,V> current;     // current entry

        HashIterator() {
            expectedModCount = modCount;
            if (size > 0) { // advance to first entry
                Entry[] t = table;
                while (index < t.length && (next = t[index++]) == null)
                    ;
            }
        }
        
        final Entry<K,V> nextEntry() {
            if (modCount != expectedModCount)
                throw new ConcurrentModificationException();
            Entry<K,V> e = next;
}
```
#### �ڶ�Key����Value����iterator()������ʱ�򣬻Ὣ��Ӧ��modCount��¼������Ȼ���ڱ��������л���бȽϣ����expectedModCount��modCount����ȣ����׳�```ConcurrentModificationException```


## HashMap.hash()
```
    static final int hash(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }
```
### ΪʲôҪ�޷�������16λ����������㣿key�����hashCodeֱ�������ò�����
![img_10.png](img_10.png)
#### ���ǿ�֪ͨ������(h = key.hashCode()) ^ (h >>> 16)����������԰Ѹ���������Ķ�����������ϵ���������ôΪʲôҪ��ô���أ�
#### ���Ƕ�֪�����¼�������¹�ϣֵ�ں��潫�����hashmap�������λ�ļ��㣬���㹫ʽ��(n - 1) & hash��������ʱ�����λ��16�������λ��������
![img_11.png](img_11.png)
#### ��ϸ�۲����Ĳ��ѷ��֣�������16λ���п��ܻᱻ�����λ���Ķ������������Σ�������ǲ����ղ���λ������㣬��ô�ڼ����λʱ����ʧ��������
#### Ҳ������ܻ�˵����ʹ��ʧ�˸���������ͬhashcodeҲ���Լ������ͬ�Ĳ�λ��������ϸ�뵱������ϣ��ܽӽ�ʱ����ô�������һ������Ϳ��ܵ���һ�ι�ϣ��ײ��������Ҳ�ǽ������������µ�һ������

### ʹ��^�����ԭ��
#### ��������ܸ��õı��������ֵ��������������&������������ֵ����1��£������|������������ֵ����0��£

### Ϊʲô��λ������ʹ��2^n��
#### Ϊ���ù�ϣ��Ľ�����Ӿ��ȣ��������������������16����17�����λ��������
![img_12.png](img_12.png)
#### hashcode����&����ᱻ�����0���Σ����ղ�λ���ֻ��Ϊ0��16����hashmap��˵��һ��������
#### ������Ŀ�Ļ���Ϊ����hashcode���ȷֲ�


## ʹ��ע������

### ������Զ���������Ϊ HashMap �� key ʱ�����ʱ����Ҫ���� hashCode �� equals ����
### HashMap�ĳ�ʼ�����ڲ����һ��Ԫ��ʱ����resize��ɵ�
### ָ��������һ���������ֵ�����ᾭ��tableSizeForת�ɲ�С������ֵ��2��n����
### putԪ��ʱ��Ԫ�ص�λ��ȡ��������ĳ��Ⱥ�key��hashֵ��λ��Ľ��i = (n - 1) & hash



## �ο�����
### [����1](https://blog.csdn.net/ywlmsm1224811/article/details/91388815)
### [����2](https://blog.csdn.net/moneywenxue/article/details/110457302)