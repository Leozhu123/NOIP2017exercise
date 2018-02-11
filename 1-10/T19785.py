#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

for i in range(20, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="T19785", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    m = randint(3,10000) 
    t=randint(3,10000) 
    test_data.input_writeln(m,t)
    for j in range(1, m+1):
        test_data.input_write(randint(10,1000))
    test_data.input_writeln("")
    for j in range(1, m+1):
        test_data.input_write(randint(1,5000))
    print(i)
    test_data.output_gen("T19785.exe")
        
