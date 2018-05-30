#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库



for i in range(11, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="T19782", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    n = randint(1,10000) 
    tree=Graph.tree(n);
    test_data.input_writeln(n)
    for edge in tree.iterate_edges():
        test_data.input_writeln(edge.start,edge.end)
    test_data.output_gen("T19782.exe")
        
