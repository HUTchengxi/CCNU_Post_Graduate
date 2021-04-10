## ǰϷ

### Java���ݻ������ࣺ�����������ͺ������������ͣ��ֱ��Ӧ��ֵ���ݺ����ô������ֲ�ͬ�����ݴ��ݷ�ʽ



## ǳ����

### ���ݴ���

#### �������������ǻ����������͵ĳ�Ա������ǳ������ֱ�ӽ���ֵ���ݣ�Ҳ���ǽ�������ֵ����һ�ݸ��µĶ�����Ϊ�����ݲ�ͬ�����ݣ����Զ�����һ������ĸó�Ա����ֵ�����޸ģ�����Ӱ����һ�����󿽱��õ�������

#### �������������������������͵ĳ�Ա����������˵��Ա������ĳ�����顢ĳ����Ķ���ȣ���ôǳ������������ô��ݣ�Ҳ����ֻ�ǽ��ó�Ա����������ֵ���ڴ��ַ������һ�ݸ��µĶ�����Ϊʵ������������ĸó�Ա������ָ��ͬһ��ʵ��������������£���һ���������޸ĸó�Ա������Ӱ�쵽��һ������ĸó�Ա����ֵ

![img_1.png](img_1.png)

### ʵ�ַ�ʽ

#### ͨ���������췽��ʵ��

```
class Person{

    //��������ֵ���ֱ����ֵ���ݺ����ô���
    private Age age;
    private String name;
    
    //�������췽��
    public Person(Person p) {
        this.name=p.name;
        this.age=p.age;
    }
}
```

#### ͨ����дObject���clone()����ʵ�֣�ע�����㣺
1. Object����Ȼ�������������������������ܱ����ģ���protected���Σ������������޷�ֱ��ʹ�ã������Ҫʹ��clone����ʵ��ǳ�������ͱ���Ҫ��д�÷���
2. ʹ��clone�����������ʵ��Cloneable�ӿڣ�������׳��쳣CloneNotSupportedException

```
class Student implements Cloneable{

    private String name;
    private int length;
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public int getLength() {
        return this.length;
    }
    
    public void setLength(int length) {
        this.length=length;
    }
    //����������ַ�����ʽ
    public String toString() {
        return "�����ǣ� "+this.getName()+"�������ǣ� "+this.getLength();
    }
    //��дObject���clone����
    public Object clone() {
        Object obj=null;
        //����Object���clone����������һ��Objectʵ��
        try {
            obj= super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return obj;
    }
}
```



## ���

### ���ݴ���

#### ����������������͵ĳ�Ա�����Ķ���ͼ�����еĶ��󶼿������ڴ�ռ䣻��ǳ����ֻ�Ǵ��ݵ�ַָ���µĶ���û�ж������������ʹ����ڴ�ռ�

#### ����˵���������õĶ�����κβ���������Ӱ�쵽ԭ���������ֵ
![img.png](img.png)

### ʵ�ַ�ʽ

#### ͨ����дObject���clone����ʵ�֣�
1. ���������л�Ϊ�ֽ����к�Ĭ�ϻὫ�ö������������ͼ�������л�����ͨ�������м���������ʵ�����
2. ʵ��Serializable�ӿڼ���ʵ�ֶ�������л��ͷ����л�
3. ���ĳ�����Ա�transient�ؼ������Σ���ô�����Ծ��޷���������

```
/*
 * ����������
 */
class Age implements Cloneable{
    //������ĳ�Ա���������ԣ�
    private int age;
    //���췽��
    public Age(int age) {
        this.age=age;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String toString() {
        return this.age+"";
    }
    
    //��дObject��clone����
    public Object clone() {
        Object obj=null;
        try {
            obj=super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return obj;
    }
}
/*
 * ����ѧ����
 */
class Student implements Cloneable{

    //ѧ����ĳ�Ա���������ԣ�,����һ������Ϊ��Ķ���
    private String name;
    private Age aage;
    private int length;
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public Age getaAge() {
        return this.aage;
    }
    
    public void setaAge(Age age) {
        this.aage=age;
    }
    
    public int getLength() {
        return this.length;
    }
    
    public void setLength(int length) {
        this.length=length;
    }
    
    //��дObject���clone����
    @Override
    public Object clone() {
        Object obj=null;
        //����Object���clone��������ǳ����
        try {
            obj= super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        //����Age���clone�����������
        //�Ƚ�objת��Ϊѧ����ʵ��
        Student stu=(Student)obj;
        //ѧ����ʵ����Age�������ԣ�������clone�������п���
        stu.aage=(Age)stu.getaAge().clone();
        return obj;
    }
}
```

#### ͨ�����л�ʵ��

```
/*
 * ����������
 */
class Age implements Serializable{
    //������ĳ�Ա���������ԣ�
    private int age;
    //���췽��
    public Age(int age) {
        this.age=age;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String toString() {
        return this.age+"";
    }
}
/*
 * ����ѧ����
 */
class Student implements Serializable{

    //ѧ����ĳ�Ա���������ԣ�,����һ������Ϊ��Ķ���
    private String name;
    private Age aage;
    private int length;
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public Age getaAge() {
        return this.aage;
    }
    
    public void setaAge(Age age) {
        this.aage=age;
    }
    
    public int getLength() {
        return this.length;
    }
    
    public void setLength(int length) {
        this.length=length;
    }
    //����������ַ�����ʽ
    public String toString() {
        return "�����ǣ� "+this.getName()+"�� ����Ϊ�� "+this.getaAge().toString()+", �����ǣ� "+this.getLength();
    }
}

public class Test {
    
    public static void main(String[] args) {
        
        Age a=new Age(20);
        Student stu1=new Student("ҡͷҮ��",a,175);
        //ͨ�����л�����ʵ�����
        ByteArrayOutputStream bos=new ByteArrayOutputStream();
        ObjectOutputStream oos=new ObjectOutputStream(bos);
        oos.writeObject(stu1);
        oos.flush();
        ObjectInputStream ois=new ObjectInputStream(new ByteArrayInputStream(bos.toByteArray()));
        Student stu2=(Student)ois.readObject();
        System.out.println(stu1.toString());
        System.out.println(stu2.toString());
        System.out.println();
    }
}
```



## �ο�����

### [����1](https://www.cnblogs.com/shakinghead/p/7651502.html#4762341)