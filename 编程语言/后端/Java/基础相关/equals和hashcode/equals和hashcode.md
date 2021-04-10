## equals����

### ��Object���еĶ���
```
// �Ƚ���������������Ƿ���ͬ
public boolean equals(Object obj) {
        return (this == obj);
}
```

### String����д���equals����
```
public boolean equals(Object anObject) {  
    if (this == anObject) {  
        return true;  
    }  
    if (anObject instanceof String) {  
        String anotherString = (String)anObject;  
        int n = count;  
        if (n == anotherString.count) {  
            char v1[] = value;  
            char v2[] = anotherString.value;  
            int i = offset;  
            int j = anotherString.offset;  
            while (n�C != 0) {  
                if (v1[i++] != v2[j++])  
                    return false;  
            }  
            return true;  
        }  
    }  
    return false;  
}  
```

### ��д��Ҫע��

#### ��equals()������overrideʱ��hashCode()ҲҪ��override������һ��hashCode()������ʵ����˵����ȵĶ������ǵ�hash codeһ�����



## hashcode

### hashCode����

#### ���ÿ����һ��Ԫ�ؾͼ��һ�Σ���ô��Ԫ�غܶ�ʱ������ӵ������е�Ԫ�رȽϵĴ����ͷǳ����ˡ�Ҳ����˵����������������Ѿ���1000��Ԫ�أ���ô��1001��Ԫ�ؼ��뼯��ʱ������Ҫ����1000��equals����������Ȼ���󽵵�Ч��
#### ���ǣ�Java�����˹�ϣ���ԭ����ϣ�㷨Ҳ��Ϊɢ���㷨���ǽ��������ض��㷨ֱ��ָ����һ����ַ�ϣ���ѧ�߿��Լ���⣬hashCode����ʵ���Ϸ��صľ��Ƕ���洢�������ַ��ʵ�ʿ��ܲ����ǣ�
#### ����һ����������Ҫ����µ�Ԫ��ʱ���ȵ������Ԫ�ص�hashCode��������һ�����ܶ�λ����Ӧ�÷��õ�����λ���ϣ�������λ����û��Ԫ�أ����Ϳ���ֱ�Ӵ洢�����λ���ϣ������ٽ����καȽ��ˣ�������λ�����Ѿ���Ԫ���ˣ��͵�������equals��������Ԫ�ؽ��бȽϣ���ͬ�Ļ��Ͳ����ˣ�����ͬ��ɢ�������ĵ�ַ�������������һ����ͻ��������⡣����һ��ʵ�ʵ���equals�����Ĵ����ʹ�󽵵��ˣ�����ֻ��Ҫһ����

### ����
#### ��һ��JavaӦ�õ�ִ���ڼ䣬���һ�������ṩ��equals���Ƚϵ���Ϣû�б��޸ĵĻ����ö����ε���hashCode()�������÷�������ʼ����һ����ͬһ��integer
#### ��������������equals(Object)��������ȵģ���ô���ö��߸��Ե�hashCode()�����������ͬһ��integer���
#### ����Ҫ�����equals(java.lang.Object)��������ȵ��������󣬵��ö��߸��Ե�hashCode()�������������ͬ��integer�����Ȼ��������ԱӦ����ʶ�����ڲ�ͬ�Ķ��������ͬ��integer������п��ܻ����hash table������

### Object����hashCode��������
```
public native int hashCode();
```

### String����hashCode��������
```
public int hashCode() {
    int h = hash;
    if (h == 0 && value.length > 0) {
        char val[] = value;
        for (int i = 0; i < value.length; i++) {
            h = 31 * h + val[i];
        }
        hash = h;
    }
    return h;
}
```

## ͨ��HashMap����Ҫ˵��Ϊ��Ҫ��дhashcode��equals����

### HashMap�ڲ��洢��ʽ
#### Hash��洢�ṹ
#### ����ַ�������ͻ

### �Զ�������ΪKeyʱ

#### �Զ�����
```
class Key {
   private Integer id;
   public Integer getId()
   {
       return id; 
   }
   public Key(Integer id)
   {
       this.id = id;  
   }
}

public class Main {
    
    public static void main(String[] args) {
        
        Key k1 = new Key(111);
        Key k2 = new Key(111);
        
        Map map = new HashMap();
        map.put(k1, "ss");
        
        System.out.print(map.get(k2));
    }
}
```

#### �������дhashcode()�����������null��δ�ҵ�����ΪĬ�ϲ��õ���Object.hashCode()�����ص��Ƕ�����ڴ��ַ������������ڴ��ַ�ǲ�һ����
#### ��ʱ��Key����дhashCode����
```
public int hashCode() {
    return id.hashCode();
}
```
#### ���ض�Ӧ��id��hashCodeֵ��k1��k2��ֵ��һ���ģ����Զ�Ӧ��hashCode��ֵҲ����ȵģ��������ս������null��������ΪHashMap�ڲ��������һ������ַ�������ͻ������hashCodeֵ��ͬ������key�����ͨ��equals�����ȽϷ���false����ᶼ���뵽��Ӧ�������У���������Ϊ������ȵ�ֵ
#### ��дequals����
```
public boolean equals(Object object) {
    
    if (o == null || !(o instanceof Key))
    {
        return false; 
    } else{ 
        return this.getId().equals(((Key) o).getId());
    }
}
```

#### �ٴ�ִ��Main�������������ss


## �ο�����
### [����1](https://www.cnblogs.com/lukelook/p/7845188.html)
### [����2](https://zhuanlan.zhihu.com/p/78249480)



























