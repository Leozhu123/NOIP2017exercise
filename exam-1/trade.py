from cyaron import * # 引入CYaRon的库

for i in range(4, 11): 
    test_data = IO(file_prefix="trade", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    n = randint(150,200)
    m = randint(n,n*n/2-1);
    test_data.input_writeln(n, m) # 写入到输入文件里，自动以空格分割并换行
    graph = Graph.graph(n, m, weight_limit=100000,self_loop=False, repeated_edges=False) # 生成一个n点，m边的随机图，边权限制为5
    test_data.input_writeln(graph) # 自动写入到输入文件里，默认以一行一组u v w的形式输出
    print(i)
    test_data.output_gen("trade.exe") 
