#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

for i in range(6, 11): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="sleep", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    n=randint(3,1000000000)
    k=randint(1,n/2)
    test_data.input_writeln(n) # 写入到输入文件里，自动以空格分割并换行
    test_data.output_gen("sleep.exe") 
