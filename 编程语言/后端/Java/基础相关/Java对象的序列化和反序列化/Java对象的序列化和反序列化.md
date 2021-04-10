## ���л��ͷ����л�����

### ����
#### ���л����Ѷ���ת��Ϊ�ֽ����еĹ���
#### �����л������ֽ����л�ԭ�ɶ���Ĺ���

### ��Ҫ��;
#### �Ѷ���ת�����ֽ����У��������뿪�ڴ�ռ䣬���ñ��浽Ӳ���ϣ�ͨ�������һ���ļ���
```
Web�������е�Session���󣬵��� 10���û��������ʣ����п��ܳ���10���Session�����ڴ���ܳԲ�����
����Web�����ͻ��һЩsession�����л���Ӳ���У���Ҫ���ˣ��ٰѱ�����Ӳ���еĶ���ԭ���ڴ���
```
#### �������ϴ��Ͷ�����ֽ�����
```
�����������ڽ���Զ��ͨ��ʱ���˴˿��Է��͸������͵����ݡ������Ǻ������͵����ݣ������Զ��������е���ʽ�������ϴ��͡�
���ͷ���Ҫ�����Java����ת��Ϊ�ֽ����У������������ϴ��ͣ����շ�����Ҫ���ֽ������ٻָ�ΪJava����
```

## JDK����е����л�API��java.io��

### �����������ObjectOutputStream
#### ���ķ���
```
ObjectOutputStream(OutputStream out)
ͨ�����������ObjectOutputStream����

void writeObject(Object obj)
�Բ���ָ����obj����������л����ѵõ����ֽ�����д��һ��Ŀ���������
```
#### ʹ��ʾ��
![img.png](img.png)
![img_1.png](img_1.png)

### ������������ObjectInputStream
#### ���ķ���
```
ObjectInputStream(InputStream in)
ͨ������������ObjectInputStream����

Object readObject()
��һ��Դ�������ж�ȡ�ֽ����У��ٰ����Ƿ����л�Ϊһ�����󣬲����䷵��
```
#### ʹ��ʾ��
![img_2.png](img_2.png)

### Seriliazable�ӿ�

#### ʵ��Serializable�ӿڵ����ṩ���ַ�ʽ�������л�
1. ����Ĭ�����л���ʽ������transatient�ͷ�static�����Խ������л�
2. ��дreadObject��writeObject��ɲ������Ե����л�

#### serialVersionUID�����л��İ汾�ţ�����ʵ��Serializable�ӿڵ��඼����ôһ����ʾ���л��汾��ʶ���ľ�̬��������ʵ�����������Ժ��ļ����е�class��classpath�е�class��Ҳ�����޸Ĺ����class���������ˣ����ڰ�ȫ���ƿ��ǣ������׳��˴��󣬲��Ҿܾ����롣��ô����������������Ҫ�����л������һ���ֶλ��߷����أ�Ӧ����ô�죿�Ǿ����Լ�ȥָ��serialVersionUID���������У����û��ָ��Person���serialVersionUID�ģ���ôjava���������Զ������class����һ��ժҪ�㷨��������ָ���㷨��ֻҪ����ļ���һ���ո񣬵õ���UID�ͻ��Ȼ��ͬ�ģ����Ա�֤����ô�����У���������Ψһ�ġ����ԣ������һ���ֶκ�����û����ָ��serialVersionUID����������Ϊ����������һ��UID����Ȼ��ǰ�汣�����ļ��е��Ǹ�����һ���ˣ����Ǿͳ�����2�����л��汾�Ų�һ�µĴ�����ˣ�ֻҪ�����Լ�ָ����serialVersionUID���Ϳ��������л���ȥ���һ���ֶΣ����߷�����������Ӱ�쵽���ڵĻ�ԭ����ԭ��Ķ�����������ʹ�ã����һ����˷����������Կ����á�����˵serialVersionUID�����л��ͷ����л�֮��˴���ʶ��Ψһ����
```
private final static long serialVersionUID = 12345678L;
```
#### serialVersionUID��ȡֵ��Java����ʱ������������ڲ�ϸ���Զ����ɵġ���������Դ���������޸ģ������±��룬�����ɵ����ļ���serialVersionUID��ȡֵ�п���Ҳ�ᷢ���仯
#### ͨ�����������л�������ʾ����һ��serialVersionUIDֵ

### Externalizable�ӿ�
#### Externalizable�ӿڼ̳��� Serializable�ӿڣ�ʵ��Externalizable�ӿڵ�����ȫ���������������л�����Ϊ
1. writeExternal�������Զ��巴���л�������߼�
2. readExternal�������Զ������л�������߼�
#### Externalizable�ӿڵ�ʵ�ַ�ʽһ��Ҫ��Ĭ�ϵ��޲ι��캯�������û���޲ι��캯���������л��ᱨ��
#### ����ָ��serialVersionUID



## �Զ������л�����

### transient�ؼ���
#### ʹ��transient�ؼ������ε����Բ��ᱻ���л����ļ���

### ���readObject��writeObject����
#### ʵ��Serializable�ӿڲ�ʵ��readObject��writeObject�����ֱ����ڷ����л������л�����ע��������������```private void``
```
public class Book implements Serializable {
    private static final long serialVersionUID = -5438448475454104576L;
 
    private String name;
 
    private String isbn;
 
    private List<String> authors;
 
    private void writeObject(ObjectOutputStream oos) throws IOException {
        oos.writeObject(name);
        oos.writeObject(isbn);
    }
 
    private void readObject(ObjectInputStream ois) throws IOException, ClassNotFoundException {
        name = (String) ois.readObject();
        isbn = (String) ois.readObject();
    }
}
```
#### Java����ObjectOutputStream�������Ƿ���˽�еģ��޷���ֵ��writeObject����������У����ί�и÷������ж������л�
![img_3.png](img_3.png)

### ʵ��Externalizable�ӿ�
#### ʵ��Externalizable�ӿڲ�ʵ��writeExternal��readExternal����
```
public class Book implements Externalizable {
    
    private String name;
 
    private String isbn;
 
    private List<String> authors;
 
    @Override
    public void writeExternal(ObjectOutput out) throws IOException {
        out.writeObject(name);
        out.writeObject(isbn);
    }
 
    @Override
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        name = (String) in.readObject();
        isbn = (String) in.readObject();
    }
}
```