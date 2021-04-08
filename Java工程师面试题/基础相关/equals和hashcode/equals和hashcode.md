## equals方法

### 在Object类中的定义
```
// 比较两个对象的引用是否相同
public boolean equals(Object obj) {
        return (this == obj);
}
```

### String类重写后的equals方法
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
            while (n– != 0) {  
                if (v1[i++] != v2[j++])  
                    return false;  
            }  
            return true;  
        }  
    }  
    return false;  
}  
```

### 重写需要注意

#### 当equals()方法被override时，hashCode()也要被override。按照一般hashCode()方法的实现来说，相等的对象，它们的hash code一定相等



## hashcode

### hashCode背景

#### 如果每增加一个元素就检查一次，那么当元素很多时，后添加到集合中的元素比较的次数就非常多了。也就是说，如果集合中现在已经有1000个元素，那么第1001个元素加入集合时，它就要调用1000次equals方法。这显然会大大降低效率
#### 于是，Java采用了哈希表的原理。哈希算法也称为散列算法，是将数据依特定算法直接指定到一个地址上，初学者可以简单理解，hashCode方法实际上返回的就是对象存储的物理地址（实际可能并不是）
#### 这样一来，当集合要添加新的元素时，先调用这个元素的hashCode方法，就一下子能定位到它应该放置的物理位置上；如果这个位置上没有元素，它就可以直接存储在这个位置上，不用再进行任何比较了；如果这个位置上已经有元素了，就调用它的equals方法与新元素进行比较，相同的话就不存了，不相同就散列其它的地址。所以这里存在一个冲突解决的问题。这样一来实际调用equals方法的次数就大大降低了，几乎只需要一两次

### 性质
#### 在一个Java应用的执行期间，如果一个对象提供给equals做比较的信息没有被修改的话，该对象多次调用hashCode()方法，该方法必须始终如一返回同一个integer
#### 如果两个对象根据equals(Object)方法是相等的，那么调用二者各自的hashCode()方法必须产生同一个integer结果
#### 并不要求根据equals(java.lang.Object)方法不相等的两个对象，调用二者各自的hashCode()方法必须产生不同的integer结果。然而，程序员应该意识到对于不同的对象产生不同的integer结果，有可能会提高hash table的性能

### Object类中hashCode方法定义
```
public native int hashCode();
```

### String类中hashCode方法定义
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

## 通过HashMap来简要说明为何要重写hashcode和equals方法

### HashMap内部存储形式
#### Hash表存储结构
#### 链地址法解决冲突

### 自定义类作为Key时

#### 自定义类
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

#### 如果不重写hashcode()，则输出的是null，未找到，因为默认采用的是Object.hashCode()，返回的是对象的内存地址，两个对象的内存地址是不一样的
#### 此时对Key类重写hashCode方法
```
public int hashCode() {
    return id.hashCode();
}
```
#### 返回对应的id的hashCode值，k1和k2的值是一样的，所以对应的hashCode的值也是相等的，但是最终结果还是null，这是因为HashMap内部还会进行一个链地址法解决冲突：对于hashCode值相同的两个key，如果通过equals方法比较返回false，则会都加入到对应的链表中，而不是作为两个相等的值
#### 重写equals方法
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

#### 再次执行Main方法，最终输出ss


## 参考文献
### [文献1](https://www.cnblogs.com/lukelook/p/7845188.html)
### [文献2](https://zhuanlan.zhihu.com/p/78249480)



























