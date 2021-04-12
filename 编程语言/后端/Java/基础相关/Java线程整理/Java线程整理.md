## �������߳�

### ����
#### ������ָһ���ڴ������е�Ӧ�ó���ÿ�����̶����Լ�������һ���ڴ�ռ䣬�����̿ռ����ռ䣩�����̲��������̶߳��������ڣ�һ�������п�����������߳�
#### ������ϵͳ������Դ����͵��ȵ�һ��������λ
### �߳�
#### �߳���ָ�����е�һ��ִ�����̣�һ�������п������ж���߳�
#### �߳��ǽ��̵�һ��ʵ�壬��CPU���Ⱥͷ��ɵĻ�����λ�����ǱȽ��̸�С���ܶ������еĻ�����λ
#### �߳����Լ��Ķ�ջ�;ֲ����������߳�֮��û�е����ĵ�ַ�ռ䣬һ���̰߳�����������
1.  һ��ָ��ǰ��ִ��ָ���ָ��ָ��
2. һ��ջ
3. һ���Ĵ���ֵ�ļ��ϣ�������һ������������ִ���̵߳Ĵ�����״̬��
4. һ��˽�е�������

## Java�߳�

### ������ʽ
#### ��չjava.lang.Thread��
```
public class Thread implements Runnable {
    ...
}
```
#### ʵ��java.lang.Runnable�ӿ�
```
@FunctionalInterface
public interface Runnable {
    public abstract void run();
}
```

### ʵ������ʽ
#### �����ͨ����չThread�࣬��ֱ��new����
#### �����ͨ��ʵ��Runnable�ӿڣ�����Ҫ������Thread�Ĺ��췽��
```
public Thread(Runnable target) {
    init(null, target, "Thread-" + nextThreadNum(), 0);
}
```

### �߳�������Thread.class.start()
####  �ڵ���start()����֮ǰ���̴߳�����״̬�У���״ָ̬��һ��Thread���󣬵���û��һ���������߳�
#### �ڵ���start()����֮�󣺷�����һϵ�и��ӵ�����
1. �����µ�ִ���̣߳������µĵ���ջ��
2. ���̴߳���״̬ת�Ƶ�������״̬
3. �����̻߳�û���ִ��ʱ����Ŀ��run()����������

### �̼߳���״̬
![img.png](img.png)
#### ��״̬���̶߳����Ѿ���������û�������ϵ���start()����
#### ������״̬�����߳����ʸ����У������ȳ���û�а���ѡ��Ϊ�����߳�ʱ�߳�������״̬
1. ��start()��������ʱ���߳����Ƚ��������״̬
2. ���߳�����֮����ߴ��������ȴ���˯��״̬������Ҳ���ص�������״̬
#### ����״̬���̵߳��ȳ���ӿ����г���ѡ��һ���߳���Ϊ��ǰ�߳�ʱ�߳�������״̬����Ҳ���߳̽�������״̬��Ψһһ�ַ�ʽ
#### �ȴ�/����/˯��״̬�������߳����ʸ�����ʱ��������״̬��ʵ���������״̬���Ϊһ�֣��乲ͬ���ǣ��߳��Ծ��ǻ�ģ����ǵ�ǰû���������С����仰˵�����ǿ����еģ��������ĳ���¼����֣������ܷ��ص�������״̬
#### ����̬�����̵߳�run()�������ʱ����Ϊ����ȥ


### ������IO�������������ֹ�߳�ִ�еķ�ʽ
#### ˯��
1. Thread.sleep(longmillis)��Thread.sleep(long millis, int nanos)
2. ���߳�˯��ʱ������˯��ĳ���ط���������֮ǰ���᷵�ص�������״̬����˯��ʱ�䵽�ڣ��򷵻ص�������״̬
3. ��Ҫע����ǣ�ͨ��sleep�����������ߵ��̲߳����ͷų��е���
#### �ȴ�
1. Thread.yield()����ͣ��ǰ����ִ�е��̶߳��󣬲�ִ�������̣߳�ʵ�����޷���֤yield()�ﵽ�ò�Ŀ�ģ���Ϊ�ò����̻߳��п��ܱ��̵߳��ȳ����ٴ�ѡ��
2. Thread.class.join()����֤��ǰ�߳�ִֹͣ�У�ֱ�����߳���������߳����Ϊֹ��Ȼ���������������߳�û�д���ǰ�̲߳���Ҫֹͣ
```
public class ThreadTest {

    public static void main(String[] args) {

        Thread thread = new Thread() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    System.out.println("��" + i + "��ִ��");
                }
            }
        };

        thread.start();

        for (int i = 0; i < 10; i++) {
            System.out.println("���̵߳�" + i + "��ִ��");
            if(i > 2) {
                try {
                    // ��i>2ʱ����ֹͣmain�߳�ִ�У�֪��thread�߳�ִ����֮����ִ��
                    // ���Կ������̺߳ϲ�
                    thread.join();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

}
```
#### ��Ϊ��Ҫһ�������������������
1. lock���ƣ���synchronized��object.wait() �� object.notify()


### �̵߳�ͬ��
#### synchronizedͬ������
```
public synchronized int getX() {  
    return x++;  
} 

public static synchronized int getX() {
    return x++;
}
```
#### synchronizedͬ�������
```
public int fix(int y) {  
   synchronized (this) {  
       x = x - y;  
   }  
   return x;  
}

public static int fix(int y) {
    synchronized(Xxx.class) {
        x = x - y;;
    }
    return x;
} 
```


### �߳̽���
#### Object���ʵ������
```
void notify()�������ڴ˶���������ϵȴ��ĵ����߳�
void notifyAll()�������ڴ˶���������ϵȴ��������߳�
void wait()�����µ�ǰ�̵߳ĵȴ���ֱ�������̵߳��ô˶����notify()��notifyAll()
```
#### ע��
1. wait�����������ͷų��е������ҽ���˯��״̬
2. notify��notifyAll���������ͷų��е�������ǰ�̼߳���ִ��


### �з���ֵ���߳�
#### 1.5��������ʵ��Callable�ӿڵ��߳̿ɷ���ֵ
```
public class ThreadTest {

    public static void main(String[] args) throws ExecutionException, InterruptedException {

        Callable callable = new Callable() {
            @Override
            public Object call() throws Exception {
                return "welcome";
            }
        };

        ExecutorService executorService = Executors.newSingleThreadExecutor();
        Future future = executorService.submit(callable);
        System.out.println(future.get());
        executorService.shutdown();
    }

}
```


## Java�߳�������

### ��
#### java.util.concurrent.locks.Condition
#### java.util.concurrent.locks.Lock
#### java.util.concurrent.locks.ReadWriteLock

### �ź���
#### Semaphore

### ��������
#### java.util.concurrent.BlockingQueue

### ����ջ
#### java.util.concurrent.BlockingDeque

### ԭ����
#### java.util.concurrent.atomic.AtomicLong
#### java.util.concurrent.atomic.AtomicInteger

### �ϰ���
#### java.util.concurrent.CyclicBarrier



## �ο�����
### [����1](https://blog.csdn.net/kwame211/article/details/78963044)



