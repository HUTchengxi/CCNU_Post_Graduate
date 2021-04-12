![img.png](img.png)
![img_1.png](img_1.png)

## Set����

### ����
#### ������洢��ͬ��Ԫ�أ����Զ�ȥ�أ��ж��ظ���ͨ�������equals��hashcode����

### HashSet
#### ͨ��hash�㷨���洢Ԫ�أ����кܺõĴ�ȡ�Ͳ�������
#### ���ܱ�֤Ԫ������
#### �̷߳ǰ�ȫ

### SortedSet
#### ��֤Ԫ������
#### TreeSet��ͨ�����ü���Ԫ�ص�compareTo(Object obj)���Ƚ�Ԫ��֮��Ĵ�С������ʹ��TreeSet�洢��Ԫ�ض�Ӧ�����ͱ���ʵ����Comaprable�ӿ�

## EnumSet
#### ����
```
public abstract class EnumSet<E extends Enum<E>> 
    extends AbstractSet<E>
    implements Cloneable, java.io.Serializable
```
#### ��Ҫ���ڴ洢ö����Ԫ�أ����е�Ԫ��Ҳ������ģ�˳���ǰ���ʹ�õ�ö���ඨ���Ԫ��˳��



## List����

### ����
#### Ԫ�ؿ��ظ�
#### ��Ԫ�ص�˳��������ӵ�˳���������

### ArrayList
#### �ڲ�ͨ������ʵ��
#### �������nullֵ

### LinkedList
#### �ڲ�ͨ���������ʽʵ��

### Vector
#### ��ArrayList���ƣ���������Vector���̰߳�ȫ��

### Stack
#### �̳���Vector����һ���Ƚ������ջ
#### �ṩpop��peek��push����


### Iterator�ӿ�
#### ���ϵĵ���������Ҫ�ṩ��������
1. boolean hasNext()���жϼ������Ƿ������һ��Ԫ�ء�����У�hasNext()�������� true
2. Object next()�����ؼ�������һ��Ԫ��
3. void remove()��ɾ����������һ��next�������ص�Ԫ��

### ListIterator�ӿ�
#### ר������List�ĵ��������̳���Iterator�ӿڣ������ṩ����������
2. boolean hasPrevious()���жϼ������Ƿ������һ��Ԫ�ء�����У��÷������� true
2. Object previous()�����ؼ�������һ��Ԫ��
3. void add(Object o)����ָ��λ�ò���һ��Ԫ��



## Map����

### ����
#### ����key->value ��ֵ�Ե���ʽ�洢����

### HashMap
#### �̷߳ǰ�ȫ
#### ����ʹ��null��Ϊkey��value

### HashTable
#### �̰߳�ȫ
#### ������ʹ��null��Ϊkey��value

### LinkedHashMap
#### �̳���HashMap
#### ʹ��˫��������ά��key-value�ԵĴ���(�����˳��һ��)
#### �������ܱ�HashMap�ͣ���������ȫ��Ԫ�ص����ܱ�HashMap��

### Properties
#### �̳���HashTable��Ҳ���̰߳�ȫ����
#### ������һ��key��value����String���͵�Map
#### ��Ҫ���ڲ��������ļ�

### TreeMap
#### SortedMap��ʵ����
#### Key��Ӧ�����ͱ���ʵ��Comparable�ӿڣ�TreeMapͨ������Key�����compareTo������ȷ��key֮���˳��





## �ο�����
### [����1](https://www.cnblogs.com/bingyimeiling/p/10255037.html)









