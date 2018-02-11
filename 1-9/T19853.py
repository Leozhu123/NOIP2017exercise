#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

for i in range(11, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="T19272", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    n = randint(3,100000) 
    tree=Graph.tree(n);
    test_data.input_writeln(n)
    for edge in tree.iterate_edges():
        test_data.input_writeln(edge.start,edge.end)
    for j in range(1, n+1): 
        test_data.input_write(randint(1,1000))
    print(i)
    test_data.output_gen("T19853.exe")
        
