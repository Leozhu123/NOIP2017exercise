#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

for i in range(1, 11): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="gongdao", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    m=randint(1,10000)
    n=randint(1,m)
    test_data.input_writeln(m,n)
    for j in range(1,m):
        t=randint(5,1000)
        test_data.input_write(t)
    test_data.output_gen("T19276.exe") 
