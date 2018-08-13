print ("Hello World");
print ("你好世界");

a = 100;
b = 100.0;
c = 100.12;
d = "I' am a string";

print (a);
print (b);
print (c);
print (d);

print (d[0]);
print (d[2:5]);
print (d[2:]);
e = d * 2;
f = d + "test";

print (e);
print (f);

# 列表
g = ["abcd", 786, 'abcd', 2.23];
h = g + [2.3];

print (g);
print (g[1:3]);
print (h);

# 元组 只读的列表
i = ("abcd", 786, 'abcd', 2.23);
print (i);

# 字典
j = {};
j['one'] = 1;
j[2] = 2;

k = {'one' : 1, '2' : "two"};

print (j);
print (k);

# 操作符
print ('one' in j);
print (g is not i);

# 决策
if (a  == 100) : 
	print ("Value of expression is 100");
	print ("Same handle");

print ("Diffrent handle");

# while
count = 0
while (count < 9):
   print ('The count is:', count)
   count = count + 1;
print ("End loop");

# for 用于迭代
for var in list(range(5)):
	print (var);

fruits = ['banana', 'apple', 'abc', 'mango'];
for fruit in fruits:        # traversal of List sequence
	if (fruit == 'abc') : break;
	if (fruit == 'apple') : continue;
	print ('Current fruit :', fruit)
	
# 函数
def functionname(count):
   print (count);
   return count + 1;
  
print(functionname(5));

# 可变长度参数函数
def printinfo( arg1, *vartuple ):
   print ("Output is: ");
   print (arg1);
   for var in vartuple:
      print (var);
   return;

# Now you can call printinfo function
printinfo( 10 );
printinfo( 70, 60, 50 );


def functionLoop(count):
    for i in range(count + 1):
        for j in range(count + 1):
            print (i*j, end=' ');
        print();

functionLoop(10);

